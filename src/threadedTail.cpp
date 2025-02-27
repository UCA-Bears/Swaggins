#include "vex.h"
#include "main.h"

using namespace vex;

//Variables

void threadedTail() {
    //Variables
        double currentP;
        double low;
        double high;
        double turn;
        bool hitched = false;
        bool lock = false;
        double setP;  
    //Motor Brake
        Tail_Motor.setBrake(hold);
    while(1) {
        //Switch State
            if (Controller1.ButtonA.pressing() && lock == false) { 
                hitched = !hitched;
                lock = true; 
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
            currentP = Tail_Sensor.position(degrees);
            low = currentP - setP;
            high = 360 - setP + currentP;

            if (std::abs(low) > std::abs(high) ) {
                turn = high;
                
            } else {
                turn = low;

            }

        
        //Speed and Turning
            Controller1.Screen.print(hitched ? "Hitched = True   " : "Hitched = False   ");
            Controller1.Screen.setCursor(2,2);
            Tail_Motor.setVelocity(Tail_Speed, pct);

            turn = (turn * -1) /360;
            Tail_Motor.spinFor(turn, rev, false);

        
        
    wait(5,msec);
    }


}
