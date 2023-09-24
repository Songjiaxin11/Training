#include "vex.h"
#include "robot-config.h"
using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller = controller(primary);
motor Motor_BaseLF = motor(PORT9, ratio6_1, true);
motor Motor_BaseLB = motor(PORT1, ratio6_1, true);
motor Motor_BaseLM = motor(PORT2, ratio6_1, false);
motor Motor_BaseRF = motor(PORT12, ratio6_1, false);
motor Motor_BaseRB = motor(PORT14, ratio6_1, false);
motor Motor_BaseRM = motor(PORT13, ratio6_1, true);
// motor Motor_IntakerF = motor(PORT17, ratio6_1, false);
// motor Motor_IntakerB = motor(PORT18, ratio6_1, true);
// motor Motor_ShooterF = motor(PORT4, ratio6_1, false);
// motor Motor_ShooterB = motor(PORT5, ratio6_1, true);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}