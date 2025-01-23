/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Melfely                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    12, 19, 11, 18  
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "cmath"

using namespace vex;
using namespace std;
// A global instance of competition 
  competition Competition;
//Core Motors
  motor IN_Motor = motor(PORT12); //Intake
  motor FP_Motor = motor(PORT14, true); //Flipper
  motor SS_Motor = motor(PORT3, ratio6_1, true); //Shooter
  motor ER_Motor = motor(PORT20); //Endgame Right
  motor EL_Motor = motor(PORT11, true); //Endgame left

//Motor Groups
  //4 Wheel Motors
  //Motor naming is as follows Front = F || B = Back & Left = L || Right = R
  motor FR_Motor = motor(PORT8, true);
  motor FL_Motor = motor(PORT2);
  motor BR_Motor = motor(PORT10, true);
  motor BL_Motor = motor(PORT1);
  //Endgame 
    motor_group EG_Motor = motor_group(ER_Motor, EL_Motor);
//Sensors
  rotation FP_Sensor = rotation(PORT13);
//Anntena 21

//Drivetrain
  motor leftMotorA = motor(PORT2, ratio18_1, false);
  motor leftMotorB = motor(PORT1, ratio18_1, false);
  motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
  motor rightMotorA = motor(PORT8, ratio18_1, true);
  motor rightMotorB = motor(PORT10, ratio18_1, true);
  motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
  drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 320, 360, 285, mm, 1);
//Controller
  controller Controller1 = controller(primary);
//Global Varibles
  //double Axis3drive = 0;
  double Axis3driveOut;
  double Axis1driveOut;
  double Axis4driveOut;
  bool shooterToggle = false;
  bool speedHigh = false;
  double gear = 2; 
  
void pre_auton(void) {  
  vexcodeInit();
  IN_Motor.setVelocity(100,pct);
  EG_Motor.stop(hold); 

}

//Auton Functions
  void DriveFwd(double Ddistance, double speed) {
      Drivetrain.setDriveVelocity(speed, pct);
      Drivetrain.driveFor(forward, Ddistance, mm, true);
    
  } 
 
  
  void DriveRev(double Ddistance, double speed) {
      Drivetrain.setDriveVelocity(speed, pct);
      Drivetrain.driveFor(reverse, Ddistance, mm, true );

  }

  void DriveTime(double time, double speed) {
    Drivetrain.setDriveVelocity(speed, pct);
    Drivetrain.drive(fwd);
    wait(time, msec);
    Drivetrain.stop(brake);

  }

  void RotateAmount(double rotateD, double speed) {
    Drivetrain.setTurnVelocity(speed, pct);
    Drivetrain.turnFor(rotateD, degrees, true);

  }

  void RollerFwd(double revs){
    IN_Motor.spinFor(fwd, revs, rev);


  }
  
  void RollerRev(double time) {
    IN_Motor.spin(reverse);
    wait(time, msec);
    IN_Motor.stop();

  }

  void ShooterOn() {
    SS_Motor.setVelocity(50, pct);
    SS_Motor.spin(fwd);
    wait(3, sec);

  } 
  
  void ShooterOff() {
    SS_Motor.stop(brake);

  }


void autonomous(void) {
/*//Test 1
    DriveFwd(450, 75);
    RotateAmount(-80, 75);
    DriveTime(900, -75);
    RotateAmount(20, 75);
    DriveTime(700, -75);
    RollerFwd(.8);
    DriveFwd(125, 75);
    RotateAmount(70, 75); 
    ShooterOn();
    RollerFwd(10);
    ShooterOff();



*/
  //Test 2
    DriveTime(250, -100);
    RollerFwd(1);
    DriveTime(250, 100);
  



/*  //Test 3
    DriveFwd(900, 100);
    RollerRev(2000);
    DriveRev(200, 75);
*/
}


void threadedBrake () {//Allows for Snappy Stopping
  while(1) {
    //Axis Varibles 
      double Axis3 = Controller1.Axis3.position();//These are set here to be multipled by arbitrary values to prevent stick inputs in certain directions from causing even canceling  
      double Axis1 = Controller1.Axis1.position()*2;//Mutlipled by 2 to prevent Canceling
      double Axis4 = Controller1.Axis4.position()*3;//Multipled by 3 to prevent Canceling
    //Brakes
      if (Axis3 + Axis1 + Axis4 == 0) {//Just Stopping Motors when no drive input
        FR_Motor.stop(hold);
        FL_Motor.stop(hold);
        BR_Motor.stop(hold); 
        BL_Motor.stop(hold);
        
      }
  wait(0.1,msec);
  }
}

