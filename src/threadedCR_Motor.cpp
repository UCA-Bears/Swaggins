#include "vex.h"
#include "main.h"


using namespace vex;

//Variables

void threadedCR_Motor() {
    while(1) {
        CR_Motor.spin(fwd, AxisFwdDriveOut - AxisTurnDriveOut, pct);

        wait(5,msec);
    }
}