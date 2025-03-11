#include "vex.h"
#include "main.h"


using namespace vex;

//Variables

void threadedR() {
    //Variables
        R_Motors.setVelocity(R_Speed, pct);

    while(1){
        if(Controller1.ButtonL1.pressing() || Controller1.ButtonR1.pressing()) {
            R_Motors.spin(fwd);

        } else if (Controller1.ButtonL2.pressing()) {
            R_Motors.spin(reverse);

        }
        else {
            R_Motors.stop(coast);
        }

    }


}