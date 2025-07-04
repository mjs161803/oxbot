#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "MotionControllerNode.hpp"
#include "FeedbackFrame.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/motion_control_output.hpp"

#define _USE_MATH_DEFINES
#include <math.h> 

using namespace std::chrono_literals;
using std::placeholders::_1;

MotionControllerNode::MotionControllerNode() : Node("motion_controller")
{
    // Parameters
    this->declare_parameter("max_linear_velocity_m_sec", 0.5);
    this->declare_parameter("max_angular_velocity_rad_sec", 1.0);
    this->declare_parameter("front_wheels_serial_path", "/dev/front_wheels");
    this->declare_parameter("rear_wheels_serial_path", "/dev/rear_wheels");
    this->declare_parameter("front_wheels_install_orientation", 1.0);
    this->declare_parameter("rear_wheels_install_orientation", -1.0);
    this->declare_parameter("front_wheel_diameter_cm", 19.0);
    this->declare_parameter("front_wheels_separation_cm", 62.5);
    this->declare_parameter("rear_wheel_diameter_cm", 24.5);
    this->declare_parameter("rear_wheels_separation_cm", 66.0);
    this->declare_parameter("odom_frequency", 10.0);
    this->declare_parameter("serial_polling_frequency", 100.0);

    // Timer Definitions
    int serial_timer_period_micros       = int(1000000.0 * (1.0 / this->get_parameter("serial_polling_frequency").as_double()));
    int output_timer_period_micros    = int(1000000.0 * (1.0 / this->get_parameter("odom_frequency").as_double()));
    serial_feedback_timer_ =   this->create_wall_timer(std::chrono::microseconds(serial_timer_period_micros), std::bind(&MotionControllerNode::feedbackTimerCB, this));
    odom_timer_ =       this->create_wall_timer(std::chrono::microseconds(output_timer_period_micros), std::bind(&MotionControllerNode::publishOdomCB, this));
    
    // Subscriber Definitions
    cmd_subscription_ = this->create_subscription<geometry_msgs::msg::Twist>("motion_cmd", 10, std::bind(&MotionControllerNode::cmdSubscriptionCB, this, _1));

    // Publisher Definitions
    odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("motion_controller_odom", 30);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    
    // Other private members
    t0_ = this->get_clock()->now();
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
    theta_ = 0.0; //radians from x-axis
    x_ = 0.0;
    y_ = 0.0;
    linear_vel_ = 0.0;
    angular_vel_ = 0.0;
    t1_ = this->get_clock()->now();

    // Serial Communicator initializing and Initial Serial Port Handshakes
    try
    {
        serial_comm_ = SerialCommunicator(
                                            this->get_parameter("front_wheels_serial_path").as_string(), 
                                            this->get_parameter("rear_wheels_serial_path").as_string(),
                                            this->get_parameter("front_wheels_install_orientation").as_double(),
                                            this->get_parameter("rear_wheels_install_orientation").as_double(),
                                            this->get_parameter("front_wheel_diameter_cm").as_double(),
                                            this->get_parameter("front_wheels_separation_cm").as_double(),
                                            this->get_parameter("rear_wheel_diameter_cm").as_double(),
                                            this->get_parameter("rear_wheels_separation_cm").as_double()
                                        );
        serial_comm_.initialized = serial_comm_.sc_initializing_handshake_frontwheels(); // && serial_comm_.sc_initializing_handshake_rearwheels();
        if (serial_comm_.initialized == false)
        {
            throw std::runtime_error("Unable to initialize SerialCommunicator");
        }
        serial_comm_.initialized = serial_comm_.sc_initializing_handshake_rearwheels(); // && serial_comm_.sc_initializing_handshake_rearwheels();
        if (serial_comm_.initialized == false)
        {
            throw std::runtime_error("Unable to initialize SerialCommunicator");
        }
    }
    catch (const std::runtime_error& re)
    {
        RCLCPP_ERROR(this->get_logger(), "MotionControllerNode: Runtime Exception: %s", re.what());
    }
    
}

