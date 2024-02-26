#include "rclcpp/rclcpp.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "serial_communicator.hpp"

class MotionControllerNode: public rclcpp::Node {
    public:
    MotionControllerNode();

    private:
    void publishFeedback();

    rclcpp::Publisher<oxbot_interfaces::msg::HoverboardFeedback>::SharedPtr feedback_publisher_;
    rclcpp::TimerBase::SharedPtr feedback_timer_;
    SerialCommunicator serial_comm_;
};