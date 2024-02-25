#include "rclcpp/rclcpp.hpp"
#include "./ros2node_motion_controller.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"

MotionControllerNode::MotionControllerNode() : Node("motion_controller")
    {
        feedback_publisher_ = this->create_publisher<oxbot_interfaces::msg::HoverboardFeedback>("motor_controller_feedback", 30);
        feedback_timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&MotionControllerNode::publishFeedback, this));
    }

void MotionControllerNode::publishFeedback()
    {
        auto msg = oxbot_interfaces::msg::HoverboardFeedback();
        msg.steer_or_brake = 1;
        msg.speed_or_throttle = 2;
        msg.right_wheel_rpm = 3;
        msg.left_wheel_rpm = 4;
        msg.batt_voltage_x100 = 5;
        msg.temperature = 6;
        msg.led = 7;

        feedback_publisher_->publish(msg);

    }