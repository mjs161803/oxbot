#include "rclcpp/rclcpp.hpp"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "serial_communicator.hpp"

class MotionControllerNode: public rclcpp::Node {
    public:
    MotionControllerNode();

    private:

    // Callbacks
    void publishFeedback();
    void feedback_timer_callback(const char*, int);     

    rclcpp::Publisher<oxbot_interfaces::msg::HoverboardFeedback>::SharedPtr feedback_publisher_;
    rclcpp::TimerBase::SharedPtr feedback_timer_;
    rclcpp::TimerBase::SharedPtr query_timer_;

    SerialCommunicator serial_comm_;
    int serial_buff_size_;
};