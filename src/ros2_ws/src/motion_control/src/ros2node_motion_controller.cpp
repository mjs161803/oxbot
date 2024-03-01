#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "ros2node_motion_controller.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "motion_control_config.hpp"

MotionControllerNode::MotionControllerNode() : Node("motion_controller")
{
    // Timer Definitions
    query_timer_ = this->create_wall_timer(std::chrono::seconds(1.0/SERIAL_POLLING_FREQUENCY), std::bind(&MotionControllerNode::feedback_timer_callback_, this));feedback_publisher_ = this->create_publisher<oxbot_interfaces::msg::HoverboardFeedback>("motor_controller_feedback", 30);
    feedback_timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&MotionControllerNode::publishFeedback, this));
    
    // Serial Communicator definition
    serial_comm_ = SerialCommunicator(FRONT_WHEELS_SERIAL_PATH, REAR_WHEELS_SERIAL_PATH);

    
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

void MotionControllerNode::feedback_timer_callback(const char* serial_buff, int serial_buff_size)
{

}