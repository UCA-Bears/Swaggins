#include "vex.h"
#include "functions.h"


using namespace vex;

//Variables

void threadedBL_Motor() {
    while(1) {
        BL_Motor.spin(fwd, AxisFwdDriveOut + AxisTurnDriveOut, pct);

        wait(5,msec);
    }
}