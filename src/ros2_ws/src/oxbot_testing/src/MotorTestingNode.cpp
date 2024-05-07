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

    mc_output_subscription_ = this->create_subscription<oxbot_interfaces::msg::MotionControlOutput>("motor_controller_feedback", 1, std::bind(&MotorTestingNode::MCOutputSubscriptionCB, this, _1));
    test_twist_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("motion_cmd", 10);
    int twist_publisher_timer_period_micros    = int(1000000* (1.0 / 4.0)); // 4 Hz rate
    twist_publisher_timer_ =   this->create_wall_timer(std::chrono::microseconds(twist_publisher_timer_period_micros), std::bind(&MotorTestingNode::pubTimerCB, this));
    
    max_speed_=100;
    min_speed_=-100;
    max_steer_=100;
    min_steer_=-100;
    speed_step_size_=5;
    speed_step_direction_=1;
    steer_step_size_=5;
    steer_step_direction_=1;
    current_speed_cmd_=0;
    current_steer_cmd_=0;

    fb_speed_cmd_=0;
    fb_steer_cmd_=0;
    fb_r_rpm_=0;
    fb_l_rpm_=0;
    fb_v_batt_=0;
    fb_temperature_=0;
    fb_led_=0;
    fb_timestamp_ = 0;
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
    {
        /* code */
        current_state_ = increasing_speed;
        current_speed_cmd_ = 0;
        current_steer_cmd_ = 0;
        break;
    }
    case zero_twist:
    {
        prev_state_ = current_state_;
        current_state_ = increasing_speed;
        current_speed_cmd_ += speed_step_direction_*speed_step_size_;
        break;
    }
    case increasing_speed:
    {
        int old_speed = current_speed_cmd_;
        current_speed_cmd_ += speed_step_size_;
        if ((old_speed < 0) & (current_speed_cmd_ == 0))
        {
            current_speed_cmd_ = 0;
            current_state_ = increasing_steer;
        }
        else if (current_speed_cmd_ > max_speed_)
        {
            current_speed_cmd_ = max_speed_;
            current_state_ = decreasing_speed;
        }
        break;
    }
    case decreasing_speed:
    {
        current_speed_cmd_ -= speed_step_size_;
        if (current_speed_cmd_ < min_speed_)
        {
            current_speed_cmd_ = min_speed_;
            current_state_ = increasing_speed;
        }
        break;
    }
    case increasing_steer:
    {
        int old_steer = current_steer_cmd_;
        current_steer_cmd_ += steer_step_size_;
        if ((old_steer < 0)&(current_steer_cmd_==0))
        {
            current_steer_cmd_ = 0;
            current_state_ = increasing_speed;
        }
        else if (current_steer_cmd_ > max_steer_)
        {
            current_steer_cmd_ = max_steer_;
            current_state_ = decreasing_steer;
        }
        break;
    }
    case decreasing_steer:
    {
        current_steer_cmd_ -= steer_step_size_;
        if (current_steer_cmd_ < min_steer_)
        {
            current_steer_cmd_ = min_steer_;
            current_state_ = increasing_steer;
        }
        break;
    }
    default:
    {
        current_state_ = starting;
        break;
    }
    }

    geometry_msgs::msg::Twist new_mc_cmd;
    new_mc_cmd.linear.x = current_speed_cmd_;
    new_mc_cmd.angular.z = current_steer_cmd_;
    test_twist_publisher_->publish(new_mc_cmd);
}