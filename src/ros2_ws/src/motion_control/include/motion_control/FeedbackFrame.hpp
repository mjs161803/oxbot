#ifndef FF_H
#define FF_H

#include <vector>
#include <chrono>

class FeedbackFrame 
{
    public:

    std::vector<unsigned char> serial_msg;
    std::chrono::time_point<std::chrono::steady_clock> ts;

    private:

};

#endif
