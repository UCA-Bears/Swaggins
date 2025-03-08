#include "vex.h"
#include "main.h"


using namespace vex;

//Variables 
    double AxisFwdDriveOut = 0;
    double AxisTurnDriveOut = 0;

void threadedDrive() {
    
    while(1) {
        //Controller Values
            double FwdAxis = Controller1.Axis3.position();
            double TurnAxis = Controller1.Axis1.position();
        //Temp Direct Drive

        if (TurnAxis >  80 || TurnAxis < -80) {
            AxisFwdDriveOut = FwdAxis;
            AxisTurnDriveOut = 2*TurnAxis;
        } else {
            AxisFwdDriveOut = FwdAxis;
            AxisTurnDriveOut = (1.25)*TurnAxis;
        }
            


        wait(5,msec);
    }
}