#include "vex.h"
#include "main.h"


using namespace vex;

//Variables

void threadedCv() {
    //Variables
        Cv_Motor.setVelocity(Cv_Speed, pct);

    while(1){
        if(Controller1.ButtonR1.pressing()) {
            Cv_Motor.spin(fwd);

        } else if (Controller1.ButtonR2.pressing()) {
            Cv_Motor.spin(reverse);

        }
        else {
            Cv_Motor.stop(coast);
        }

    }


}