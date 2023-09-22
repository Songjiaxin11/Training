/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       86131                                                     */
/*    Created:      9/22/2023, 7:44:21 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include <iostream>

#include "robot-config.h"
using namespace std;
using namespace vex;
// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void)
{
  // ..........................................................................
  // Insert autonomous user code here.
  MotorChassisRF.spinFor(directionType::fwd, 1000, msec, 50, velocityUnits::pct);
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void)
{
  // User control code here, inside the loop

  while (1)
  {
    int a1 = Controller.Axis1.position(percentUnits::pct);
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("Axis 1=%d", a1);
    MotorChassisRF.spin(directionType::fwd, a1, percentUnits::pct);
    MotorChassisLF.spin(directionType::fwd, a1, percentUnits::pct);
    MotorChassisLB.spin(directionType::fwd, a1, percentUnits::pct);
    MotorChassisRB.spin(directionType::fwd, a1, percentUnits::pct);
    // MotorRF.spinFor(directionType::fwd, 1000, msec, 50, velocityUnits::pct);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("MotorRF=%lf,MotorLF=%lf", MotorChassisRF.position(rotationUnits::deg),MotorChassisLF.position(rotationUnits::deg));
    double heading = Inertial.heading(rotationUnits::deg);
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("heading=%lf", heading);
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  cout << "This must be the last time" << endl;
  Inertial.calibrate();
  waitUntil(!Inertial.isCalibrating());
  this_thread::sleep_for(200);
  cout << "calibrated!" << endl;
  Controller.Screen.setCursor(5, 1);
  Controller.Screen.print("         calibrated!");
  Brain.Screen.setCursor(1, 1); // 确定在brain屏幕上的输出坐标
  Brain.Screen.print("Welcome to the wonderful world of VEX!");
  Controller.Screen.setCursor(2, 1); // 确定在controller屏幕上的输出坐标
  Controller.Screen.print("Get Started");

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {

    wait(100, msec);
  }
}
