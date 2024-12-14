#ifndef GZ_MOTION_CONTROLLER
#define GZ_MOTION_CONTROLLER 

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include <vector>
#include <eigen3/Eigen/Geometry>

class GZControllerNode: public rclcpp::Node {
    public:
    GZControllerNode();

    private:
    // Members
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_subscription_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;    
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr wheels_publisher_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_sub_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    nav_msgs::msg::Odometry current_odom_;
    geometry_msgs::msg::TransformStamped current_transform_;
    double front_wheels_separation_;
    double front_wheel_diameter_;
    double rear_wheels_separation_;
    double rear_wheel_diameter_;
    double theta_;
    double x_;
    double y_;
    double front_right_wheel_prev_pos_;
    double rear_right_wheel_prev_pos_;
    double front_left_wheel_prev_pos_;
    double rear_left_wheel_prev_pos_;
    double linear_vel_;
    double angular_vel_;
    rclcpp::Time prev_time_;
    Eigen::Matrix2d front_speed_conversion_;
    Eigen::Matrix2d rear_speed_conversion_;

    // Methods & Callbacks (CBs)
    void jointSubscriptionCB(const sensor_msgs::msg::JointState &msg);
    void cmdSubscriptionCB(const geometry_msgs::msg::Twist &);     
};

#endif 