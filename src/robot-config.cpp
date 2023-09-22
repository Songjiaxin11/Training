#include "vex.h"
using namespace vex;
brain Brain;                                 // This is the brain
controller Controller = controller(primary); // This is the controller
motor MotorChassisRF  = motor(PORT7, ratio18_1, true);
motor MotorChassisLF  = motor(PORT8, ratio18_1, true);
motor MotorChassisLB  = motor(PORT18, ratio18_1, true);
motor MotorChassisRB  = motor(PORT9, ratio18_1, true);
inertial Inertial = inertial(PORT3);