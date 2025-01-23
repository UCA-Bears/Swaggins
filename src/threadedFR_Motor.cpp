#include "vex.h"
#include "functions.h"


using namespace vex;

//Variables

void threadedFR_Motor() {
    while(1) {
        FR_Motor.spin(fwd, AxisFwdDriveOut - AxisTurnDriveOut, pct);

        wait(5,msec);
    }
}