void threadedDrive () {
  //AxisDrive Variables
    double Axis3Drive;
    double Axis1Drive;
    double Axis4Drive;
  while(1) {
    //Controller Axis setting
      double Axis3 = Controller1.Axis3.position();//Forward
      double Axis1 = Controller1.Axis1.position() * 0.1;//Turning
      double Axis4 = Controller1.Axis4.position();//Strafing
    
    //Axis1
      Axis1Drive = Axis1 * abs(Axis1);

      if (Axis3 != 0 || Axis4 != 0) { //Reduce Steering Fwd
        Axis1driveOut = Axis1Drive * 0.75;

      }
      else { //Full Steering when no Forward/Strafing input
        Axis1driveOut = Axis1Drive;

      }
    //Axis3
      Axis3Drive = Axis3;
      Axis3driveOut = Axis3Drive;
    //Axis 4
      Axis4Drive = Axis4;

      if(Axis3 != 0) {
        Axis4driveOut = Axis4Drive * 0.5;

      }
      else {
        Axis4driveOut = Axis4Drive;

      }
      
  wait(5,msec);
  }
}

void threadedIntake(void) {
  //Variables
    IN_Motor.setVelocity(100,pct);
  while(1) {
    //Intake
      if (Controller1.ButtonR1.pressing()) {
        IN_Motor.spin(fwd); //Collect

      }
      else 
      if(Controller1.ButtonR2.pressing()) {
        IN_Motor.spin(reverse); //Uncollect 

      }
      else 
      { 
        IN_Motor.stop(hold); //Stop
        
      }
    
  }
}

void threadedShooter(void) {
  //Variables
    SS_Motor.setVelocity(75,pct);
  while(1) {
    //Variables
      

    //Manual Controller of spin and auto control
      if(Controller1.ButtonL1.pressing() || shooterToggle == true) {
        SS_Motor.spin(fwd);

      }
      else
      if (Controller1.ButtonL2.pressing() && shooterToggle == false) {
        SS_Motor.spin(reverse);

      }
      else{
        SS_Motor.stop(brake);
      }
      

  wait(10,msec);
  }
}

void threadedFlipper(void) {
  //Variables
    FP_Motor.setVelocity(100,pct);
    bool flip = false;
    FP_Motor.setPosition(FP_Sensor.position(deg), deg);
    
  while(1){
    //Variables 
      
    //Auto Flipping
      if (Controller1.ButtonB.pressing()) {
        flip = true;
      }

      while(flip == true) {
        
        //Flip Disk Into
          FP_Motor.spinTo(225, deg, true);
        //Reset Flipper
          FP_Motor.spinTo(200, deg, true);
        //Turn of Flipper Unless Button Held
          if(!Controller1.ButtonB.pressing()) {
            flip = false;
            
          }
      wait(250,msec);
      }

  wait(10,msec);
  }
}

void threadedPrinting () {
  //Variables

  while(1) {
    //Variables 
      double shooterEfficiency;
      double shooterTemp;
      
    //Printing to Brain

      shooterEfficiency = SS_Motor.efficiency(pct);
      shooterTemp = SS_Motor.temperature(celsius);
       

      Brain.Screen.clearScreen();
      Brain.Screen.printAt(2, 20,"SS Motor Effeciency %f", shooterEfficiency);
      Brain.Screen.printAt(2, 40,"SS Motor Temp %f", shooterTemp);
      Brain.Screen.printAt(2, 60, "SS Motor Speed %f", round(SS_Motor.velocity(rpm) * 6) );

      Brain.Screen.printAt(2, 80,"BRD Motor Temp %f", BR_Motor.temperature(celsius));
      Brain.Screen.printAt(2, 100, "BRD Motor Effeciency %f", BR_Motor.efficiency(pct) );

      Brain.Screen.printAt(2, 120, "BLD Motor Temp %f", BL_Motor.temperature(celsius) );
      Brain.Screen.printAt(2, 140, "BLD Motor Effeciency %f", BL_Motor.efficiency(pct) );

      Brain.Screen.printAt(2, 160, "FRD Motor Temp %f", FR_Motor.temperature(celsius) );
      Brain.Screen.printAt(2, 180, "FRD Motor Effeciency %f", FR_Motor.efficiency(pct) );

      Brain.Screen.printAt(2, 200, "FLD Motor Temp %f", FL_Motor.temperature(celsius) );
      Brain.Screen.printAt(2, 220, "FLD Motor Temp %f", FL_Motor.efficiency(pct) );

    //Printing to controller
      Controller1.Screen.print("Current Gear: %f", gear);
      Controller1.Screen.setCursor(2,2);
      
  wait(100, msec);
  }
}

