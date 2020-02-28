/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Arduino.h>  
#include <Servo.h>
#include "Button.h"

Servo servoAir;  // create servo object to control a servo
Servo servoPbs;
// twelve servo objects can be created on most boards
Button buttonAir(7);
Button buttonPbs(8);

int posAir = 0;    // variable to store the servo position
int posPbs = 0;

void setup() {
  servoAir.attach(9);  // attaches the servo on pin 9 to the servo object
  servoPbs.attach(10);
}

void loop() {

  if (buttonAir.isPressed() == 1) {
    if (posAir == 0) {
      posAir = 90;
      servoAir.write(posAir);
    } else if (posAir == 90) {
      posAir = 0;
      servoAir.write(posAir);
    }
  }

  if (buttonPbs.isPressed() == 1) {
    if (posPbs == 0) {
      posPbs = 90;
      servoPbs.write(posPbs);
    } else if (posPbs == 90) {
      posPbs = 0;
      servoAir.write(posPbs);
    }
  }
 
}

