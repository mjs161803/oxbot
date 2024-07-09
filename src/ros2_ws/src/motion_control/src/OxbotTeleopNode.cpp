#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "OxbotTeleopNode.hpp"
#include "oxbot_config/oxbot_config.hpp"

using std::placeholders::_1;

OxbotTeleopNode::OxbotTeleopNode() : Node("oxbot_teleop")
{
    // Subscriber Definitions
    joy_subscription_ = this->create_subscription<sensor_msgs::msg::Joy>("joy", 10, std::bind(&OxbotTeleopNode::joySubscriptionCB, this, _1));

    // Publisher Definitions
    joycmd_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("motion_cmd", 30);
}

void OxbotTeleopNode::joySubscriptionCB(const sensor_msgs::msg::Joy &msg)
{
    geometry_msgs::msg::Twist teleop_msg;
    // convert joystick msg to Twist msg and publish for motion_controller node

    joycmd_publisher_->publish(teleop_msg);
}