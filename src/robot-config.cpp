#include "vex.h"

using namespace vex;

brain Brain;
inertial Inertial = inertial(PORT3);
motor MotorChassisLF = motor(PORT8, ratio18_1, true);
motor MotorChassisRF = motor(PORT7, ratio18_1, true);
motor MotorChassisLB = motor(PORT18, ratio18_1, true);
motor MotorChassisRB = motor(PORT9, ratio18_1, true);
motor MotorFlywheel = motor(PORT11, ratio18_1, true);
motor MotorIntaker = motor(PORT16, ratio18_1, true);
digital_out Piston_Trigger = digital_out(Brain.ThreeWirePort.A);
controller Controller = controller(primary);


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
    // Nothing to initialize
}