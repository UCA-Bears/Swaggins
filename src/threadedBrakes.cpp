#include "vex.h"
#include "main.h"

using namespace vex;

//Variables
    vex::brakeType brakeMode = brake; //Set Brake Type to all Drive Motors Values "coast" "brake" "hold"
     
void threadedBrakes() {
    //Motor Brake Mode
        FR_Motor.setBrake(brakeMode);
        FL_Motor.setBrake(brakeMode);
        BR_Motor.setBrake(brakeMode);
        BL_Motor.setBrake(brakeMode);
    
    while(1) {
        if (AxisFwdDriveOut == 0 && AxisTurnDriveOut == 0) {
            FR_Motor.stop();
            FL_Motor.stop();
            BR_Motor.stop();
            BL_Motor.stop();
        } 
    wait(5, msec);
    }
}