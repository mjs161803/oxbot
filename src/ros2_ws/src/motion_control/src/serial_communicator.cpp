
#include <string>
#include <iostream>
#include "stdio.h"


#include "serial_communicator.hpp"
#include "motion_control_config.hpp"

SerialCommunicator::SerialCommunicator(): front_wheels_serial_path_(FRONT_WHEELS_SERIAL_PATH), rear_wheels_serial_path_(REAR_WHEELS_SERIAL_PATH), front_wheels_serial_fh_(0), rear_wheels_serial_fh_(0)
{
    this->front_wheels_serial_fh_ = open(this->front_wheels_serial_path_, O_RDWR);
	    if (this->arduino < 0) {
		    RCLCPP_ERROR(this->get_logger(), "Unable to open /dev/ttyACM0.");
	    }

}

SerialCommunicator::SerialCommunicator(std::string front_wheel_path, std::string rear_wheel_path): front_wheels_serial_fh_(0), rear_wheels_serial_fh_(0)
{
    front_wheels_serial_path_ = front_wheel_path;
    rear_wheels_serial_path_ = rear_wheel_path;
}