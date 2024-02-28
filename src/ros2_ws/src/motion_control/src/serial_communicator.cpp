
#include <string>
#include <iostream>
#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "rclcpp/rclcpp.hpp"

#include "serial_communicator.hpp"
#include "motion_control_config.hpp"

void set_c_flags(termios &, int fh, rclcpp::Logger &);

SerialCommunicator::SerialCommunicator(): front_wheels_serial_path_(FRONT_WHEELS_SERIAL_PATH), rear_wheels_serial_path_(REAR_WHEELS_SERIAL_PATH), front_wheels_serial_fh_(0), rear_wheels_serial_fh_(0)
{
    auto serial_logger = rclcpp::get_logger("serial_logger");
    
    // Front Wheels Serial Port Configuring
    front_wheels_serial_fh_ = open((front_wheels_serial_path_).c_str(), O_RDWR);
	    if (front_wheels_serial_fh_ < 0) {
		    RCLCPP_ERROR(serial_logger, "Unable to open %s.", front_wheels_serial_path_);
	    }
    struct termios front_serial_term;
    if (tcgetattr(front_wheels_serial_fh_, &front_serial_term) != 0) 
    {
        RCLCPP_ERROR(serial_logger, "Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(front_serial_term, front_wheels_serial_fh_, serial_logger);

    // Rear Wheels Serial Port Configuring
    rear_wheels_serial_fh_ = open((rear_wheels_serial_path_).c_str(), O_RDWR);
	    if (rear_wheels_serial_fh_ < 0) {
		    RCLCPP_ERROR(serial_logger, "Unable to open %s.", rear_wheels_serial_path_);
	    }
    struct termios rear_serial_term;
    if (tcgetattr(rear_wheels_serial_fh_, &rear_serial_term) != 0) 
    {
        RCLCPP_ERROR(serial_logger, "Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(rear_serial_term, front_wheels_serial_fh_, serial_logger);

}

SerialCommunicator::SerialCommunicator(std::string front_wheel_path, std::string rear_wheel_path): front_wheels_serial_fh_(0), rear_wheels_serial_fh_(0)
{
    auto serial_logger = rclcpp::get_logger("serial_logger");
    
    front_wheels_serial_path_ = front_wheel_path;
    rear_wheels_serial_path_ = rear_wheel_path;

    
}

void set_c_flags(termios &ser_term, int fh, rclcpp::Logger &ser_logger) {
    ser_term.c_cflag &= ~PARENB;
    ser_term.c_cflag &= ~CSTOPB;
    ser_term.c_cflag &= ~CSIZE;
    ser_term.c_cflag |= CS8;
    ser_term.c_cflag &= ~CRTSCTS;
    ser_term.c_cflag |= CREAD | CLOCAL;
    ser_term.c_lflag &= ~ICANON;
    ser_term.c_lflag &= ~ECHO;
    ser_term.c_lflag &= ~ECHOE;
    ser_term.c_lflag &= ~ECHONL;
    ser_term.c_lflag &= ~ISIG;
    ser_term.c_iflag &= ~(IXON | IXOFF | IXANY);
    ser_term.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
    ser_term.c_oflag &= ~OPOST;
    ser_term.c_oflag &= ~ONLCR;
    ser_term.c_cc[VTIME] = 10; // 1 second
    ser_term.c_cc[VMIN] = 0;
    cfsetspeed(&ser_term, B115200);
    if (tcsetattr(fh, TCSANOW, &ser_term) != 0) {
        RCLCPP_ERROR(ser_logger, "Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
}