#include "rclcpp/rclcpp.hpp"
#include "OxbotTeleopNode.hpp"
#include "oxbot_config/oxbot_config.hpp"

using std::placeholders::_1;

#define MAX_RPM 100.0

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
    teleop_msg.linear.x = msg.axes[1] * MAX_RPM;
    teleop_msg.angular.z = msg.axes[2] * MAX_RPM;

    joycmd_publisher_->publish(teleop_msg);
}