#include "JoystickControlNode.hpp"

// Header forlogitech device node (varies by distro)
#include <joy/joy.hpp>

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<LogitechJoystickNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}