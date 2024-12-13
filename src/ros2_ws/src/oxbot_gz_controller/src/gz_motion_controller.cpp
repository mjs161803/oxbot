#include "rclcpp/rclcpp.hpp"
#include "GZControllerNode.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<GZControllerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}