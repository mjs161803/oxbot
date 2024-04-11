
#include <string>
#include <iostream>
#include <stdexcept>
#include <chrono>

#include "termios.h"
#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "rclcpp/rclcpp.hpp"

#include "SerialCommunicator.hpp"
#include "oxbot_config/oxbot_config.hpp"

using namespace std::chrono_literals;

SerialCommunicator::SerialCommunicator(): front_wheels_serial_path_(MC_FRONT_WHEELS_SERIAL_PATH), rear_wheels_serial_path_(MC_REAR_WHEELS_SERIAL_PATH), front_wheels_serial_fh_(0), rear_wheels_serial_fh_(0)
{
    front_wheels_command_[0] = 0xCD;
    front_wheels_command_[1] = 0xAB;
    front_wheels_command_[2] = 0x00;
    front_wheels_command_[3] = 0x00; 
    front_wheels_command_[4] = 0x00;
    front_wheels_command_[5] = 0x00;
    front_wheels_command_[6] = 0xCD;
    front_wheels_command_[7] = 0xAB;

    rear_wheels_command_[0] = 0xCD;
    rear_wheels_command_[1] = 0xAB;
    rear_wheels_command_[2] = 0x00;
    rear_wheels_command_[3] = 0x00; 
    rear_wheels_command_[4] = 0x00;
    rear_wheels_command_[5] = 0x00;
    rear_wheels_command_[6] = 0xCD;
    rear_wheels_command_[7] = 0xAB;   

    // Front Wheels Serial Port Configuring
    try
    {
        front_wheels_serial_fh_ = open((front_wheels_serial_path_).c_str(), O_RDWR); 
        if (front_wheels_serial_fh_ == -1) 
        {
            initialized = false;
            throw std::runtime_error("Error opening serial device file for front wheels.");
        }  
        else
        {
            initialized = true;
        }
    }
    catch(const std::runtime_error& re)
    {
        front_wheels_serial_fh_ = -1;
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: Runtime Exception: %s", re.what());
    }
    catch(const std::exception& e)
    {
        front_wheels_serial_fh_ = -1;
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: Exception: %s", e.what());
    }
    
    struct termios front_serial_term;
    if (tcgetattr(front_wheels_serial_fh_, &front_serial_term) != 0) 
    {
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "MC::SC default constructor: Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(front_serial_term, front_wheels_serial_fh_);

    // Rear Wheels Serial Port Configuring
    // rear_wheels_serial_fh_ = open((rear_wheels_serial_path_).c_str(), O_RDWR | O_NONBLOCK);
	//     if (rear_wheels_serial_fh_ < 0) {
	// 	    RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "MC::SC Default Constructor: Unable to open %s.", rear_wheels_serial_path_);
	//     }
    // struct termios rear_serial_term;
    // if (tcgetattr(rear_wheels_serial_fh_, &rear_serial_term) != 0) 
    // {
    //     RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "Error %i from tcgetattr: %s\n", errno, strerror(errno));
    // }
    // set_c_flags(rear_serial_term, rear_wheels_serial_fh_);

}

void SerialCommunicator::set_c_flags(termios &ser_term, int fh) 
{
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
    ser_term.c_cc[VTIME] = 1; // Will wait for 0.1 seconds -> 10Hz min feedback frequency
    ser_term.c_cc[VMIN] = MC_SERIAL_FEEDBACK_MESSAGE_SIZE; 
    cfsetspeed(&ser_term, B115200);
    if (tcsetattr(fh, TCSANOW, &ser_term) != 0) {
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
}

FeedbackFrame SerialCommunicator::sc_read_front_wheels() 
{
    FeedbackFrame ser_frame;
    ser_frame.ts = std::chrono::steady_clock::now();
    bool valid_msg {false};
    int bytes_read {0};
    unsigned char read_buf [MC_SERIAL_FEEDBACK_MESSAGE_SIZE] = {};
    try
    {
        bytes_read = read(this->front_wheels_serial_fh_, &read_buf, sizeof(read_buf));
        if (bytes_read == -1) 
        {
            throw std::runtime_error("Error reading front serial buffer.");
        }  
    }
    catch(const std::runtime_error& re)
    {
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: Runtime Exception: %s", re.what());
    }

    // SERIAL DATA IS LITTLE-ENDIAN (LSB FIRST)
    
    // verify bytes_read == MC_SERIAL_FEEDBACK_MESSAGE_SIZE
    // verify first 2 bytes are 0xABCD
    if ((bytes_read != MC_SERIAL_FEEDBACK_MESSAGE_SIZE) | (read_buf[0] != 0xCD) | (read_buf[1] != 0xAB))
    {
        valid_msg = false;
        RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "Non-valid serial message from front wheels: %d bytes read, 0x%2x 0x%2x header bytes", bytes_read, read_buf[0], read_buf[1]);
    }
    else
    {
        valid_msg = true;
    }

    // verify XOR checksum
    unsigned char checksum_lsb = read_buf[0]^read_buf[2]^read_buf[4]^read_buf[6]^read_buf[8]^read_buf[10]^read_buf[12]^read_buf[14];
    unsigned char checksum_msb = read_buf[1]^read_buf[3]^read_buf[5]^read_buf[7]^read_buf[9]^read_buf[11]^read_buf[13]^read_buf[15];
    if ((checksum_lsb != read_buf[16]) | (checksum_msb != read_buf[17]))
    {
        valid_msg = false;
        RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "Calculated serial frame checksum does not match received. Calculated checksum: 0x%2x %2x, Raw frame: 0x%2x%2x %2x%2x %2x%2x %2x%2x %2x%2x %2x%2x %2x%2x %2x%2x %2x%2x.", checksum_msb, checksum_lsb, read_buf[0], read_buf[1], read_buf[2], read_buf[3], read_buf[4], read_buf[5], read_buf[6], read_buf[7], read_buf[8], read_buf[9], read_buf[10], read_buf[11], read_buf[12], read_buf[13], read_buf[14], read_buf[15], read_buf[16], read_buf[17]);
    }

    if (valid_msg)
    {
        // process CMD1 (signed int16): steer or brake command
        ser_frame.steering = ((read_buf[2]) << 8) | read_buf[3];
        
        // process CMD2 (signed int16): speed or throttle
        ser_frame.speed = ((read_buf[4]) << 8) | read_buf[5];
        
        // process SpeedR (signed int16): right wheel speed in RPM
        ser_frame.r_rpm = ((read_buf[6]) << 8) | read_buf[7];
        
        // process SpeedL (signed int16): left wheel speed in RPM
        ser_frame.l_rpm = ((read_buf[8]) << 8) | read_buf[9];
        
        // process Battery Voltage (signed int16): battery voltage x 100
        ser_frame.v_batt = ser_frame.convert_v_batt(read_buf[10], read_buf[11]);
        
        // process Temperature (signed int16): temperature in degrees C x 10
        ser_frame.temperature = ser_frame.convert_temp(read_buf[12], read_buf[13]);
        
        // process LED (unsigned int16): state of sideboard LEDs
        ser_frame.led_status = ((read_buf[14]) << 8) | read_buf[15];

        ser_frame.valid = true;

    }

    tcflush(front_wheels_serial_fh_, TCIFLUSH);
    
    write(this->front_wheels_serial_fh_, this->front_wheels_command_, sizeof(this->front_wheels_command_));
    // write(this->rear_wheels_serial_fh_, this->rear_wheels_command_, sizeof(this->rear_wheels_command_));

    return ser_frame;
}

