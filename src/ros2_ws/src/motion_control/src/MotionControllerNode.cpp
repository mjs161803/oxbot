#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "MotionControllerNode.hpp"
#include "FeedbackFrame.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/motion_control_output.hpp"
#include "oxbot_config/oxbot_config.hpp"


using namespace std::chrono_literals;

MotionControllerNode::MotionControllerNode() : Node("motion_controller")
{
    // Timer Definitions
    int serial_timer_period_micros       = int(1000000* (1.0 / MC_SERIAL_POLLING_FREQUENCY));
    int output_timer_period_micros    = int(1000000* (1.0 / MC_OUTPUT_FREQUENCY));
    serial_feedback_timer_ =   this->create_wall_timer(std::chrono::microseconds(serial_timer_period_micros), std::bind(&MotionControllerNode::feedbackTimerCB, this));
    output_timer_ =       this->create_wall_timer(std::chrono::microseconds(output_timer_period_micros), std::bind(&MotionControllerNode::publishOutputCB, this));
    
    // Publisher Definitions
    output_publisher_ = this->create_publisher<oxbot_interfaces::msg::MotionControlOutput>("motor_controller_output", 30);
    
    // Serial Communicator initializing and Initial Serial Port Handshakes
    try
    {
        serial_comm_ = SerialCommunicator();
        serial_comm_.initialized = serial_comm_.sc_initializing_handshake_frontwheels(); // && serial_comm_.sc_initializing_handshake_rearwheels();
        if (serial_comm_.initialized == false)
        {
            throw std::runtime_error("Unable to initialize SerialCommunicator");
        }
    }
    catch (const std::runtime_error& re)
    {
        RCLCPP_ERROR(this->get_logger(), "MotionControllerNode: Runtime Exception: %s", re.what());
    }
    
}

void MotionControllerNode::publishOutputCB()
{
    auto msg_v = oxbot_interfaces::msg::MotionControlOutput();
    auto msg = oxbot_interfaces::msg::HoverboardFeedback();

    for(auto itr : this->front_serial_feedback_data_)
    {
        msg.steer_or_brake = itr.steering;
        msg.speed_or_throttle = itr.speed;
        msg.right_wheel_rpm = itr.r_rpm;
        msg.left_wheel_rpm = itr.l_rpm;
        msg.batt_voltage_x100 = itr.v_batt;
        msg.temperature = itr.temperature;
        msg.led = itr.led_status;
        msg.timestamp_ns = itr.ts.time_since_epoch().count();
        msg_v.mc_output.push_back(msg);
        // RCLCPP_INFO(this->get_logger(), "Front Wheels:\n   Timestamp: %d\n   Steering: %8d\n   Speed: %8d\n   Right RPM: %8d\n   Left RPM: %8d\n   Battery Voltage: %8d\n   Temperature: %8d\n   LED: %016x.", itr.ts.time_since_epoch().count(), itr.steering, itr.speed, itr.r_rpm, itr.l_rpm, itr.v_batt, itr.temperature, itr.led_status);    
    }

    // iterate over rear_serial_feedback_data_ and convert/publish each FeedBackFrame as a HoverboardFeedback ROS2 message

    output_publisher_->publish(msg_v);
    this->front_serial_feedback_data_.clear();

}

void MotionControllerNode::feedbackTimerCB()
{
    FeedbackFrame current_frame;
    
    current_frame = this->serial_comm_.sc_read_front_wheels();
    if (current_frame.valid)
    {
        this->front_serial_feedback_data_.insert(std::end(this->front_serial_feedback_data_), current_frame);
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "MotionControllerNode::feedbackTimerCB: Reading front wheels serial port device returned invalid feedback frame.");
    }
    
    // current_frame = this->serial_comm_.sc_read_rear_wheels();
    // if (current_frame.valid)
    // {
    //     this->rear_serial_feedback_data_.clear(); // TEMPORARY WHILE TESTING TO PREVENT RUNNING OUT OF MEMORY.  TO BE REMOVED LATER.
    //     this->rear_serial_feedback_data_.insert(std::end(this->rear_serial_feedback_data_), current_frame);
    //     RCLCPP_INFO(this->get_logger(), "Rear Wheels:\n   Steering: %8d\n   Speed: %8d\n   Right RPM: %8d\n   Left RPM: %8d\n Battery Voltage: %8d\n   Temperature: %8d\n LED: %016x.", current_frame.steering, current_frame.speed, current_frame.r_rpm, current_frame.l_rpm, current_frame.v_batt, current_frame.temperature, current_frame.led_status);    
    // }
    // else
    // {
    //     RCLCPP_INFO(this->get_logger(), "Reading rear wheels serial port device returned no feedback message.");
    // }
    
}