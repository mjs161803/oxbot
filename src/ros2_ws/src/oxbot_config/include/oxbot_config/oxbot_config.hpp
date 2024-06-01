
/****************************
 * motion_control
****************************/

// Serial Port Configuration for current Oxbot hardware platform
#define MC_FRONT_WHEELS_SERIAL_PATH "/dev/rear-wheels"
#define MC_REAR_WHEELS_SERIAL_PATH "/dev/front-wheels"
#define MC_SERIAL_FEEDBACK_MESSAGE_SIZE 18 // the feedback message from the hoverboard controller is 144 bytes long 
#define MC_FRONT_WHEELS_INSTALL_ORIENTATION 1 // 1 for correct, -1 if hoverboard wheels were installed backwards
#define MC_REAR_WHEELS_INSTALL_ORIENTATION -1 // 1 for correct, -1 if hoverboard wheels were installed backwards
#define MC_FRONT_WHEEL_DIAMETER_CM 19.0
#define MC_REAR_WHEEL_DIAMETER_CM 24.5

// Timing configurations
#define MC_OUTPUT_FREQUENCY 2 // desired frequency of motion_controller output publisher, in Hz
#define MC_SERIAL_POLLING_FREQUENCY 100 // desired frequency pulling feedback data from the serial buffer file handle
