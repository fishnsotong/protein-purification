#include <Arduino.h>  
#include <Servo.h>
#include "Button.h"

Servo servoPbsAir;
Servo servoPbsToggle;
Servo ImidAir;
Servo servoImidToggle;

int controls[] = {7, 6, 5};

int posPbsAir = 0;    // immediately sucks Pbs up when turned on
int posPbsToggle = 135;

int testLight = 13;

void setup() {

  for (int a = 0; a < 3; a++) {
    pinMode(controls[a], INPUT);
  }

  servoPbsAir.attach(9);  // attaches the servo on pin 9 to the servo object
  servoPbsToggle.attach(10);

  pinMode(testLight, OUTPUT);
  digitalWrite(testLight, LOW);
}

void loop() {

  if (digitalRead(controls[0]) == HIGH) {
    digitalWrite(testLight, HIGH);

    // creating negative pressure in the well
    for (posPbsAir = 0; posPbsAir <= 90; posPbsAir += 1) {
      servoPbsAir.write(posPbsAir);
      delay(15);
    }
    for (posPbsToggle = 135; posPbsToggle >= 90; posPbsToggle -= 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    }
    // yes, it takes that long to dispense through the column
    delay(15000);

    for (posPbsToggle = 90; posPbsToggle <= 135; posPbsToggle += 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    }
    for (posPbsAir = 90; posPbsAir >= 0; posPbsAir -= 1) {
      servoPbsAir.write(posPbsAir);
      delay(15);
    }
    digitalWrite(testLight, LOW);

  } else if (digitalRead(controls[1]) == HIGH) {
    // ...code

  } else if (digitalRead(controls[2]) == HIGH) {
    // ...code
    
  }
}

