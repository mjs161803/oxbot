#include "FeedbackFrame.hpp"
#include "chrono"


FeedbackFrame::FeedbackFrame()
{
    valid = false;
    steering = 0;
    speed = 0;
    r_rpm = 0;
    l_rpm = 0;
    v_batt = 0;
    temperature = 0;
    led_status = 0;
    ts =  std::chrono::steady_clock::now();
} 

signed int FeedbackFrame::convert_v_batt(unsigned char lsb, unsigned char msb)
{
    signed int voltage = msb;
    voltage <<= 8;
    voltage |= lsb;
    voltage /= 100;

    return voltage;
}

signed int FeedbackFrame::convert_temp(unsigned char lsb, unsigned char msb)
{
    signed int t = msb;
    t <<= 8;
    t |= lsb;
    t /= 10;
    t = (t * 1.8)+32;

    return t;
}