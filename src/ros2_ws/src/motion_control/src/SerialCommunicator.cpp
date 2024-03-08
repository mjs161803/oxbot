
#include <string>
#include <iostream>
#include <stdexcept>

#include "termios.h"
#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/logger.hpp"

#include "SerialCommunicator.hpp"
#include "oxbot_config/oxbot_config.hpp"

void set_c_flags(termios &, int fh, rclcpp::Logger &);

SerialCommunicator::SerialCommunicator(): front_wheels_serial_path_(MC_FRONT_WHEELS_SERIAL_PATH), rear_wheels_serial_path_(MC_REAR_WHEELS_SERIAL_PATH), front_wheels_serial_fh_(0), rear_wheels_serial_fh_(0)
{
    // Front Wheels Serial Port Configuring
    try
    {
        front_wheels_serial_fh_ = open((front_wheels_serial_path_).c_str(), O_RDWR); 
        if (front_wheels_serial_fh_ == -1) 
        {
            throw std::runtime_error("Error opening serial device file for front wheels.");
        }  
    }
    catch(const std::runtime_error& re)
    {
        front_wheels_serial_fh_ = NULL;
        RCLCPP_ERROR(serial_logger_, "SerialCommunicator: Runtime Exception: %s", re.what());
    }
    catch(const std::exception& e)
    {
        front_wheels_serial_fh_ = NULL;
        RCLCPP_ERROR(serial_logger_, "SerialCommunicator: Exception: %s", e.what());
    }
    
    struct termios front_serial_term;
    if (tcgetattr(front_wheels_serial_fh_, &front_serial_term) != 0) 
    {
        RCLCPP_ERROR(serial_logger_, "Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(front_serial_term, front_wheels_serial_fh_);

    // Rear Wheels Serial Port Configuring
    rear_wheels_serial_fh_ = open((rear_wheels_serial_path_).c_str(), O_RDWR);
	    if (rear_wheels_serial_fh_ < 0) {
		    RCLCPP_ERROR(serial_logger_, "Unable to open %s.", rear_wheels_serial_path_);
	    }
    struct termios rear_serial_term;
    if (tcgetattr(rear_wheels_serial_fh_, &rear_serial_term) != 0) 
    {
        RCLCPP_ERROR(serial_logger_, "Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(rear_serial_term, front_wheels_serial_fh_);

}

SerialCommunicator::SerialCommunicator(std::string front_wheel_path, std::string rear_wheel_path): front_wheels_serial_fh_(0), rear_wheels_serial_fh_(0)
{
    front_wheels_serial_path_ = front_wheel_path;
    rear_wheels_serial_path_ = rear_wheel_path;

    
}

void SerialCommunicator::set_c_flags(termios &ser_term, int fh) {
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
        RCLCPP_ERROR(serial_logger_, "Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
}

const std::vector<unsigned char> SerialCommunicator::sc_read() 
{
    const std::vector<unsigned char> ser_buf;
    unsigned char read_buf [MC_SERIAL_FEEDBACK_MESSAGE_SIZE];
    try
    {
        int bytes_read = read(this->front_wheels_serial_fh_, &read_buf, sizeof(read_buf));
        if (bytes_read == -1) 
        {
            throw std::runtime_error("Error reading serial buffer.");
        }  
    }
    catch(const std::runtime_error& re)
    {
        RCLCPP_ERROR(serial_logger_, "SerialCommunicator: Runtime Exception: %s", re.what());
    }

    return ser_buf;
}

int SerialCommunicator::sc_write(std::vector<unsigned char> write_buf)
{
    int num_written (0);

    return num_written;
}