#include <chrono>
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
    int max_speed_;
    int min_speed_;
    int max_steer_;
    int min_steer_;
    int current_speed_cmd_;
    int current_steer_cmd_;
    signed int fb_speed_cmd_;
    signed int fb_steer_cmd_;
    signed int fb_r_rpm_;
    signed int fb_l_rpm_;
    signed int fb_v_batt_;
    signed int fb_temperature_;
    unsigned int fb_led_;
    unsigned int fb_timestamp_;

    // Methods & Callbacks (CBs)
    void MCOutputSubscriptionCB(const oxbot_interfaces::msg::MotionControlOutput &);   
};