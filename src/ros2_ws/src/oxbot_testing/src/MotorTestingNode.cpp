#include "rclcpp/rclcpp.hpp"
#include "MotorTestingNode.hpp"

#include "oxbot_interfaces/msg/motion_control_output.hpp"
#include "oxbot_config/oxbot_config.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

MotorTestingNode::MotorTestingNode() : Node("motor_tester")
{
    current_state_ = starting;
    prev_state_ = starting;
    next_state_ = starting;

    mc_output_subscription_ = this->create_subscription<oxbot_interfaces::msg::MotionControlOutput>("motor_controller_feedback", 1, std::bind(&MotorTestingNode::MCOutputSubscriptionCB, this, _1));
    test_twist_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("motion_cmd", 10);
    int twist_publisher_timer_period_micros    = int(1000000* (1.0 / 0.2)); // 0.2 Hz... i.e. - every 5 seconds.
    twist_publisher_timer_ =   this->create_wall_timer(std::chrono::microseconds(twist_publisher_timer_period_micros), std::bind(&MotorTestingNode::pubTimerCB, this));
    
    int max_speed_=100;
    int min_speed_=-100;
    int max_steer_=100;
    int min_steer_=-100;
    int step_size_=5;
    int step_direction_=1;
    int current_speed_cmd_=0;
    int current_steer_cmd_=0;
    bool speed_testing = true;
    bool steer_testing = false;

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

void MotorTestingNode::pubTimerCB(void)
{
    switch (current_state_)
    {
    case starting:
        /* code */
        prev_state_ = current_state_;
        current_state_ = increasing_speed;
        break;
    case zero_twist:
        if (prev_state_ == increasing_speed | prev_state_ == decreasing_speed)
        {
            prev_state_ = current_state_;
            current_state_ = increasing_steer;
        }
        else if (prev_state_ == increasing_steer | prev_state_ == decreasing_steer)
        {
            prev_state_ = current_state_;
            current_state_ = increasing_speed;
        }
        break;
    case increasing_speed:
        current_speed_cmd_ += speed_step_size_*speed_step_direction_;
        if (current_speed_cmd_ > max_speed_)
        {
            current_speed_cmd_ = max_speed_;
            speed_step_direction_ *= -1;
            prev_state_ = current_state_;
            current_state_ = decreasing_speed;
        }
        else
        {
            prev_state_ = current_state_;
            current_state_ = increasing_speed;
        }
        break;
    case decreasing_speed:
        current_speed_cmd_ += speed_step_size_*speed_step_direction_;
        if (current_speed_cmd_ < min_speed_)
        {
            current_speed_cmd_ = min_speed_;
            speed_step_direction_ *= -1;
            prev_state_ = current_state_;
            current_state_ = returning_to_zero;
        }
        else
        {
            prev_state_ = current_state_;
            current_state_ = decreasing_speed;
        }        
        break;
    case returning_to_zero:
        //prev_state_ = current_state_;
        break;
    case increasing_steer:
        //prev_state_ = current_state_;
        break;
    case decreasing_steer:
        //prev_state_ = current_state_;
        break;
    default:
        //prev_state_ = current_state_;
        break;
    }

    geometry_msgs::msg::Twist new_mc_cmd;
    new_mc_cmd.linear.x = current_speed_cmd_;
    new_mc_cmd.angular.z = current_steer_cmd_;
}