#include "vex.h"
#include "functions.h"


using namespace vex;

//Variables

void threadedFL_Motor() {
    while(1) {
        FL_Motor.spin(fwd, AxisFwdDriveOut + AxisTurnDriveOut, pct);

        wait(5,msec);
    }

}