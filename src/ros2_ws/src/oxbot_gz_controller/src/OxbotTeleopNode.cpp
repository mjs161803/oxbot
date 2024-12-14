#include "rclcpp/rclcpp.hpp"
#include "OxbotTeleopNode.hpp"

using std::placeholders::_1;

OxbotTeleopNode::OxbotTeleopNode() : Node("oxbot_teleop")
{
    // Subscriber Definitions
    joy_subscription_ = this->create_subscription<sensor_msgs::msg::Joy>("joy", 10, std::bind(&OxbotTeleopNode::joySubscriptionCB, this, _1));

    // Publisher Definitions
    joycmd_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("motion_cmd", 30);

    // Parameters
    this->declare_parameter("max_linear_velocity_m_sec", 0.5);
    this->declare_parameter("max_angular_velocity_rad_sec", 1.0);

    speed_ = 0.0;
    steer_ = 0.0;
    max_speed_ = get_parameter("max_linear_velocity_m_sec").as_double();
    max_steer_ = get_parameter("max_angular_velocity_rad_sec").as_double();
}

void OxbotTeleopNode::joySubscriptionCB(const sensor_msgs::msg::Joy &msg)
{
    speed_ = static_cast<double>(msg.axes[1])*(max_speed_);
    steer_ = static_cast<double>(msg.axes[2])*(max_steer_)*(-1.0);
    geometry_msgs::msg::Twist teleop_msg;
    teleop_msg.linear.x = speed_;
    teleop_msg.angular.z = steer_;
    joycmd_publisher_->publish(teleop_msg);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<OxbotTeleopNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
