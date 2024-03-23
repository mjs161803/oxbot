#ifndef FF_H
#define FF_H

#include <vector>
#include <chrono>

class FeedbackFrame 
{
    public:
    FeedbackFrame();
    bool valid;
    signed int steering;
    signed int speed;
    signed int r_rpm;
    signed int l_rpm;
    signed int v_batt;
    signed int temperature;
    unsigned int led_status;
    std::chrono::time_point<std::chrono::steady_clock> ts;

    signed int convert_v_batt(unsigned char, unsigned char);
    signed int convert_temp(unsigned char, unsigned char);
    
    private:

};

#endif
