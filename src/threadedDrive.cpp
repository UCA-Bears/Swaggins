#include "vex.h"
#include "functions.h"


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
            AxisFwdDriveOut = FwdAxis;
            AxisTurnDriveOut = TurnAxis;


        wait(5,msec);
    }
}