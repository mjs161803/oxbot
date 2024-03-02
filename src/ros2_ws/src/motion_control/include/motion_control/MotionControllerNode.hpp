#include "rclcpp/rclcpp.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "serial_communicator.hpp"
#include "motion_control_config.hpp"
#include <vector>

class MotionControllerNode: public rclcpp::Node {
    public:
    MotionControllerNode();

    private:

    // Callbacks
    void publishFeedback();
    std::vector<unsigned char> feedbackTimerCallback();     

    rclcpp::Publisher<oxbot_interfaces::msg::HoverboardFeedback>::SharedPtr feedback_publisher_;
    rclcpp::TimerBase::SharedPtr feedback_timer_;
    rclcpp::TimerBase::SharedPtr serial_query_timer_;

    SerialCommunicator serial_comm_;
    std::vector<unsigned char> front_serial_feedback_data;
    std::vector<unsigned char> rear_serial_feedback_data;
};