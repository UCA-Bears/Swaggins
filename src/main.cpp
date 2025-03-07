/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Melfely                                                   */
/*    Created:      10/31/2024, 1:09:43 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "main.h"

using namespace vex;

// A global instance of competition
competition Competition;

//Controller
  controller Controller1 = controller();

//Motors 
  motor FR_Motor = motor(PORT2);
  motor FL_Motor = motor(PORT9, true);
  motor BR_Motor = motor(PORT10);
  motor BL_Motor = motor(PORT1, true);
  motor CL_Motor = motor(PORT8);
  motor CR_Motor = motor(PORT18, true);
  motor Tail_Motor = motor(PORT20, true);
  motor Cv_Motor = motor(PORT3);
//Sensors
  rotation Tail_Sensor = rotation(PORT19);
// Variables
  double Cv_Speed = 100;
  double Tail_Speed = 100;


void pre_auton(void) {

  
}



void autonomous(void) {
  
}



void usercontrol(void) {
  thread threadDrive = thread(threadedDrive);
  thread threadBrakes = thread(threadedBrakes);
  thread threadFR_Motor = thread(threadedFR_Motor);
  thread threadFL_Motor = thread(threadedFL_Motor);
  thread threadBR_Motor = thread(threadedBR_Motor);
  thread threadBL_Motor = thread(threadedBL_Motor);
  thread threadCR_Motor = thread(threadedCR_Motor);
  thread threadCL_Motor = thread(threadedCL_Motor);
  thread threadTail = thread(threadedTail);
  thread threadCv = thread(threadedCv); 

  while (1) {
    

    wait(10, msec); 

  }
}


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
