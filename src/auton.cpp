#include "main.h"

void drive(int speed, float time) {
    if (time > 0 ) { //Drive Forward
        RD_Motors.spin(fwd, speed, pct);
        LD_Motors.spin(fwd, speed, pct);
        wait(time, msec);

    } else if ( time < 0) { //Drive Forward
        LD_Motors.spin(reverse, speed, pct);
        RD_Motors.spin(reverse, speed, pct);
        wait(time * -1, msec);
    }
    RD_Motors.stop(hold);
    LD_Motors.stop(hold);
}

void drive(int speed, vex::distanceUnits distance ) {
    float time; //Time to reach distance
    float wheelRPM = WHEELSPEED * (speed/100.0f); //Get the current wheel speed
    
    float distPerSec = (WHEELCIRCUM * wheelRPM) / 60.0f; //Get how much distance is traveled per second
    
    time = static_cast<float>(distance) / distPerSec; //Get time needed to travel X distance.

    time = time * 1000; //Convert to Msecs
    drive(speed, time);

}

void turn(int speed, float time) {
    if (time > 0 ) { //Turn Right
        LD_Motors.spin(fwd, speed, pct);
        RD_Motors.spin(reverse, speed, pct);
        wait(time, msec);

    } else if ( time < 0) { //Turn Left
        LD_Motors.spin(reverse, speed, pct);
        RD_Motors.spin(fwd, speed, pct);
        wait(time * -1, msec);
    }
    
    LD_Motors.stop(hold);
    RD_Motors.stop(hold);

}

void turn(int speed, vex::rotationUnits degr ) {
    float time; //Amount of time to turn to turn x degrees
    
    float wheelRPM = WHEELSPEED * (speed/100.0f); //Get the current wheel speed
    float distPerSec = (WHEELCIRCUM * wheelRPM) / 60.0f; //Get how much distance is traveled per second
    
    float rotationDistance = PI * (BOTCIRCUM / 2.0f) * (static_cast<float>(degr) / 360.0f);
    
    time = rotationDistance / distPerSec; 
    time = time * 1000; //Convert to Msecs
    //Negative time is left turn. Positive time is right turn 

    turn(speed, time);


}

void intake(float time) {
    Cv_Motor.setVelocity(Cv_Speed, pct);
    Cv_Motor.spin(fwd);
    wait(time, msec);
    Cv_Motor.stop(hold); 
}