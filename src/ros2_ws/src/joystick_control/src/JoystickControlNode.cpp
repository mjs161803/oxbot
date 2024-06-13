
#include "logitech_joystick_node.hpp"

// Header forlogitech device node (varies by distro)
#include <joy/joy.hpp>

LogitechJoystickNode::LogitechJoystickNode() : Node("logitech_joystick_node") {
  // Create a subscription to the joystick topic
  joy_sub_ = create_subscription<sensor_msgs::msg::Joy>(
      "/joy", 10, std::bind(&LogitechJoystickNode::joyCallback, this, _1));

  // Create a publisher for Twist messages
  twist_pub_ = create_publisher<geometry_msgs::msg::Twist>("twist", 10);
}

void LogitechJoystickNode::joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg) {
  // Check for valid axes (modify based on your joystick configuration)
  if (msg->axes.size() < 2 || msg->buttons.size() < 2) {
    RCLCPP_WARN(this->get_logger(), "Invalid joystick data. Check axis/button count");
    return;
  }

  // Extract linear and angular velocities from axes (adjust based on your joystick)
  geometry_msgs::msg::Twist twist;
  twist.linear.x = msg->axes[1];  // Forward/backward axis (usually Y axis)
  twist.angular.z = msg->axes[0];  // Turning axis (usually X axis)

  // Handle button presses for additional control (optional)
  if (msg->buttons[0]) {
    // Implement custom logic for button press (e.g. emergency stop)
    twist.linear.x = 0.0;
    twist.angular.z = 0.0;
  }

  // Publish the Twist message
  twist_pub_->publish(twist);
}
