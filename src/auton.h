#ifndef MY_AUTON_H
#define MY_AUTON_H

#include "main.h"
    //Auton Variables
        //All Measurements are in inches
        //SET THESE BASED ON BOT SPECIFICS
        static const int WHEELSIZE = 4; //Wheel Size in inches
        static const float BOTLENGTH = 14 + (10.0/16.0); //Track Width assumes a symetrical wheel placement
        static const float WHEELSPEED = 250;
        //SET THESE ABOVE CORRECTLY

        static const float PI = 3.14159;
        static const float WHEELCIRCUM = WHEELSIZE * PI; //Get how much distance is travelled per Revolution
        static const float BOTCIRCUM = BOTLENGTH * PI;

    //Functions
    void drive(int speed, float time);
    void drive(int speed, vex::distanceUnits distance);

    void turn(int speed, float time);
    void turn(int speed, vex::rotationUnits degr);

    void intake(float time);

#endif