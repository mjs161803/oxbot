#include "rclcpp/rclcpp.hpp"
#include "OxbotTeleopNode.hpp"

using std::placeholders::_1;

OxbotTeleopNode::OxbotTeleopNode() : Node("oxbot_teleop")
{
    // Timer Definitions    
    output_timer_ = this->create_wall_timer(std::chrono::microseconds(33333), std::bind(&OxbotTeleopNode::outputTimerCB, this));
        
    // Subscriber Definitions
    joy_subscription_ = this->create_subscription<sensor_msgs::msg::Joy>("joy", 10, std::bind(&OxbotTeleopNode::joySubscriptionCB, this, _1));

    // Publisher Definitions
    joycmd_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("motion_cmd", 30);

    // Parameters
    this->declare_parameter("max_linear_velocity_m_sec", 0.5);
    this->declare_parameter("max_angular_velocity_rad_sec", 1.0);

    speed_ = 0.0;
    steer_ = 0.0;
}

void OxbotTeleopNode::joySubscriptionCB(const sensor_msgs::msg::Joy &msg)
{
    speed_ = static_cast<double>(msg.axes[1])*(this->get_parameter("max_linear_velocity_m_sec").as_double());
    steer_ = static_cast<double>(msg.axes[2])*(this->get_parameter("max_angular_velocity_rad_sec").as_double());
}

void OxbotTeleopNode::outputTimerCB() 
{
    geometry_msgs::msg::Twist teleop_msg;
    // convert joystick msg to Twist msg and publish for motion_controller node
    teleop_msg.linear.x = speed_;
    teleop_msg.angular.z = steer_;

    joycmd_publisher_->publish(teleop_msg);
}