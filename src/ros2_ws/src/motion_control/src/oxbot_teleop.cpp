#include "rclcpp/rclcpp.hpp"
#include "OxbotTeleopNode.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<OxbotTeleopNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}