#include "vex.h"
#include "controller.h"
#include "usercontrol.h"
#include "robot-config.h"
using namespace vex;
using namespace std;

void baseControl()
{
    MotorChassisRF.spin(directionType::fwd, A3 - A4 - A1, percentUnits::pct);
    MotorChassisLF.spin(directionType::fwd, -A3 - A4 - A1, percentUnits::pct);
    MotorChassisLB.spin(directionType::fwd, -A3 + A4 - A1, percentUnits::pct);
    MotorChassisRB.spin(directionType::fwd, A3 + A4 - A1, percentUnits::pct);
}
void setFlyWheelSpeed(double speed)
{
    MotorFlywheel.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
}
void setIntakerSpeed(double speed)
{
    MotorIntaker.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
}
void liftControl()
{
    Piston_Trigger.set(true);
    wait(200, msec);
    Piston_Trigger.set(false);
    wait(200, msec);
}
void usercontrol(void)
{
    while (true)
    {
        if (A)
        {
            // MotorFlywheel.spin(vex::directionType::fwd, 54, vex::velocityUnits::pct);
            setFlyWheelSpeed(54);
        }
        if (B)
        {
            setFlyWheelSpeed(65);
            // MotorFlywheel.spin(vex::directionType::fwd, 65, vex::velocityUnits::pct);
        }
        if (Y)
        {
            setFlyWheelSpeed(0);
            // MotorFlywheel.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
        }
        if (R1)
        {
            setIntakerSpeed(100);
            // MotorIntaker.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        }
        if (L1)
        {
            liftControl();
        }
        baseControl();
        wait(20, msec); // Sleep the task for a short amount of time to
                        // prevent wasted resources.
    }
}