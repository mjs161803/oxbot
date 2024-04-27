#include "rclcpp/rclcpp.hpp"
#include "MotorTestingNode.hpp"

#include "oxbot_interfaces/msg/motion_control_output.hpp"
#include "oxbot_config/oxbot_config.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

MotorTestingNode::MotorTestingNode() : Node("motor_tester")
{
    mc_output_subscription_ = this->create_subscription<oxbot_interfaces::msg::MotionControlOutput>("motor_controller_feedback", 1, std::bind(&MotorTestingNode::MCOutputSubscriptionCB, this, _1));
    test_twist_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("motion_cmd", 10);
    int max_speed_=100;
    int min_speed_=-100;
    int max_steer_=100;
    int min_steer_=-100;
    int current_speed_cmd_=0;
    int current_steer_cmd_=0;

    signed int fb_speed_cmd_=0;
    signed int fb_steer_cmd_=0;
    signed int fb_r_rpm_=0;
    signed int fb_l_rpm_=0;
    signed int fb_v_batt_=0;
    signed int fb_temperature_=0;
    unsigned int fb_led_=0;
    unsigned int fb_timestamp_ = 0;
}

void MotorTestingNode::MCOutputSubscriptionCB(const oxbot_interfaces::msg::MotionControlOutput &msg)
{
    fb_speed_cmd_ = msg.mc_output.end()->speed_or_throttle;
    fb_steer_cmd_ = msg.mc_output.end()->steer_or_brake;
    fb_r_rpm_ = msg.mc_output.end()->right_wheel_rpm;
    fb_l_rpm_ = msg.mc_output.end()->left_wheel_rpm;
    fb_v_batt_ = msg.mc_output.end()->batt_voltage_x100;
    fb_temperature_ = msg.mc_output.end()->temperature;
    fb_timestamp_ = msg.mc_output.end()->timestamp_ns;
}