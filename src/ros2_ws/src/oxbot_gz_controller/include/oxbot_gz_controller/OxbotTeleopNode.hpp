#ifndef OXBOT_TELEOP
#define OXBOT_TELEOP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include <vector>

class OxbotTeleopNode: public rclcpp::Node {
    public:
    OxbotTeleopNode();

    private:
    // Members
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr joycmd_publisher_;    
    
    double speed_;
    double steer_;
    double max_speed_;
    double max_steer_;
    
    // Methods & Callbacks (CBs)
    void joySubscriptionCB(const sensor_msgs::msg::Joy &);  
};

#endif