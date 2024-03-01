/*****
* High-level operation of serial_control within Oxbot:
*   1) Jetson Nano is powered up
*   2) Oxbot launch file launches motion_controller node
*       2.1) motion_controller constructor is called
*           2.1.1) private member serial_comm_ is created using the SerialCommunicator::SerialCommunicator() default constructor
*               2.1.1.1) SerialCommunicator() default constructor initializes private members for serial file handles for reading/writing
*       2.2) motion_controller node is spun
*           2.2.1) serial_timer_callback_() is called at SERIAL_POLLING_FREQUENCY Hz
*               2.2.1.1) ros2node_motion_controller->serial_timer_callback_: Gather raw serial data via motion_controller->sc_read() call
*                   2.2.1.1.1) serial_comm_: retreive serial buffer
*                   2.2.1.1.3) serial_comm_: parse buffer into oxbot_interfaces::msg::HoverboardFeedback objects, calculating and adding timestamps 
*                   2.2.1.1.4) a std::vector<oxbot_interfaces::msg::HoverboardFeedback> object is returned to SerialCommunicator object
*               2.2.1.2) SerialCommunicator->serial_timer_callback_: check for null

*   3) Hoverboard controllers are powered each powered on
*/
#include <string>
#include <vector>
#include "termios.h"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/hoverboard_command.hpp"

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

    int sc_write(const oxbot_interfaces::msg::HoverboardCommand);
    const std::vector<oxbot_interfaces::msg::HoverboardFeedback> sc_read(); // method returns a character buffer containing feedback message data for parsing, if any are in the serial device queue

    private:
    std::string front_wheels_serial_path_;
    std::string rear_wheels_serial_path_;
    int front_wheels_serial_fh_;
    int rear_wheels_serial_fh_;
    int serial_buff_size_;
};