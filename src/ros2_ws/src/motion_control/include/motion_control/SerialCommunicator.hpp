/*****
* High-level operation of serial_control within Oxbot:
*   1) Jetson Nano is powered up
*   2) Oxbot launch file launches motion_controller node
*       2.1) motion_controller constructor is called
*           2.1.1) private member serial_comm_ is created using the SerialCommunicator::SerialCommunicator() default constructor
*               2.1.1.1) SerialCommunicator() default constructor initializes private members for serial file handles for reading/writing
*       2.2) motion_controller node is spun
*           2.2.1) feedbackTimerCallback() is called at MC_SERIAL_POLLING_FREQUENCY Hz
*               2.2.1.1) get front wheel serial buffer and append it in MotionControllerNode.front_serial_feedback_data vector
*                   2.2.1.1.1) serial_comm_: retreive serial buffer, convert char array to std::vector<unsigned char>, append timestamp, return that vector
*               2.2.1.2) get rear wheel serial buffer and append it in MotionControllerNode.rear_serial_feedback_data vector
*                   2.2.1.2.1) serial_comm_: retreive serial buffer, convert char array to std::vector<unsigned char>, append timestamp, return that vector
*           2.2.2) publishFeedback() is called at MC_OUTPUT_FREQUENCY Hz
*               2.2.2.1) parse/process front_serial_feedback_data and rear_serial_feedback_data, generate vector of oxbot_interfaces::msg::HoverboardFeedback messages
*               2.2.2.2)  

*   3) Hoverboard controllers are powered each powered on
*/
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "termios.h"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/hoverboard_command.hpp"
#include "oxbot_config/oxbot_config.hpp"

class SerialCommunicator
{
    public:
    SerialCommunicator();                                               //default constructor
    SerialCommunicator(std::string, std::string);                       //paramaterized constructor
    SerialCommunicator(const SerialCommunicator&);                      //copy constructor
    SerialCommunicator& operator=(const SerialCommunicator&);           //copy assignment operator
    SerialCommunicator(SerialCommunicator&&) noexcept;                  //move constructor
    SerialCommunicator& operator=(SerialCommunicator&&) noexcept;       //move assignment operator
    ~SerialCommunicator();                                              //destructor

    int sc_write(std::vector<unsigned char>);
    const std::vector<unsigned char> sc_read(); // method returns a vector of unsigned char's containing feedback message data for parsing, if any are in the serial device queue

    bool initialized;
    
    private:
    std::string front_wheels_serial_path_;
    std::string rear_wheels_serial_path_;
    int front_wheels_serial_fh_;
    int rear_wheels_serial_fh_;
    int serial_buff_size_;

    void set_c_flags(termios &, int);
};