void threadedControls () {
  //Variables
    bool shooterLatch = false;
    bool shooterToggleOpen = false;
    bool gearLatch = false;
    double shooterSetSpeed = 0;
    
    EG_Motor.setVelocity(100, pct);
  while(1) {
    //Variables
    
    //Shooter Toggle
      if (Controller1.ButtonA.pressing() ){
        shooterToggleOpen = true;

      } 


      if (shooterToggleOpen == true) {
        if (shooterLatch == false) {
          shooterToggle = !shooterToggle;
          shooterLatch = true;
          
        }
        if(!Controller1.ButtonA.pressing() ) {
          shooterToggleOpen = false;

        }
      }
      else {
        shooterLatch = false;

      }
  
    //Shooter Gear Selection
      if (Controller1.ButtonUp.pressing()){
        if(gearLatch == false){
          if (gear < 3){//Check to make sure not over max gear

            gear = gear + 1;

          }
          gearLatch = true;
        }
      }
      else 
      if (Controller1.ButtonDown.pressing()) {
        if(gearLatch == false){
          if (gear > 1){//Check to make sure not under mini gear

            gear = gear - 1;

          }
          gearLatch = true;
        }
      }
      else {
        gearLatch = false;
      }


    //Speed Shooter Gear Setting
      if ((SS_Motor.velocity(rpm) * 6) < shooterSetSpeed - (shooterSetSpeed * .10) ){
        double speed = 100;
        SS_Motor.setVelocity(speed, pct);

      }
      else
      if (gear == 3) {
        double speed = 100;
        SS_Motor.setVelocity(speed, pct);
        shooterSetSpeed = 3600 * (speed/100);  
         
      }
      else 
      if (gear == 2) {
        double speed = 75;
        SS_Motor.setVelocity(speed, pct);
        shooterSetSpeed = 3600 * (speed/100);

      }
      else 
      if (gear == 1) {
        double speed = 60;
        SS_Motor.setVelocity(speed, pct);
        shooterSetSpeed = 3600 * (speed/100);

      }

    //Endgame
      if (Controller1.ButtonX.pressing() ) {
        EG_Motor.spin(fwd);

      }
      else 
      if (Controller1.ButtonY.pressing() ) {
        EG_Motor.spin(reverse);

      }
      else {
        EG_Motor.stop(hold);

      }
    
  wait(10, msec);
  } 
}

void threadedFR_Motor() {
  //Variables

  while(1) {
    //Drive
      //Drive Movement which actually spins the motors
      //Motors are setup under this system
      //XY_Motor.spin(Fwd, ForwardAxis +||- TurningAxis +||- StrafingAxis, pct);
      FR_Motor.spin(fwd, Axis3driveOut - Axis1driveOut - Axis4driveOut, pct);


  wait(10, msec);
  }
}

void threadedFL_Motor(){
  //Variables
  
  while(1){
    //Drive
      //Drive Movement which actually spins the motors
      //Motors are setup under this system
      //XY_Motor.spin(Fwd, ForwardAxis +||- TurningAxis +||- StrafingAxis, pct);
      FL_Motor.spin(fwd, Axis3driveOut + Axis1driveOut + Axis4driveOut, pct);

  wait(10, msec);
  }
}

void threadedBR_Motor() {
  //Variables
  
  while(1) {
    //Drive
      //Drive Movement which actually spins the motors
      //Motors are setup under this system
      //XY_Motor.spin(Fwd, ForwardAxis +||- TurningAxis +||- StrafingAxis, pct);
      BR_Motor.spin(fwd, Axis3driveOut - Axis1driveOut + Axis4driveOut, pct);

  wait(10, msec); 
  }
}

void threadedBL_Motor() {
  //Variables

  while(1) {
    //Drive
      //Drive Movement which actually spins the motors
      //Motors are setup under this system
      //XY_Motor.spin(Fwd, ForwardAxis +||- TurningAxis +||- StrafingAxis, pct);
      BL_Motor.spin(fwd, Axis3driveOut + Axis1driveOut - Axis4driveOut, pct);

  wait(10, msec);
  }
}


void usercontrol(void) {
  //Threads
    thread ThreadBrake = thread(threadedBrake);
    thread ThreadDrive = thread(threadedDrive);
    thread ThreadIntake = thread(threadedIntake);
    thread ThreadFlipper = thread(threadedFlipper);
    thread ThreadShooter = thread(threadedShooter);
    thread ThreadPrinting = thread(threadedPrinting);
    thread ThreadControls = thread(threadedControls);
    thread ThreadFR_Motor = thread(threadedFR_Motor);
    thread ThreadFL_Motor = thread(threadedFL_Motor);
    thread ThreadBR_Motor = thread(threadedBR_Motor);
    thread ThreadBL_Motor = thread(threadedBL_Motor);
    //thread ThreadAcceleration = thread(threadedAcceleration);

  while (1) {
      
  wait(10, msec);               
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}