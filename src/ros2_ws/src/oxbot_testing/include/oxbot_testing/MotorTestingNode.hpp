#include "rclcpp/rclcpp.hpp"
#include "oxbot_interfaces/msg/motion_control_output.hpp"
#include "oxbot_config/oxbot_config.hpp"
#include "geometry_msgs/msg/twist.hpp"

class MotorTestingNode: public rclcpp::Node {
    public:
    MotorTestingNode();
    
    private:
    // Members
    rclcpp::Subscription<oxbot_interfaces::msg::MotionControlOutput>::SharedPtr mc_output_subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr test_twist_publisher_;    
    int max_speed;
    int min_speed;
    int max_steer;
    int min_steer;
    int current_speed_cmd;
    int current_steer_cmd;

    // Methods & Callbacks (CBs)
    void MCOutputSubscriptionCB(const oxbot_interfaces::msg::MotionControlOutput &);   
};