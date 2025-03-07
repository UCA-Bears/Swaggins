#ifndef MY_AUTON_H
#define MY_AUTON_H

#include "main.h"
void drive(int speed, float time);
void drive(int speed, float distance);

void turn(int speed, float time);
void turn(int speed, vex::rotationUnits degr);

void intake(float time);

#endif