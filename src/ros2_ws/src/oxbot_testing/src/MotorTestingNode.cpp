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

    mc_output_subscription_ = this->create_subscription<oxbot_interfaces::msg::MotionControlOutput>("motor_controller_output", 1, std::bind(&MotorTestingNode::MCOutputSubscriptionCB, this, _1));
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

    fb_front_speed_cmd_=0;
    fb_front_steer_cmd_=0;
    fb_front_r_rpm_=0;
    fb_front_l_rpm_=0;
    fb_front_v_batt_=0;
    fb_front_temperature_=0;
    fb_front_led_=0;
    fb_front_timestamp_ = 0;
    fb_rear_speed_cmd_=0;
    fb_rear_steer_cmd_=0;
    fb_rear_r_rpm_=0;
    fb_rear_l_rpm_=0;
    fb_rear_v_batt_=0;
    fb_rear_temperature_=0;
    fb_rear_led_=0;
    fb_rear_timestamp_ = 0;
}

void MotorTestingNode::MCOutputSubscriptionCB(const oxbot_interfaces::msg::MotionControlOutput &msg)
{
    for (auto it = msg.mc_output.rbegin(); it != msg.mc_output.rend(); ++it)
    {
        if (it->front_or_back == "front")
        {
            fb_front_speed_cmd_ = it->speed_or_throttle;
            fb_front_steer_cmd_ = it->steer_or_brake;
            fb_front_r_rpm_ = it->right_wheel_rpm;
            fb_front_l_rpm_ = it->left_wheel_rpm;
            fb_front_v_batt_ = it->batt_voltage_x100;
            fb_front_temperature_ = it->temperature;
            fb_front_timestamp_ = it->timestamp_ns;
        }
    }
    for (auto it = msg.mc_output.rbegin(); it != msg.mc_output.rend(); ++it)
    {
        if (it->front_or_back == "back")
        {
            fb_rear_speed_cmd_ = it->speed_or_throttle;
            fb_rear_steer_cmd_ = it->steer_or_brake;
            fb_rear_r_rpm_ = it->right_wheel_rpm;
            fb_rear_l_rpm_ = it->left_wheel_rpm;
            fb_rear_v_batt_ = it->batt_voltage_x100;
            fb_rear_temperature_ = it->temperature;
            fb_rear_timestamp_ = it->timestamp_ns;
        }
    }


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
    printMCOutput();
}

void MotorTestingNode::printMCOutput()
{
    RCLCPP_INFO(this->get_logger(), "Front Wheels Feedback: %d / %d / %d / %d / %d / %d / %d / %d", fb_front_speed_cmd_, fb_front_steer_cmd_, fb_front_r_rpm_, fb_front_l_rpm_, fb_front_v_batt_, fb_front_temperature_, fb_front_led_, fb_front_timestamp_);
    RCLCPP_INFO(this->get_logger(), "Rear Wheels Feedback: %d / %d / %d / %d / %d / %d / %d / %d", fb_rear_speed_cmd_, fb_rear_steer_cmd_, fb_rear_r_rpm_, fb_rear_l_rpm_, fb_rear_v_batt_, fb_rear_temperature_, fb_rear_led_, fb_rear_timestamp_);
}