#include "rclcpp/rclcpp.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "SerialCommunicator.hpp"
#include "oxbot_config/oxbot_config.hpp"
#include <vector>

class MotionControllerNode: public rclcpp::Node {
    public:
    MotionControllerNode();

    private:

    // Callbacks
    void publishOutputCB();
    void feedbackTimerCB();     

    rclcpp::Publisher<oxbot_interfaces::msg::HoverboardFeedback>::SharedPtr output_publisher_;
    rclcpp::TimerBase::SharedPtr serial_feedback_timer_;
    rclcpp::TimerBase::SharedPtr output_timer_;

    SerialCommunicator serial_comm_;
    std::vector<unsigned char> front_serial_feedback_data_;
    std::vector<unsigned char> rear_serial_feedback_data_;
};