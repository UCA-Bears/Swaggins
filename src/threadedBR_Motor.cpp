#include "vex.h"
#include "functions.h"


using namespace vex;

//Variables

void threadedBR_Motor() {
    while(1) {
        BR_Motor.spin(fwd, AxisFwdDriveOut - AxisTurnDriveOut, pct);

        wait(5,msec);
    }
}