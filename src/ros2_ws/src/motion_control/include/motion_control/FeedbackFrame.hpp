#include <vector>
#include <chrono>

class FeedbackFrame 
{
    public:

    std::vector<unsigned char> serial_frame;
    std::chrono::time_point<std::chrono::steady_clock> ts;

    private:

};