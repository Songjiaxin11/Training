#ifndef ROBOT_CONFIG_H_
#define ROBOT_CONFIG_H_
#include "vex.h"

using namespace vex;

extern brain Brain;

// Chassis motors: Left/Right Front/Back
extern motor MotorChassisLF;
extern motor MotorChassisRF;
extern motor MotorChassisLB;
extern motor MotorChassisRB;
extern motor MotorFlywheel;
extern motor MotorIntaker;
extern digital_out Piston_Trigger;
extern controller Controller;

extern inertial Inertial;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

#endif