
/****************************
 * motion_control
****************************/

// Serial Port Configuration for current Oxbot hardware platform
#define MC_FRONT_WHEELS_SERIAL_PATH "/dev/front-wheels"
#define MC_REAR_WHEELS_SERIAL_PATH "/dev/rear-wheels"
#define MC_SERIAL_FEEDBACK_MESSAGE_SIZE 144 // the feedback message from the hoverboard controller is 144 bytes long 

// Timing configurations
#define MC_OUTPUT_FREQUENCY 2 // desired frequency of motion_controller output publisher, in Hz
#define MC_SERIAL_POLLING_FREQUENCY 100 // desired frequency pulling feedback data from the serial buffer file handle
