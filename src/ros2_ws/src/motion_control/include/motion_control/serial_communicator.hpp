#include <string>
#include "termios.h"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/hoverboard_command.hpp"

class SerialCommunicator
{
    public:
    SerialCommunicator();                                           //default constructor
    SerialCommunicator(std::string, std::string);                   //paramaterized constructor
    SerialCommunicator(const SerialCommunicator&);                  //copy constructor
    SerialCommunicator& operator=(const SerialCommunicator&);       //copy assignment operator
    SerialCommunicator(SerialCommunicator&&) noexcept;              //move constructor
    SerialCommunicator& operator=(SerialCommunicator&&) noexcept;   //move assignment operator
    ~SerialCommunicator();                                          //destructor

    int sc_write(const oxbot_interfaces::msg::HoverboardCommand);
    const oxbot_interfaces::msg::HoverboardFeedback sc_read();

    private:
    std::string front_wheels_serial_path_;
    std::string rear_wheels_serial_path_;
    int front_wheels_serial_fh_;
    int rear_wheels_serial_fh_;

};