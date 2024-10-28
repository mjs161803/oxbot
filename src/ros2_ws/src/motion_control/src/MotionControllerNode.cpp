#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "MotionControllerNode.hpp"
#include "FeedbackFrame.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/motion_control_output.hpp"
#include "oxbot_config/oxbot_config.hpp"


using namespace std::chrono_literals;
using std::placeholders::_1;

MotionControllerNode::MotionControllerNode() : Node("motion_controller")
{
    // Timer Definitions
    int serial_timer_period_micros       = int(1000000* (1.0 / MC_SERIAL_POLLING_FREQUENCY));
    int output_timer_period_micros    = int(1000000* (1.0 / MC_OUTPUT_FREQUENCY));
    serial_feedback_timer_ =   this->create_wall_timer(std::chrono::microseconds(serial_timer_period_micros), std::bind(&MotionControllerNode::feedbackTimerCB, this));
    odom_timer_ =       this->create_wall_timer(std::chrono::microseconds(output_timer_period_micros), std::bind(&MotionControllerNode::publishOdomCB, this));
    
    // Subscriber Definitions
    cmd_subscription_ = this->create_subscription<geometry_msgs::msg::Twist>("motion_cmd", 10, std::bind(&MotionControllerNode::cmdSubscriptionCB, this, _1));

    // Publisher Definitions
    odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("motor_controller_odom", 30);
    
    // Initializing current_odom_ message contents
    current_odom_.header.frame_id = "odom";
    current_odom_.header.stamp = this->get_clock()->now();
    current_odom_.child_frame_id = "base_footprint";
    current_odom_.pose.pose.position.x = 0.0;
    current_odom_.pose.pose.position.y = 0.0;
    current_odom_.pose.pose.position.z = 0.0;
    current_odom_.pose.pose.orientation.x = 0.0;
    current_odom_.pose.pose.orientation.y = 0.0;
    current_odom_.pose.pose.orientation.z = 0.0;
    current_odom_.pose.pose.orientation.w = 1.0;
    current_odom_.twist.twist.linear.x = 0.0;
    current_odom_.twist.twist.linear.y = 0.0;
    current_odom_.twist.twist.linear.z = 0.0;
    current_odom_.twist.twist.angular.x = 0.0;
    current_odom_.twist.twist.angular.y = 0.0;
    current_odom_.twist.twist.angular.z = 0.0;

    // Serial Communicator initializing and Initial Serial Port Handshakes
    try
    {
        serial_comm_ = SerialCommunicator();
        serial_comm_.initialized = serial_comm_.sc_initializing_handshake_frontwheels(); // && serial_comm_.sc_initializing_handshake_rearwheels();
        if (serial_comm_.initialized == false)
        {
            throw std::runtime_error("Unable to initialize SerialCommunicator");
        }
        serial_comm_.initialized = serial_comm_.sc_initializing_handshake_rearwheels(); // && serial_comm_.sc_initializing_handshake_rearwheels();
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

void MotionControllerNode::cmdSubscriptionCB(const geometry_msgs::msg::Twist &msg)
{
    // to-do: after receiving a Twist msg, update serial_comm_.front_wheels_command_ and .rear_wheels_command_
    double steer_cmd = msg.angular.z; // in units of rad/sec
    double speed_cmd = msg.linear.x;  // in units of m/sec
    //rclcpp_info(this->get_logger(), "MotionControllerNode: Attempting to update hoverboard command to steer_cmd=%d  speed_cmd=%d", steer_cmd, speed_cmd);
    this->serial_comm_.set_front_steer(steer_cmd);
    this->serial_comm_.set_front_speed(speed_cmd);
    this->serial_comm_.set_rear_steer(steer_cmd);
    this->serial_comm_.set_rear_speed(speed_cmd);
}

void MotionControllerNode::publishOdomCB()
{
    odom_publisher_->publish(current_odom_);
}

void MotionControllerNode::feedbackTimerCB()
{
    auto front_frame = this->serial_comm_.sc_read_front_wheels();
    if (!front_frame.valid)
    {
        RCLCPP_INFO(this->get_logger(), "MotionControllerNode::feedbackTimerCB: Reading front wheels serial port device returned invalid feedback frame.");
    }
    
    auto rear_frame = this->serial_comm_.sc_read_rear_wheels();
    if (!rear_frame.valid)
    {
        RCLCPP_INFO(this->get_logger(), "MotionControllerNode::feedbackTimerCB: Reading rear wheels serial port device returned invalid feedback frame.");
    }
       // update current_odom_

}