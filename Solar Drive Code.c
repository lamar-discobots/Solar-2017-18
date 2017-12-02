#pragma config(Motor,  port2,           right1,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           liftR,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           liftL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           left1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           left2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           right2,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           claw,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
//fdsjbahkgfasdjhkyrfkjsdgf
void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	motor [liftL] = 127;
	motor [liftR] = 127;
	wait (1.0);
	motor [liftL] = 20;
	motor [liftR] = 20;
	//lift up for 1 seconds       change off 20 b/c motor burnout?

	motor [left1] = 127;
	motor [left2] = 127;
	motor [right1] = 120;
	motor [right2] = 120;
	wait (2.3);
	motor [left1] = 0;
	motor [left2] = 0;
	motor [right1] = 0;
	motor [right2] = 0;
	//move forward  cm

	motor [liftL] = -110;
	motor [liftR] = -110;
	wait (0.4);
	motor [liftL] = 0;
	motor [liftR] = 0;

	//lift down for .4 seconds

	motor [claw] = -127;
	wait (0.5);
	motor [claw] = 0;
	// open claw


 motor [left1] = -127;
 motor [left2] = -127;
 wait (2.0);

 motor [left1] = -127;
 motor[left2] = -127;
 motor [right1] = -127;
 motor [right2] = -127;
 wait (2.0);

 motor [left1] = 0;
 motor[left2] = 0;
 motor [right1] = 0;
 motor [right2] = 0;
}

  // ..........................................................................
  	/*
	motor [left1] = 127;
	motor [left2] = 127;
	motor [right1] = 127;
	motor [right2] = 127;
	wait(8);
	motor [left1] = 0;
	motor [left2] = 0;
	motor [right1] = 0;
	motor [right2] = 0;
} */
  // ..........................................................................

  // Remove this function call once you have "real" code.
  //AutonomousCodePlaceholderForTesting();
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  while (true){
  	int leftside=vexRT (Ch3);
  	int rightside=vexRT (Ch2);
  	int liftup=vexRT (Btn6U);
  	int liftdown=vexRT (Btn6D);
  	int clawopen=vexRT (Btn5U);
  	int clawclose=vexRT (Btn5D);

  	  ///// Left Wheels /////
  	if (leftside >=10){
  		motor [left1] = leftside;
  	  motor [left2] = leftside;
  	}

  	else if (leftside <=-10){
  		motor [left1] = leftside;
  		motor [left2] = leftside;
  	}

  	else {
  		motor [left1] = 0;
  		motor [left2] = 0;
  	}
  	   ///// Right Wheels /////
  	  if (rightside >= 10){

  		motor [right1] = rightside;
  		motor [right2] = rightside;
  	}

  	else if (rightside <= -10){
  		motor [right1] = rightside;
  		motor [right2] = rightside;
  	}

  else {
  		motor [right1] = 0;
  		motor [right2] = 0;
  	}
     /////Lift/////

  	if (liftup == 1){
  		motor [liftL] = 127;
  		motor [liftR] = 127;
  		}

  	else if (liftdown == 1){
  		motor [liftL] = -127;
  		motor [liftR] = -127;
  		}

  	else{
  		motor [liftL] = 0;
  		motor [liftR] = 0;
  		}

  		/////Claw/////

  		if (clawopen == 1)
  			motor [claw] = 127;

  		else if (clawclose == 1)
 				motor [claw] = -127;

  		else
  			motor [claw] = 0;


    // This is the main execution loop for the user control program.
   // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    // UserControlCodePlaceholderForTesting();
  }
}
