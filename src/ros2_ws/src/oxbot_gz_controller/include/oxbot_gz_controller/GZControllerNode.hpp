#ifndef GZ_MOTION_CONTROLLER
#define GZ_MOTION_CONTROLLER 

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include <vector>

class GZControllerNode: public rclcpp::Node {
    public:
    GZControllerNode();

    private:
    // Members
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_subscription_;
    rclcpp::TimerBase::SharedPtr odom_timer_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;    
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    nav_msgs::msg::Odometry current_odom_;
    double theta_;
    double x_;
    double y_;
    double linear_vel_;
    double angular_vel_;
    rclcpp::Time t0_;
    rclcpp::Time t1_;

    // Methods & Callbacks (CBs)
    void jointCallback(const sensor_msgs::msg::JointState &msg);
    void cmdSubscriptionCB(const geometry_msgs::msg::Twist &);     
    void publishOdomCB();
};

#endif 