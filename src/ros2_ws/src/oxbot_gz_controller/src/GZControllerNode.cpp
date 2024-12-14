
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "GZControllerNode.hpp"
#include <eigen3/Eigen/Geometry>

#define _USE_MATH_DEFINES
#include <math.h> 

using namespace std::chrono_literals;
using std::placeholders::_1;

GZControllerNode::GZControllerNode() : Node("gz_motion_controller")
{
    // Parameters
    this->declare_parameter("max_linear_velocity_m_sec", 0.5);
    this->declare_parameter("max_angular_velocity_rad_sec", 1.0);
    this->declare_parameter("front_wheel_diameter_cm", 19.0);
    this->declare_parameter("front_wheels_separation_cm", 62.5);
    this->declare_parameter("rear_wheel_diameter_cm", 24.5);
    this->declare_parameter("rear_wheels_separation_cm", 66.0);
    
    // Subscriber Definitions
    cmd_subscription_ = this->create_subscription<geometry_msgs::msg::Twist>("motion_cmd", 10, std::bind(&GZControllerNode::cmdSubscriptionCB, this, _1));
    joint_sub_ = create_subscription<sensor_msgs::msg::JointState>("/joint_states", 10, std::bind(&GZControllerNode::jointSubscriptionCB, this, _1));

    // Publisher Definitions
    wheels_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("simple_velocity_controller/commands", 30);
    odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("gz_controller_odom", 30);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    // Other private members
    current_transform_.header.frame_id = "odom";
    current_transform_.child_frame_id = "base_footprint";
    current_odom_.header.frame_id = "odom";
    current_odom_.header.stamp = this->get_clock()->now();
    current_odom_.child_frame_id = "base_footprint";
    current_odom_.pose.pose.position.x = 0.0;
    current_odom_.pose.pose.position.y = 0.0;
    current_odom_.pose.pose.position.z = 0.0;
    current_odom_.pose.pose.orientation.x = 0.0;
    current_odom_.pose.pose.orientation.y = 0.0;
    current_odom_.pose.pose.orientation.z = 0.0;
    current_odom_.pose.pose.orientation.w = 1.0;
    current_odom_.twist.twist.linear.x = 0.0;
    current_odom_.twist.twist.linear.y = 0.0;
    current_odom_.twist.twist.linear.z = 0.0;
    current_odom_.twist.twist.angular.x = 0.0;
    current_odom_.twist.twist.angular.y = 0.0;
    current_odom_.twist.twist.angular.z = 0.0;
    front_wheel_diameter_ = get_parameter("front_wheel_diameter_cm").as_double();
    rear_wheel_diameter_ = get_parameter("rear_wheel_diameter_cm").as_double();
    front_wheels_separation_ = get_parameter("front_wheels_separation_cm").as_double();
    rear_wheels_separation_ = get_parameter("rear_wheels_separation_cm").as_double();
    front_speed_conversion_ << (front_wheel_diameter_/200.0)/2.0, (front_wheel_diameter_/200.0)/2.0, (front_wheel_diameter_/2.0)/(front_wheels_separation_), -(front_wheel_diameter_/2.0)/(front_wheels_separation_);
    rear_speed_conversion_ << (rear_wheel_diameter_/200.0)/2.0, (rear_wheel_diameter_/200.0)/2.0, (rear_wheel_diameter_/2.0)/(rear_wheels_separation_), -(rear_wheel_diameter_/2.0)/(rear_wheels_separation_);
    theta_ = 0.0; //radians from x-axis
    x_ = 0.0;
    y_ = 0.0;
    linear_vel_ = 0.0;
    angular_vel_ = 0.0;
    front_right_wheel_prev_pos_ = 0.0;
    front_left_wheel_prev_pos_ = 0.0;
    rear_right_wheel_prev_pos_ = 0.0;
    rear_left_wheel_prev_pos_ = 0.0;
    prev_time_ = get_clock()->now();
           
}

