#ifndef SERIAL_COMMUNICATOR
#define SERIAL_COMMUNICATOR 

#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "termios.h"
#include "oxbot_interfaces/msg/hoverboard_feedback.hpp"
#include "oxbot_interfaces/msg/hoverboard_command.hpp"
#include "FeedbackFrame.hpp"

#define SERIAL_FEEDBACK_MESSAGE_SIZE 18

class SerialCommunicator
{
    public:
    SerialCommunicator();
    SerialCommunicator(const std::string &, const std::string &, const double &, const double &, const double &, const double &, const double &, const double &);
    
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
    double fwheel_orientation_;
    double fwheel_diameter_cm_;
    double fwheel_separation_cm_;
    double rwheel_orientation_;
    double rwheel_diameter_cm_;
    double rwheel_separation_cm_;
    unsigned char front_wheels_command_[8];
    unsigned char rear_wheels_command_[8];

    void set_c_flags(termios &, int);
    void convert_int16_to_uchar_(int16_t, unsigned char*);
    void update_front_checksum();
    void update_rear_checksum();
};

#endif 