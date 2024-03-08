#include "rclcpp/rclcpp.hpp"
#include "MotionControllerNode.hpp"

int main(int argc, char **argv)
{
    auto mc_logger = rclcpp::get_logger("mc_logger");

    rclcpp::init(argc, argv);
    try
    {
        auto node = std::make_shared<MotionControllerNode>();
    }
    catch (std::exception& e)
    {
        RCLCPP_ERROR(mc_logger, "motion_controller.cpp: Exception: %s", e.what());
        return -1;
    }
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}