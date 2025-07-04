#include "rclcpp/rclcpp.hpp"
#include "MotionControllerNode.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MotionControllerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}