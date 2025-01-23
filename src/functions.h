#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

    #include "vex.h"
    using namespace vex;

    //Controller
        extern controller Controller1;
    //Motors
        extern motor FR_Motor;
        extern motor FL_Motor;
        extern motor BR_Motor;
        extern motor BL_Motor;
        extern motor Tail_Motor;
        extern motor Cv_Motor;
    //Sensors 
        extern rotation Tail_Sensor;
    //Variables
        extern double AxisFwdDriveOut;
        extern double AxisTurnDriveOut;
        extern double Cv_Speed; 


void threadedDrive();

void threadedBrakes();

void threadedFR_Motor();

void threadedFL_Motor();

void threadedBR_Motor();

void threadedBL_Motor();

void threadedTail();

void threadedCv(); 


#endif