// Time measurment struct
#include "t_data.h"

// include the register/pin definitions
#include "derivative.h"      /* derivative-specific definitions */


struct time {
    int add;
    int multiply;
    int divide;
    int sqrt;
    int sin;
    int cos;  
}