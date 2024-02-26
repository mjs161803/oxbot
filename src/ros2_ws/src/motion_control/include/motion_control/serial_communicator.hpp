#include <string>

class SerialCommunicator
{
    public:
    SerialCommunicator();                                           //default constructor
    SerialCommunicator(std::string, std::string);                   //paramaterized constructor
    SerialCommunicator(const SerialCommunicator&);                  //copy constructor
    SerialCommunicator& operator=(const SerialCommunicator&);       //copy assignment operator
    SerialCommunicator(SerialCommunicator&&) noexcept;              //move constructor
    SerialCommunicator& operator=(SerialCommunicator&&) noexcept;   //move assignment operator
    ~SerialCommunicator();                                          //destructor
    

    private:
    std::string front_wheels_serial_path_;
    std::string rear_wheels_serial_path_;
    int fh_;

};