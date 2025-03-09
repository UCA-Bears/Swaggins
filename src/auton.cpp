#include "main.h"

void drive(int speed, float time) {

    BL_Motor.spin(fwd, speed, pct);
    FR_Motor.spin(fwd, speed, pct);
    FL_Motor.spin(fwd, speed, pct);
    BR_Motor.spin(fwd, speed, pct);
    wait(time, msec);
    BL_Motor.stop(hold);
    FR_Motor.stop(hold);
    FL_Motor.stop(hold);
    BR_Motor.stop(hold);

}

void drive(int speed, float distance) {
    float time;
    const int wheelSize = 4; //Wheel Size in inches
    const int wheelDiam = wheelSize * 3.14159; 






}

void turn(int speed, float time) {
    if (time > 0 ) { //Turn Right
        BL_Motor.spin(fwd, speed, pct);
        FR_Motor.spin(reverse, speed, pct);
        FL_Motor.spin(fwd, speed, pct);
        BR_Motor.spin(reverse, speed, pct);
        wait(time, msec);

    } else if ( time < 0) { //Turn Left
        BL_Motor.spin(reverse, speed, pct);
        FR_Motor.spin(fwd, speed, pct);
        FL_Motor.spin(reverse, speed, pct);
        BR_Motor.spin(fwd, speed, pct);
        wait(time * -1, msec);
    }
    BL_Motor.stop(hold);
    FR_Motor.stop(hold);
    FL_Motor.stop(hold);
    BR_Motor.stop(hold);

}

void intake(float time) {
    Cv_Motor.setVelocity(Cv_Speed, pct);
    Cv_Motor.spin(fwd);
    wait(time, msec);
    Cv_Motor.stop(hold); 
}