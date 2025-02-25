#include "vex.h"
#include "functions.h"
#include <cmath>

using namespace vex;

//Variables

void spinFor(double time) {
    
        
    if (time > 0) {
        Tail_Motor.spin(fwd, Tail_Speed, pct);
        wait(time, msec);
        Tail_Motor.stop(hold);


    } else if(time < 0) {
        time = time * -1;
        Tail_Motor.spin(reverse, Tail_Speed, pct);
        wait(time, msec);
        Tail_Motor.stop(hold);
    }


}

void threadedTail() {
    //Variables
        double currentP;
        double low;
        double high;
        double turn;
        bool hitched = false;
        bool lock = false;
        double setP;
        double turnTime;  
        double degPS;
        
    //Motor Brake
        Tail_Motor.setBrake(hold);
        Controller1.Screen.print(hitched ? "Hitched = True   " : "Hitched = False   ");
    while(1) {
        //Switch State
            if (Controller1.ButtonA.pressing() && lock == false) { 
                hitched = !hitched;
                lock = true; 
                Controller1.Screen.print(hitched ? "Hitched = True   " : "Hitched = False   ");
            } else if (!Controller1.ButtonA.pressing() ) {
                lock = false;

            }
        
        //Set Point
            if (hitched == false) {
                setP = 151;

            } else if (hitched == true) {
                setP = 166;

            }

        //Which Direction to Turn
            currentP = Tail_Sensor.position(deg);
            low = currentP - setP;
            high = 360 - setP + currentP;

            if (std::abs(low) > std::abs(high) ) {
                turn = high;
                
            } else {
                turn = low;

            }

        
        //Speed and Turning
            Controller1.Screen.setCursor(2,2);
            Tail_Motor.setVelocity(Tail_Speed, pct);
            turn = (turn * -1);
            degPS = 25 * 60; 

            turnTime = (turn / degPS) * 1000;
            spinFor(turnTime);

        
    wait(1,msec);
    }


}
