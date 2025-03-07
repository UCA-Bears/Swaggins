//Main header file connecting all other header files to the same includes and to main.cpp

#ifndef MY_MAIN_H
#define MY_MAIN_H

    #include "vex.h"
    #include "functions.h"
    #include "auton.h"
    #include <cmath>
    using namespace vex;

    //Controller
        extern controller Controller1;
    //Motors
        extern motor FR_Motor;
        extern motor FL_Motor;
        extern motor BR_Motor;
        extern motor BL_Motor;
        extern motor CL_Motor;
        extern motor CR_Motor;
        extern motor Tail_Motor;
        extern motor Cv_Motor;
    //Sensors 
        extern rotation Tail_Sensor;
    //Variables
        extern double AxisFwdDriveOut;
        extern double AxisTurnDriveOut;
        extern double Cv_Speed; 
        extern double Tail_Speed;

#endif