// https://lastminuteengineers.com/stepper-motor-l298n-arduino-tutorial/


 // Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution =200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void motorInit() {
	// set the speed at 60 rpm:
	myStepper.setSpeed(180);
}








void spinMotor(bool clockwise, int step) 
{
  if (clockwise){
    myStepper.step(step);
  }
  else{
    myStepper.step(-step);
  }

}
