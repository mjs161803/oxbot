
#include <string>
#include "serial_communicator.hpp"
#include "motion_control_config.hpp"

SerialCommunicator::SerialCommunicator(): front_wheels_serial_path_(FRONT_WHEELS_SERIAL_PATH), rear_wheels_serial_path_(REAR_WHEELS_SERIAL_PATH), fh_(0)
{

}

SerialCommunicator::SerialCommunicator(std::string front_wheel_path, std::string rear_wheel_path): fh_(0)
{
    front_wheels_serial_path_ = front_wheel_path;
    rear_wheels_serial_path_ = rear_wheel_path;
}