void GZControllerNode::cmdSubscriptionCB(const geometry_msgs::msg::Twist &msg)
{
    Eigen::Vector2d robot_speed(msg.linear.x, msg.angular.z);
    Eigen::Vector2d front_wheel_speed = front_speed_conversion_.inverse() * robot_speed;
    Eigen::Vector2d rear_wheel_speed = rear_speed_conversion_.inverse() * robot_speed;
    std_msgs::msg::Float64MultiArray wheel_speed_msg;
    wheel_speed_msg.data.push_back(front_wheel_speed.coeff(1));
    wheel_speed_msg.data.push_back(front_wheel_speed.coeff(0));
    wheel_speed_msg.data.push_back(rear_wheel_speed.coeff(1));
    wheel_speed_msg.data.push_back(rear_wheel_speed.coeff(0));
    wheels_publisher_->publish(wheel_speed_msg);
}

void GZControllerNode::jointSubscriptionCB(const sensor_msgs::msg::JointState &state)
{
    // Implements the inverse differential kinematic model
    // Given the position of the wheels, calculates their velocities
    // then calculates the velocity of the robot wrt the robot frame
    // and then converts it in the global frame and publishes the TF
    double dp_front_left = state.position.at(1) - front_left_wheel_prev_pos_;
    double dp_front_right = state.position.at(0) - front_right_wheel_prev_pos_;
    rclcpp::Time msg_time = state.header.stamp;
    rclcpp::Duration dt = msg_time - prev_time_;

    // Actualize the prev pose for the next itheration
    front_left_wheel_prev_pos_ = state.position.at(1);
    front_right_wheel_prev_pos_ = state.position.at(0);
    rear_left_wheel_prev_pos_ = state.position.at(3);
    rear_right_wheel_prev_pos_ = state.position.at(2);
    prev_time_ = state.header.stamp;

    // Calculate the rotational speed of each wheel
    double fi_front_left = dp_front_left / dt.seconds();
    double fi_front_right = dp_front_right / dt.seconds();

    // Calculate the linear and angular velocity
    double linear = ((front_wheel_diameter_/2.0) * 0.01 * fi_front_right + (front_wheel_diameter_/2.0) * 0.01 * fi_front_left) / 2.0;
    double angular = ((front_wheel_diameter_/2.0) * 0.01 * fi_front_right - (front_wheel_diameter_/2.0) * 0.01 * fi_front_left) / (front_wheels_separation_*0.01);

    // Calculate the position increment
    double d_s = ((front_wheel_diameter_/2.0)*.01 * dp_front_right + (front_wheel_diameter_/2.0)*0.01 * dp_front_left) / 2.0;
    double d_theta = ((front_wheel_diameter_/2.0)*0.01 * dp_front_right - (front_wheel_diameter_/2.0)*0.01 * dp_front_left) / (front_wheels_separation_*0.01);
    theta_ += d_theta;
    x_ += d_s * cos(theta_);
    y_ += d_s * sin(theta_);

    // Compose and publish the odom message
    tf2::Quaternion q;
    q.setRPY(0, 0, theta_);
    current_odom_.header.stamp = get_clock()->now();
    current_odom_.pose.pose.position.x = x_;
    current_odom_.pose.pose.position.y = y_;
    current_odom_.pose.pose.orientation.x = q.getX();
    current_odom_.pose.pose.orientation.y = q.getY();
    current_odom_.pose.pose.orientation.z = q.getZ();
    current_odom_.pose.pose.orientation.w = q.getW();
    current_odom_.twist.twist.linear.x = linear;
    current_odom_.twist.twist.angular.z = angular;
    odom_publisher_->publish(current_odom_);

    // TF
    current_transform_.transform.translation.x = x_;
    current_transform_.transform.translation.y = y_;
    current_transform_.transform.rotation.x = q.getX();
    current_transform_.transform.rotation.y = q.getY();
    current_transform_.transform.rotation.z = q.getZ();
    current_transform_.transform.rotation.w = q.getW();
    current_transform_.header.stamp = get_clock()->now();
    tf_broadcaster_->sendTransform(current_transform_);
}