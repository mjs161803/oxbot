#include "rclcpp/rclcpp.hpp"
#include "OxbotTeleopNode.hpp"
#include "oxbot_config/oxbot_config.hpp"

using std::placeholders::_1;

#define MAX_RPM 100.0

OxbotTeleopNode::OxbotTeleopNode() : Node("oxbot_teleop")
{
    // Timer Definitions    
    output_timer_ = this->create_wall_timer(std::chrono::microseconds(33333), std::bind(&OxbotTeleopNode::outputTimerCB, this));
        
    // Subscriber Definitions
    joy_subscription_ = this->create_subscription<sensor_msgs::msg::Joy>("joy", 10, std::bind(&OxbotTeleopNode::joySubscriptionCB, this, _1));

    // Publisher Definitions
    joycmd_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("motion_cmd", 30);

    speed_ = 0.0;
    steer_ = 0.0;
}

void OxbotTeleopNode::joySubscriptionCB(const sensor_msgs::msg::Joy &msg)
{
    speed_ = msg.axes[1]*MC_MAX_SPEED_CM_PER_SEC;
    steer_ = msg.axes[2]*MC_MAX_OMEGA_RAD_PER_SEC;
}

void OxbotTeleopNode::outputTimerCB() 
{
    geometry_msgs::msg::Twist teleop_msg;
    // convert joystick msg to Twist msg and publish for motion_controller node
    teleop_msg.linear.x = static_cast<double>(speed_);
    teleop_msg.angular.z = static_cast<double>(steer_);

    joycmd_publisher_->publish(teleop_msg);
}