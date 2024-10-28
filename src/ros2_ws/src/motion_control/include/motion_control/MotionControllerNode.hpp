#ifndef MOTION_CONTROLLER
#define MOTION_CONTROLLER 

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/motion_control_output.hpp"
#include "SerialCommunicator.hpp"
#include "FeedbackFrame.hpp"
#include "oxbot_config/oxbot_config.hpp"
#include <vector>

class MotionControllerNode: public rclcpp::Node {
    public:
    MotionControllerNode();

    private:
    // Members
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_subscription_;
    rclcpp::TimerBase::SharedPtr serial_feedback_timer_;
    rclcpp::TimerBase::SharedPtr odom_timer_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;    
    SerialCommunicator serial_comm_;
    nav_msgs::msg::Odometry current_odom_;

    // Methods & Callbacks (CBs)
    void cmdSubscriptionCB(const geometry_msgs::msg::Twist &);     
    void feedbackTimerCB();
    void publishOdomCB();
};

#endif 