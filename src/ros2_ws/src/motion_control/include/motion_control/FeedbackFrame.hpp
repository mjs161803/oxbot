#include <vector>
#include <chrono>

class FeedbackFrame 
{
    public:

    const std::vector<unsigned char> serial_frame;
    const std::chrono::time_point<std::chrono::steady_clock> ts;

    private:

};