#include "rclcpp/rclcpp.hpp"

class motors_node : public rclcpp::Node // MODIFY NAME
{
public:
    motors_node() : Node("node_name") // MODIFY NAME
    {
    }

private:
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<motors_node>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