void MotionControllerNode::cmdSubscriptionCB(const geometry_msgs::msg::Twist &msg)
{
    double steer_cmd = msg.angular.z; // in units of rad/sec
    double speed_cmd = msg.linear.x;  // in units of m/sec
    this->serial_comm_.set_front_steer(steer_cmd);
    this->serial_comm_.set_front_speed(speed_cmd);
    this->serial_comm_.set_rear_steer(steer_cmd);
    this->serial_comm_.set_rear_speed(speed_cmd);
}

void MotionControllerNode::publishOdomCB()
{
    tf2::Quaternion q;
    q.setRPY(0,0,theta_);
    current_odom_.header.stamp = t1_;
    current_odom_.twist.twist.linear.x = linear_vel_;
    current_odom_.twist.twist.angular.z = angular_vel_;
    current_odom_.pose.pose.orientation.x = q.x();
    current_odom_.pose.pose.orientation.y = q.y();
    current_odom_.pose.pose.orientation.z = q.z();
    current_odom_.pose.pose.orientation.w = q.w();
    current_odom_.pose.pose.position.x = x_;
    current_odom_.pose.pose.position.y = y_;

    odom_publisher_->publish(current_odom_);

    geometry_msgs::msg::TransformStamped transformStamped;
    transformStamped.header = current_odom_.header;
    transformStamped.child_frame_id = current_odom_.child_frame_id;
    transformStamped.transform.translation.x = x_;
    transformStamped.transform.translation.y = y_;
    transformStamped.transform.translation.z = 0.0;
    transformStamped.transform.rotation.x = current_odom_.pose.pose.orientation.x;
    transformStamped.transform.rotation.y = current_odom_.pose.pose.orientation.y;
    transformStamped.transform.rotation.z = current_odom_.pose.pose.orientation.z;
    transformStamped.transform.rotation.w = current_odom_.pose.pose.orientation.w;

    tf_broadcaster_->sendTransform(transformStamped);
}

void MotionControllerNode::feedbackTimerCB()
{
    auto front_frame = this->serial_comm_.sc_read_front_wheels();
    if (!front_frame.valid)
    {
        RCLCPP_INFO(this->get_logger(), "MotionControllerNode::feedbackTimerCB: Reading front wheels serial port device returned invalid feedback frame.");
        return;
    }
    
    auto rear_frame = this->serial_comm_.sc_read_rear_wheels();
    if (!rear_frame.valid)
    {
        RCLCPP_INFO(this->get_logger(), "MotionControllerNode::feedbackTimerCB: Reading rear wheels serial port device returned invalid feedback frame.");
        return;
    }
    t1_ = this->get_clock()->now();
    auto dt = t1_-t0_;
    double lw_ang_vel = double(front_frame.l_rpm) * M_PI / 30.0;
    double rw_ang_vel = double(front_frame.r_rpm) * M_PI / 30.0;
    linear_vel_ = ((this->get_parameter("front_wheel_diameter_cm").as_double()/100.0) / 2.0) * (rw_ang_vel + lw_ang_vel);
    angular_vel_ = ((this->get_parameter("front_wheel_diameter_cm").as_double()/100.0)/(this->get_parameter("front_wheels_separation_cm").as_double()/100.0))*(rw_ang_vel-lw_ang_vel);
    auto d_s = linear_vel_ * dt.seconds();
    auto d_theta = angular_vel_ * dt.seconds();
    theta_ += d_theta;
    x_ += d_s * cos(theta_);
    y_ += d_s * sin(theta_);

    t0_ = t1_;

    // RCLCPP_INFO_STREAM(get_logger(),
    //                     "\n t0_: " << t0_.seconds() <<
    //                     " t1_: "<< t1_.seconds() <<
    //                     " dt: " << dt.seconds() <<
    //                     " lw_ang_vel: " << lw_ang_vel <<
    //                     " rw_ang_vel: " << rw_ang_vel <<
    //                     " linear_vel: " << linear_vel_ <<
    //                     " angular_vel: " << angular_vel_ <<
    //                     " d_s: " << d_s <<
    //                     " d_theta: " << d_theta <<
    //                     " theta_: " << theta_ <<
    //                     " x_: " << x_ <<
    //                     " y_: " << y_
    //                     );
}