FeedbackFrame SerialCommunicator::sc_read_rear_wheels() 
{
    FeedbackFrame ser_frame;
    ser_frame.ts = std::chrono::steady_clock::now();
    // bool valid_msg {false};
    // int bytes_read {0};
    // unsigned char read_buf [MC_SERIAL_FEEDBACK_MESSAGE_SIZE] = {};
    // try
    // {
    //     int bytes_read = read(this->rear_wheels_serial_fh_, &read_buf, sizeof(read_buf));
    //     if (bytes_read == -1) 
    //     {
    //         throw std::runtime_error("Error reading rear serial buffer.");
    //     }  
    // }
    // catch(const std::runtime_error& re)
    // {
    //     RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: Runtime Exception: %s", re.what());
    // }

    return ser_frame;
}

bool SerialCommunicator::sc_initializing_handshake_frontwheels()
{
    bool result {false};
    unsigned char initial_command[8] {  0xCD, 0xAB,     // frame header start
                                        0x00, 0x00,     // steer command = 0
                                        0x00, 0x00,     // speed command = 0 
                                        0xCD, 0xAB};    // XOR checksum
    
    
    int bytes_read {0};
    unsigned char read_buf [MC_SERIAL_FEEDBACK_MESSAGE_SIZE] = {};
    auto read_delay_duration = std::chrono::nanoseconds(100ms);
    auto sleep_duration = std::chrono::nanoseconds(1s);
    auto sync_delay_duration = std::chrono::nanoseconds(101ms);

    while (result == false)
    {
        try
        {
            write(this->front_wheels_serial_fh_, initial_command, sizeof(initial_command));
            rclcpp::sleep_for(read_delay_duration);
            bytes_read = read(this->front_wheels_serial_fh_, &read_buf, MC_SERIAL_FEEDBACK_MESSAGE_SIZE);
            if (bytes_read < 0) 
            {
                throw std::runtime_error("Error reading front serial buffer.");
            }  
            else if (bytes_read == 0)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC front wheels initializing handshake: read 0 bytes... waiting 1 second");
                rclcpp::sleep_for(sleep_duration);
                result = false;
            }
            else if (bytes_read > 0 && bytes_read < MC_SERIAL_FEEDBACK_MESSAGE_SIZE)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC front wheels initializing handshake: read incomplete message of %d bytes. Expected %d bytes... waiting 1 second", bytes_read, MC_SERIAL_FEEDBACK_MESSAGE_SIZE);
                rclcpp::sleep_for(sleep_duration);
                tcflush(front_wheels_serial_fh_, TCIFLUSH);
                result = false;
            }
            else if (bytes_read == MC_SERIAL_FEEDBACK_MESSAGE_SIZE && read_buf[0] != 0xCD && read_buf[1] != 0xAB)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC front wheels initializing handshake: successfully read feedback frame of %d bytes, but incorrect header. Raw frame: 0x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x.", bytes_read, read_buf[0], read_buf[1], read_buf[2], read_buf[3], read_buf[4], read_buf[5], read_buf[6], read_buf[7], read_buf[8], read_buf[9], read_buf[10], read_buf[11], read_buf[12], read_buf[13], read_buf[14], read_buf[15], read_buf[16], read_buf[17]);
                rclcpp::sleep_for(sync_delay_duration);
                tcflush(front_wheels_serial_fh_, TCIFLUSH);
                result = false;
            }
            else if (bytes_read == MC_SERIAL_FEEDBACK_MESSAGE_SIZE && read_buf[0] == 0xCD && read_buf[1] == 0xAB)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC front wheels initializing handshake: successfully read feedback frame of %d bytes with correct header. Raw frame: 0x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x.", bytes_read, read_buf[0], read_buf[1], read_buf[2], read_buf[3], read_buf[4], read_buf[5], read_buf[6], read_buf[7], read_buf[8], read_buf[9], read_buf[10], read_buf[11], read_buf[12], read_buf[13], read_buf[14], read_buf[15], read_buf[16], read_buf[17]);
                result = true;
            }
        }
        catch(const std::runtime_error& re)
        {
            RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: Runtime Exception: %s", re.what());
        }
    }

    return result;
}

