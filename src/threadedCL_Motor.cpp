#include "vex.h"
#include "main.h"


using namespace vex;

//Variables

void threadedCL_Motor() {
    while(1) {
        CL_Motor.spin(fwd, AxisFwdDriveOut + AxisTurnDriveOut, pct);

        wait(5,msec);
    }
}