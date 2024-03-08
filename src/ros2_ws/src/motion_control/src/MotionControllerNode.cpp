#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "MotionControllerNode.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "motion_control_config.hpp"

using namespace std::chrono_literals;

MotionControllerNode::MotionControllerNode() : Node("motion_controller")
{
    // Timer Definitions
    int query_timer_period_micros       = int(1000000* (1.0 / SERIAL_POLLING_FREQUENCY));
    int feedback_timer_period_micros    = int(1000000* (1.0 / OUTPUT_FREQUENCY));
    serial_query_timer_ =   this->create_wall_timer(std::chrono::microseconds(query_timer_period_micros), std::bind(&MotionControllerNode::feedbackTimerCallback, this));
    feedback_timer_ =       this->create_wall_timer(std::chrono::microseconds(feedback_timer_period_micros), std::bind(&MotionControllerNode::publishFeedback,           this));
    
    // Publisher Definitions
    feedback_publisher_ = this->create_publisher<oxbot_interfaces::msg::HoverboardFeedback>("motor_controller_feedback", 30);
    
    // Serial Communicator definition
    try
    {
        serial_comm_ = SerialCommunicator(FRONT_WHEELS_SERIAL_PATH, REAR_WHEELS_SERIAL_PATH);
        if (serial_comm_.front_wheels_serial_fh_ == NULL)
        {
            throw std::runtime_error("Unable to initialize SerialCommunicator");
        }
    }
    catch (const std::runtime_error& re)
    {
        RCLCPP_ERROR(this->get_logger(), "MotionControllerNode: Runtime Exception: %s", re.what());
    }
    

    
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

std::vector<unsigned char> MotionControllerNode::feedbackTimerCallback()
{
    std::vector<unsigned char> serial_buffer_contents;
    serial_buffer_contents.push_back(0xff);

    front_serial_feedback_data.push_back(0xff);

    return serial_buffer_contents;
}