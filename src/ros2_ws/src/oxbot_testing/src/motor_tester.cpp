#include "rclcpp/rclcpp.hpp"
#include "MotorTestingNode.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MotorTestingNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}