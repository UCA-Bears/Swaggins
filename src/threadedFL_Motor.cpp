#include "vex.h"
#include "main.h"


using namespace vex;

//Variables

void threadedFL_Motor() {
    while(1) {
        FL_Motor.spin(fwd, AxisFwdDriveOut + AxisTurnDriveOut, pct);

        wait(5,msec);
    }

}