void SerialCommunicator::convert_int16_to_uchar_(int16_t int16_cmd, unsigned char* cmd_bytes, int num_bytes_cmd_array)
{
    cmd_bytes[0] = int16_cmd && 0x0011;   // LSB of int16
    cmd_bytes[1] = int16_cmd >> 8;        // MSB of int16
}

void SerialCommunicator::set_front_steer(int16_t st)
{
    unsigned char new_steer[2] {0x00};
    convert_int16_to_uchar_(st, new_steer, sizeof(new_steer));
    this->front_wheels_command_[2] = new_steer[0];  // LSB first
    this->front_wheels_command_[3] = new_steer[1];  // MSB second
    update_front_checksum();
}

void SerialCommunicator::set_front_speed(int16_t sp)
{
    unsigned char new_speed[2] {0x00};
    convert_int16_to_uchar_(sp, new_speed, sizeof(new_speed));
    this->front_wheels_command_[4] = new_speed[0];  // LSB first
    this->front_wheels_command_[5] = new_speed[1];  // MSB second
    update_front_checksum();
}

void SerialCommunicator::update_front_checksum()
{
    unsigned char checksum_lsb = front_wheels_command_[0]^front_wheels_command_[2]^front_wheels_command_[4];
    unsigned char checksum_msb = front_wheels_command_[1]^front_wheels_command_[3]^front_wheels_command_[5];
    front_wheels_command_[6] = checksum_lsb;
    front_wheels_command_[7] = checksum_msb;
}

void SerialCommunicator::update_rear_checksum()
{
    unsigned char checksum_lsb = rear_wheels_command_[0]^rear_wheels_command_[2]^rear_wheels_command_[4];
    unsigned char checksum_msb = rear_wheels_command_[1]^rear_wheels_command_[3]^rear_wheels_command_[5];
    rear_wheels_command_[6] = checksum_lsb;
    rear_wheels_command_[7] = checksum_msb;
}