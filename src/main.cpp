/**
 * File              : main.cpp
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-02-24T15:12:24+0800
 * Last Modified Date: 2020-03-03T19:26:29+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */
#include <Arduino.h>  
#include <Servo.h>
#include "Button.h"

Servo servoPbsAir;
Servo servoPbsToggle;
Servo servoImidAir;
Servo servoImidToggle;

int controls[] = {7, 6, 5};

int posPbsAir = 0;    // immediately sucks Pbs up when turned on
int posPbsToggle = 135;
int posImidAir = 90; //immediately sucks Imid up when turned on
int posImidToggle = 90; // open to low conc Imid + Pbs when turned on

int testLight = 13;

void setup() {

  for (int a = 0; a < 3; a++) {
    pinMode(controls[a], INPUT);
  }

  servoPbsAir.attach(9);  // attaches the servo on pin 9 to the servo object
  servoPbsToggle.attach(10);
  servoImidAir.attach(11);
  servoImidToggle.attach(3);

  pinMode(testLight, OUTPUT);
  digitalWrite(testLight, LOW);

  servoPbsAir.write(posPbsAir);
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
    digitalWrite(testLight, HIGH);

    for (posImidToggle = 90; posImidToggle <= 135; posImidToggle += 1) {
      servoImidToggle.write(posImidToggle);
      delay(15);
    } // close the Imid valve

      for (posPbsToggle = 135; posPbsToggle >= 0; posPbsToggle -= 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    } // open outlet

    for (posImidAir = 90; posImidAir >= 0; posImidAir -= 1) {
      servoImidAir.write(posImidAir);
      delay(15);
    } // dispense Imid.
    // yes, it takes that long to dispense through the column
    delay(15000);

    for (posPbsToggle = 0; posPbsToggle <= 135; posPbsToggle += 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    } // close outlet

    digitalWrite(testLight, LOW);

  } else if (digitalRead(controls[2]) == HIGH) {
    digitalWrite(testLight, HIGH);

    for (posImidToggle = 135; posImidToggle <= 180; posImidToggle += 1) {
      servoImidToggle.write(posImidToggle);
      delay(15);
    } // open the Imid valve to high conc.

    for (posImidAir = 0; posImidAir <= 90; posImidAir += 1) {
      servoImidAir.write(posImidAir);
      delay(15);
    } // suck high conc Imid.

    delay(7500);

    for (posImidToggle = 180; posImidToggle >= 135; posImidToggle -= 1) {
      servoImidToggle.write(posImidToggle);
      delay(15);
    } // close the Imid valve

    for (posPbsToggle = 135; posPbsToggle >= 0; posPbsToggle -= 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    } // open outlet

    for (posImidAir = 90; posImidAir >= 0; posImidAir -= 1) {
      servoImidAir.write(posImidAir);
      delay(15);
    } // dispense high conc Imid
    delay(15000);

    for (posPbsToggle = 0; posPbsToggle <= 90; posPbsToggle += 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    } // open outlet to Pbs

    for (posPbsAir = 0; posPbsAir <= 90; posPbsAir += 1) {
      servoPbsAir.write(posPbsAir);
      delay(15); //dispense Pbs
    }
    
    // yes, it takes that long to dispense through the column
    delay(15000);

    for (posPbsToggle = 90; posPbsToggle <= 135; posPbsToggle += 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    }
    for (posPbsAir = 90; posPbsAir >= 0; posPbsAir -= 1) {
      servoPbsAir.write(posPbsAir);
      delay(15); // reset PBS
    }

    for (posImidToggle = 45; posImidToggle <= 90; posImidToggle += 1) {
      servoImidToggle.write(posImidToggle);
      delay(15);
    }

    for (posPbsAir = 0; posPbsAir <= 90; posPbsAir += 1) {
      servoPbsAir.write(posPbsAir);
      delay(15); // suck low con imid
    }

    digitalWrite(testLight, LOW);

  }
}
/* TODO:
 * 1. elution (imidazole + PBS) presented backflow at 45 deg, try 135 deg?
 *
 * 2. reset of system somehow not automatic, and cannot happan at the same
 *    time. I suggest staggering it in void setup()
 *
 * 3. power supply: 12v and 5v from plug is unreliable, only laptops work.
 *    why? can try 9v from wall? or power banks.
 */