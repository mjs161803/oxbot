#include "rclcpp/rclcpp.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/motion_control_output.hpp"
#include "SerialCommunicator.hpp"
#include "FeedbackFrame.hpp"
#include "oxbot_config/oxbot_config.hpp"
#include <vector>

class MotionControllerNode: public rclcpp::Node {
    public:
    MotionControllerNode();

    private:

    // Callbacks
    void publishOutputCB();
    void feedbackTimerCB();     

    rclcpp::Publisher<oxbot_interfaces::msg::MotionControlOutput>::SharedPtr output_publisher_;
    // set up subscriber for cmd_vel commands. CB will then update speed and steering for serial_comm_ member
    rclcpp::TimerBase::SharedPtr serial_feedback_timer_;
    rclcpp::TimerBase::SharedPtr output_timer_;

    SerialCommunicator serial_comm_;
    std::vector<FeedbackFrame> front_serial_feedback_data_;
    std::vector<FeedbackFrame> rear_serial_feedback_data_;
};