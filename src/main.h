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
        extern motor FR_Motor; //Front Right Motor
        extern motor FL_Motor; //Front Left Motor
        extern motor BR_Motor; //Back Right Motor
        extern motor BL_Motor; //Back Left Motor
        extern motor CL_Motor; //Center Left Motor
        extern motor CR_Motor; //Center Right Motor
        extern motor Tail_Motor; //Tail Hitch Motor
        extern motor Cv_Motor; //Conveyer Motor
        extern motor LR_Motor; //Left Roller
        extern motor RR_Motor; //Right Roller

    //Motor Groups
        extern motor_group R_Motors; //Roller Motors
        extern motor_group RD_Motors; //Right Side Drive Motors
        extern motor_group LD_Motors; //Left Side Drive Motors
    //Sensors 
        extern rotation Tail_Sensor;
    //Variables
        extern double AxisFwdDriveOut; //To Send Forward Inputs too drive wheel Threads
        extern double AxisTurnDriveOut; //TO send stering inputs to drive wheel threads

        //All Speeds are in percent unless stated otherwise
        extern double Cv_Speed;  //Conveyer Speed
        extern double Tail_Speed; //Tail Speed 
        extern double R_Speed; //Roller Speed 

        

#endif