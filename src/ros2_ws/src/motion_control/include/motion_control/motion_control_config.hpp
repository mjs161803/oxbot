// Serial Port Configuration for current Oxbot hardware platform
#define FRONT_WHEELS_SERIAL_PATH "/dev/front-wheels"
#define REAR_WHEELS_SERIAL_PATH "/dev/rear-wheels"
#define SERIAL_FEEDBACK_MESSAGE_SIZE 144 // the feedback message from the hoverboard controller is 144 bytes long 

// Timing configurations
#define OUTPUT_FREQUENCY 2 # desired frequency of motion_controller output publisher, in Hz
#define SERIAL_POLLING_FREQUENCY 100 # desired frequency pulling feedback data from the serial buffer file handle
