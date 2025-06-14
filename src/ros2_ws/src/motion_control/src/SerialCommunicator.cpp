
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

using namespace std::chrono_literals;

SerialCommunicator::SerialCommunicator()
{
    front_wheels_serial_path_="/dev/front_wheels";
    rear_wheels_serial_path_="/dev/rear_wheels";
    front_wheels_serial_fh_=0;
    rear_wheels_serial_fh_=0;
    fwheel_orientation_=1.0;
    rwheel_orientation_=-1.0;
    fwheel_diameter_cm_=19.0;
    fwheel_separation_cm_=62.5;
    rwheel_diameter_cm_=24.5;
    rwheel_separation_cm_=66.0;
    front_wheels_serial_fh_ = 0;

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
    front_wheels_serial_fh_ = open((front_wheels_serial_path_).c_str(), O_RDWR); 
    if (front_wheels_serial_fh_ == -1) 
    {
        initialized = false;
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: unable to open front wheel serial port.");
    }  
    else
    {
        initialized = true;
    }
    
    struct termios front_serial_term;
    if (tcgetattr(front_wheels_serial_fh_, &front_serial_term) != 0) 
    {
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "MC::SC default constructor: Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(front_serial_term, front_wheels_serial_fh_);

    // Rear Wheels Serial Port Configuring
    rear_wheels_serial_fh_ = open((rear_wheels_serial_path_).c_str(), O_RDWR); 
    if (rear_wheels_serial_fh_ == -1) 
    {
        initialized = false;
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: unable to open rear wheels serial port.");
    }  
    else
    {
        initialized = true;
    }
    
    struct termios rear_serial_term;
    if (tcgetattr(rear_wheels_serial_fh_, &rear_serial_term) != 0) 
    {
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "MC::SC default constructor: Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(rear_serial_term, rear_wheels_serial_fh_);

}

SerialCommunicator::SerialCommunicator( const std::string front_path, 
                                        const std::string rear_path,
                                        const double front_orientation,
                                        const double rear_orientation,
                                        const double front_diameter, 
                                        const double front_separation,
                                        const double rear_diameter,
                                        const double rear_separation) 
{
    front_wheels_serial_path_=front_path; 
    rear_wheels_serial_path_=rear_path; 
    front_wheels_serial_fh_=0;
    rear_wheels_serial_fh_=0;
    fwheel_orientation_=front_orientation;
    rwheel_orientation_=rear_orientation;
    fwheel_diameter_cm_=front_diameter;
    fwheel_separation_cm_=front_separation;
    rwheel_diameter_cm_=rear_diameter;
    rwheel_separation_cm_=rear_separation;
    
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
    front_wheels_serial_fh_ = open((front_wheels_serial_path_).c_str(), O_RDWR); 
    if (front_wheels_serial_fh_ == -1) 
    {
        initialized = false;
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: unable to open front wheel serial port.");
    }  
    else
    {
        initialized = true;
    }
    
    struct termios front_serial_term;
    if (tcgetattr(front_wheels_serial_fh_, &front_serial_term) != 0) 
    {
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "MC::SC default constructor: Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(front_serial_term, front_wheels_serial_fh_);

    // Rear Wheels Serial Port Configuring
    rear_wheels_serial_fh_ = open((rear_wheels_serial_path_).c_str(), O_RDWR); 
    if (rear_wheels_serial_fh_ == -1) 
    {
        initialized = false;
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: unable to open rear wheels serial port.");
    }  
    else
    {
        initialized = true;
    }
    
    struct termios rear_serial_term;
    if (tcgetattr(rear_wheels_serial_fh_, &rear_serial_term) != 0) 
    {
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "MC::SC default constructor: Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }
    set_c_flags(rear_serial_term, rear_wheels_serial_fh_);

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
    ser_term.c_cc[VMIN] = SERIAL_FEEDBACK_MESSAGE_SIZE; 
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
    unsigned char read_buf [SERIAL_FEEDBACK_MESSAGE_SIZE] = {};
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
    
    // verify bytes_read == SERIAL_FEEDBACK_MESSAGE_SIZE
    // verify first 2 bytes are 0xABCD
    if ((bytes_read != SERIAL_FEEDBACK_MESSAGE_SIZE) | (read_buf[0] != 0xCD) | (read_buf[1] != 0xAB))
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
        ser_frame.steering = read_buf[2] | (read_buf[3] << 8);
        
        // process CMD2 (signed int16): speed or throttle
        ser_frame.speed = int16_t(fwheel_orientation_)*int16_t(read_buf[4] | (read_buf[5] << 8));
        
        // process SpeedR (signed int16): right wheel speed in RPM
        ser_frame.r_rpm = int16_t(fwheel_orientation_)*(-1 * int16_t(read_buf[6] | (read_buf[7] << 8))); // note the polarity reversal: "forward" = "positive rpm"
        
        // process SpeedL (signed int16): left wheel speed in RPM
        ser_frame.l_rpm = int16_t(fwheel_orientation_) * int16_t(read_buf[8] | (read_buf[9] << 8));
        
        // swap left and right wheel RPM values if hoverboard was installed backwards
        if (fwheel_orientation_ == -1.0) 
        {
            std::swap(ser_frame.r_rpm, ser_frame.l_rpm);
        }

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
    RCLCPP_DEBUG(rclcpp::get_logger("serial_logger"), "Completed sc_read_front_wheels.");

    return ser_frame;
}

FeedbackFrame SerialCommunicator::sc_read_rear_wheels() 
{
    FeedbackFrame ser_frame;
    ser_frame.ts = std::chrono::steady_clock::now();
    bool valid_msg {false};
    int bytes_read {0};
    unsigned char read_buf [SERIAL_FEEDBACK_MESSAGE_SIZE] = {};
    try
    {
        bytes_read = read(this->rear_wheels_serial_fh_, &read_buf, sizeof(read_buf));
        if (bytes_read == -1) 
        {
            throw std::runtime_error("Error reading rear serial buffer.");
        }  
    }
    catch(const std::runtime_error& re)
    {
        RCLCPP_ERROR(rclcpp::get_logger("serial_logger"), "SerialCommunicator: Runtime Exception: %s", re.what());
    }

    // SERIAL DATA IS LITTLE-ENDIAN (LSB FIRST)
    
    // verify bytes_read == SERIAL_FEEDBACK_MESSAGE_SIZE
    // verify first 2 bytes are 0xABCD
    if ((bytes_read != SERIAL_FEEDBACK_MESSAGE_SIZE) | (read_buf[0] != 0xCD) | (read_buf[1] != 0xAB))
    {
        valid_msg = false;
        RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "Non-valid serial message from rear wheels: %d bytes read, 0x%2x 0x%2x header bytes", bytes_read, read_buf[0], read_buf[1]);
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
        ser_frame.steering = read_buf[2] | (read_buf[3] << 8);
        
        // process CMD2 (signed int16): speed or throttle
        ser_frame.speed = int16_t(rwheel_orientation_) *int16_t(read_buf[4] | (read_buf[5] << 8));
        
        // process SpeedR (signed int16): right wheel speed in RPM
        ser_frame.r_rpm = int16_t(rwheel_orientation_) *(-1* int16_t(read_buf[6] | (read_buf[7] << 8))); // note the polarity reversal: "forward" = "positive rpm"
        
        // process SpeedL (signed int16): left wheel speed in RPM
        ser_frame.l_rpm = int16_t(rwheel_orientation_) * int16_t(read_buf[8] | (read_buf[9] << 8));
        
        // swap left and right wheel RPM values if hoverboard was installed backwards
        if (rwheel_orientation_ == -1.0) 
        {
            std::swap(ser_frame.r_rpm, ser_frame.l_rpm);
        }

        // process Battery Voltage (signed int16): battery voltage x 100
        ser_frame.v_batt = ser_frame.convert_v_batt(read_buf[10], read_buf[11]);
        
        // process Temperature (signed int16): temperature in degrees C x 10
        ser_frame.temperature = ser_frame.convert_temp(read_buf[12], read_buf[13]);
        
        // process LED (unsigned int16): state of sideboard LEDs
        ser_frame.led_status = ((read_buf[14]) << 8) | read_buf[15];

        ser_frame.valid = true;

    }

    tcflush(rear_wheels_serial_fh_, TCIFLUSH);
    
    write(this->rear_wheels_serial_fh_, this->rear_wheels_command_, sizeof(this->rear_wheels_command_));
    // write(this->rear_wheels_serial_fh_, this->rear_wheels_command_, sizeof(this->rear_wheels_command_));
    RCLCPP_DEBUG(rclcpp::get_logger("serial_logger"), "Completed sc_read_rear_wheels.");

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
    unsigned char read_buf [SERIAL_FEEDBACK_MESSAGE_SIZE] = {};
    auto read_delay_duration = std::chrono::nanoseconds(100ms);
    auto sleep_duration = std::chrono::nanoseconds(1s);
    auto sync_delay_duration = std::chrono::nanoseconds(101ms);

    while (result == false)
    {
        try
        {
            write(this->front_wheels_serial_fh_, initial_command, sizeof(initial_command));
            rclcpp::sleep_for(read_delay_duration);
            bytes_read = read(this->front_wheels_serial_fh_, &read_buf, SERIAL_FEEDBACK_MESSAGE_SIZE);
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
            else if (bytes_read > 0 && bytes_read < SERIAL_FEEDBACK_MESSAGE_SIZE)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC front wheels initializing handshake: read incomplete message of %d bytes. Expected %d bytes... waiting 1 second", bytes_read, SERIAL_FEEDBACK_MESSAGE_SIZE);
                rclcpp::sleep_for(sleep_duration);
                tcflush(front_wheels_serial_fh_, TCIFLUSH);
                result = false;
            }
            else if (bytes_read == SERIAL_FEEDBACK_MESSAGE_SIZE && read_buf[0] != 0xCD && read_buf[1] != 0xAB)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC front wheels initializing handshake: successfully read feedback frame of %d bytes, but incorrect header. Raw frame: 0x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x.", bytes_read, read_buf[0], read_buf[1], read_buf[2], read_buf[3], read_buf[4], read_buf[5], read_buf[6], read_buf[7], read_buf[8], read_buf[9], read_buf[10], read_buf[11], read_buf[12], read_buf[13], read_buf[14], read_buf[15], read_buf[16], read_buf[17]);
                rclcpp::sleep_for(sync_delay_duration);
                tcflush(front_wheels_serial_fh_, TCIFLUSH);
                result = false;
            }
            else if (bytes_read == SERIAL_FEEDBACK_MESSAGE_SIZE && read_buf[0] == 0xCD && read_buf[1] == 0xAB)
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

bool SerialCommunicator::sc_initializing_handshake_rearwheels()
{
    bool result {false};
    unsigned char initial_command[8] {  0xCD, 0xAB,     // frame header start
                                        0x00, 0x00,     // steer command = 0
                                        0x00, 0x00,     // speed command = 0 
                                        0xCD, 0xAB};    // XOR checksum
    
    
    int bytes_read {0};
    unsigned char read_buf [SERIAL_FEEDBACK_MESSAGE_SIZE] = {};
    auto read_delay_duration = std::chrono::nanoseconds(100ms);
    auto sleep_duration = std::chrono::nanoseconds(1s);
    auto sync_delay_duration = std::chrono::nanoseconds(101ms);

    while (result == false)
    {
        try
        {
            write(this->rear_wheels_serial_fh_, initial_command, sizeof(initial_command));
            rclcpp::sleep_for(read_delay_duration);
            bytes_read = read(this->rear_wheels_serial_fh_, &read_buf, SERIAL_FEEDBACK_MESSAGE_SIZE);
            if (bytes_read < 0) 
            {
                throw std::runtime_error("Error reading rear serial buffer.");
            }  
            else if (bytes_read == 0)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC rear wheels initializing handshake: read 0 bytes... waiting 1 second");
                rclcpp::sleep_for(sleep_duration);
                result = false;
            }
            else if (bytes_read > 0 && bytes_read < SERIAL_FEEDBACK_MESSAGE_SIZE)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC rear wheels initializing handshake: read incomplete message of %d bytes. Expected %d bytes... waiting 1 second", bytes_read, SERIAL_FEEDBACK_MESSAGE_SIZE);
                rclcpp::sleep_for(sleep_duration);
                tcflush(rear_wheels_serial_fh_, TCIFLUSH);
                result = false;
            }
            else if (bytes_read == SERIAL_FEEDBACK_MESSAGE_SIZE && read_buf[0] != 0xCD && read_buf[1] != 0xAB)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC rear wheels initializing handshake: successfully read feedback frame of %d bytes, but incorrect header. Raw frame: 0x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x.", bytes_read, read_buf[0], read_buf[1], read_buf[2], read_buf[3], read_buf[4], read_buf[5], read_buf[6], read_buf[7], read_buf[8], read_buf[9], read_buf[10], read_buf[11], read_buf[12], read_buf[13], read_buf[14], read_buf[15], read_buf[16], read_buf[17]);
                rclcpp::sleep_for(sync_delay_duration);
                tcflush(rear_wheels_serial_fh_, TCIFLUSH);
                result = false;
            }
            else if (bytes_read == SERIAL_FEEDBACK_MESSAGE_SIZE && read_buf[0] == 0xCD && read_buf[1] == 0xAB)
            {
                RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "MC::SC rear wheels initializing handshake: successfully read feedback frame of %d bytes with correct header. Raw frame: 0x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x.", bytes_read, read_buf[0], read_buf[1], read_buf[2], read_buf[3], read_buf[4], read_buf[5], read_buf[6], read_buf[7], read_buf[8], read_buf[9], read_buf[10], read_buf[11], read_buf[12], read_buf[13], read_buf[14], read_buf[15], read_buf[16], read_buf[17]);
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

void SerialCommunicator::convert_int16_to_uchar_(int16_t int16_cmd, unsigned char* cmd_bytes)
{
    cmd_bytes[0] = int16_cmd;               // LSB of int16
    cmd_bytes[1] = int16_cmd >> 8;          // MSB of int16
}

void SerialCommunicator::set_front_steer(double st)
{
    // st is in units of rad/sec
    unsigned char new_steer[2] {0x00};
    st *= -fwheel_orientation_;
    st *= (30.0/3.1415926)*(fwheel_separation_cm_ / fwheel_diameter_cm_);
    int16_t st_int = static_cast<int16_t>(st);
    convert_int16_to_uchar_(st_int, new_steer);
    this->front_wheels_command_[2] = new_steer[0];  // LSB first
    this->front_wheels_command_[3] = new_steer[1];  // MSB second
    update_front_checksum();
}

void SerialCommunicator::set_rear_steer(double st)
{
    // st is in units of rad/sec
    unsigned char new_steer[2] {0x00};
    st *= rwheel_orientation_;
    st *= (30.0/3.1415926)*(rwheel_separation_cm_ / rwheel_diameter_cm_);
    int16_t st_int = static_cast<int16_t>(st);
    convert_int16_to_uchar_(st_int, new_steer);
    this->rear_wheels_command_[2] = new_steer[0];  // LSB first
    this->rear_wheels_command_[3] = new_steer[1];  // MSB second
    update_rear_checksum();
}

void SerialCommunicator::set_front_speed(double sp)
{
    // sp is in units of m/sec
    // new_speed is in units of RPM (aka - 2pi rad/min)
    unsigned char new_speed[2] {0x00};
    sp *= fwheel_orientation_; 
    sp *= (954.93 / fwheel_diameter_cm_);
    int16_t sp_int = static_cast<int16_t>(sp);
    convert_int16_to_uchar_(sp_int, new_speed);
    this->front_wheels_command_[4] = new_speed[0];  // LSB first
    this->front_wheels_command_[5] = new_speed[1];  // MSB second
    update_front_checksum();
}

void SerialCommunicator::set_rear_speed(double sp)
{
    // sp is in units of m/sec
    // New_speed is in units of RPM (rev/min)
    unsigned char new_speed[2] {0x00};
    sp *= rwheel_orientation_;
    sp *= (954.93 / rwheel_diameter_cm_);
    int16_t sp_int = static_cast<int16_t>(sp);
    convert_int16_to_uchar_(sp_int, new_speed);
    this->rear_wheels_command_[4] = new_speed[0];  // LSB first
    this->rear_wheels_command_[5] = new_speed[1];  // MSB second
    update_rear_checksum();
}

void SerialCommunicator::update_front_checksum()
{
    unsigned char checksum_lsb = front_wheels_command_[0]^front_wheels_command_[2]^front_wheels_command_[4];
    unsigned char checksum_msb = front_wheels_command_[1]^front_wheels_command_[3]^front_wheels_command_[5];
    front_wheels_command_[6] = checksum_lsb;
    front_wheels_command_[7] = checksum_msb;
    //RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "SerialCommunicator: Updated front_wheel command: %2x %2x   %2x %2x   %2x %2x   %2x %2x", front_wheels_command_[1], front_wheels_command_[0], front_wheels_command_[3], front_wheels_command_[2], front_wheels_command_[5], front_wheels_command_[4], front_wheels_command_[7], front_wheels_command_[6]);
}

void SerialCommunicator::update_rear_checksum()
{
    unsigned char checksum_lsb = rear_wheels_command_[0]^rear_wheels_command_[2]^rear_wheels_command_[4];
    unsigned char checksum_msb = rear_wheels_command_[1]^rear_wheels_command_[3]^rear_wheels_command_[5];
    rear_wheels_command_[6] = checksum_lsb;
    rear_wheels_command_[7] = checksum_msb;
    //RCLCPP_INFO(rclcpp::get_logger("serial_logger"), "SerialCommunicator: Updated rear_wheel command: %2x %2x   %2x %2x   %2x %2x   %2x %2x", rear_wheels_command_[1], rear_wheels_command_[0], rear_wheels_command_[3], rear_wheels_command_[2], rear_wheels_command_[5], rear_wheels_command_[4], rear_wheels_command_[7], rear_wheels_command_[6]);
}