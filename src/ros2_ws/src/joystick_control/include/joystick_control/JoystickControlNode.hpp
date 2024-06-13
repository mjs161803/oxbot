#ifndef LOGITECH_JOYSTICK_NODE_HPP
#define LOGITECH_JOYSTICK_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <geometry_msgs/msg/twist.hpp>

class LogitechJoystickNode : public rclcpp::Node {
public:
  LogitechJoystickNode();

private:
  // Function prototypes for callback and other functionalities (if needed)
  void joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg);

  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr twist_pub_;
};

#endif // LOGITECH_JOYSTICK_NODE_HPP