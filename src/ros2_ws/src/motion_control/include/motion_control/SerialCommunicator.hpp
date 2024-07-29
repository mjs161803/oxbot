/*****
* High-level operation of serial_control within Oxbot:
*   1) Jetson Nano is powered up
*   2) Oxbot launch file launches motion_controller node
*       2.1) motion_controller constructor is called
*           2.1.1) private member serial_comm_ is initialized using the SerialCommunicator::SerialCommunicator() default constructor
*               2.1.1.1) SerialCommunicator() default constructor initializes private members for serial file handles for reading/writing
*           2.1.2) private member 'initialized' is calculated by sc_initializing_handshake_frontwheels() && sc_initializing_handshake_rearwheels()
*               NOTE: this will block the thread until the serial handshakes are completed.
*       2.2) Hoverboard controllers are powered each powered on
*       2.3) motion_controller node constructor is completed after serial handshaking finishes, and node is then spun
*           2.3.1) feedbackTimerCallback() is called at MC_SERIAL_POLLING_FREQUENCY Hz
*               2.3.1.1) get front wheel serial buffer and append it in MotionControllerNode.front_serial_feedback_data vector
*                   2.3.1.1.1) serial_comm_: retreive serial buffer, convert char array to std::vector<unsigned char>, append timestamp, return that vector
*               2.3.1.2) get rear wheel serial buffer and append it in MotionControllerNode.rear_serial_feedback_data vector
*                   2.3.1.2.1) serial_comm_: retreive serial buffer, convert char array to std::vector<unsigned char>, append timestamp, return that vector
*           2.3.2) publishFeedback() is called at MC_OUTPUT_FREQUENCY Hz
*               2.3.2.1) parse/process front_serial_feedback_data and rear_serial_feedback_data, generate vector of oxbot_interfaces::msg::HoverboardFeedback messages
*               2.3.2.2)  
*/
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "termios.h"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/hoverboard_command.hpp"
#include "oxbot_config/oxbot_config.hpp"
#include "FeedbackFrame.hpp"

class SerialCommunicator
{
    public:
    SerialCommunicator();                                               //default constructor
    
    FeedbackFrame sc_read_front_wheels();            // method reads the front wheels serial device, and returns a timestamped serial buffer contents as a vector of unsigned chars
    FeedbackFrame sc_read_rear_wheels();             // method reads the rear wheels serial device, and returns a timestamped serial buffer contents as a vector of unsigned chars
    bool sc_initializing_handshake_frontwheels();
    bool sc_initializing_handshake_rearwheels();
    bool initialized;
    void set_front_speed(double);
    void set_front_steer(double);
    
    void set_rear_speed(double);
    void set_rear_steer(double);
    
    private:
    std::string front_wheels_serial_path_;
    std::string rear_wheels_serial_path_;
    int front_wheels_serial_fh_;
    int rear_wheels_serial_fh_;
    int serial_buff_size_;
    unsigned char front_wheels_command_[8];
    unsigned char rear_wheels_command_[8];

    void set_c_flags(termios &, int);
    void convert_int16_to_uchar_(int16_t, unsigned char*);
    void update_front_checksum();
    void update_rear_checksum();
};