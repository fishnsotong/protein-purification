/**
 * File              : main.cpp
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-02-24T15:12:24+0800
 * Last Modified Date: 2020-04-21T22:42:59+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */

#include <Arduino.h>  
#include <Servo.h>
#include "Button.h"

Servo servoPbsAir;
Servo servoPbsToggle;
Servo servoImidAir;
Servo servoImidToggle;

int controls[] = {7, 6, 5};

int posPbsAir = 0;
int posPbsToggle = 90; // default CLOSED
int posImidAir = 90;
int posImidToggle = 45; // default CLOSED

int testLight = 13;

void resetSystem();
void blink();

void pbsDispense();
void pbsCollect();

void imidDispense();
void imidCollect();

// main outlet of the device
// open before each action and close after dispensing PBS
// 90-135 deg
void mainToggleOpen_PBS();    // TPort
void mainToggleClose_PBS();   // TPort

// open before each action and close after dispending Imid
// 0-135 deg
void mainToggleOpen_IMID();
void mainToggleClose_IMID();

// toggle to switch between PBS and imidazole action
void imidToggleOpen_HIGH();
void imidToggleOpen_LOW();
void imidToggleClose_HIGH();
void imidToggleClose_LOW();

void setup() {

  for (int a = 0; a < 3; a++) {
    pinMode(controls[a], INPUT);
  }

  servoPbsAir.attach(9);
  servoPbsToggle.attach(10);
  servoImidAir.attach(11);
  servoImidToggle.attach(3);

  pinMode(testLight, OUTPUT);
  digitalWrite(testLight, LOW);

  servoPbsToggle.write(posPbsToggle);
  servoImidToggle.write(posImidToggle);
  resetSystem();
}

void loop() {

  if (digitalRead(controls[0]) == HIGH) {
    
    digitalWrite(testLight, HIGH);
    pbsDispense();
    mainToggleOpen_PBS();

    delay(15000);

    mainToggleClose_PBS();
    pbsCollect();
    digitalWrite(testLight, LOW);

  } else if (digitalRead(controls[1]) == HIGH) {

    digitalWrite(testLight, HIGH);
    imidToggleClose_LOW();
    mainToggleOpen_IMID();
    imidDispense();

    delay(15000);

    mainToggleClose_IMID();
    digitalWrite(testLight, LOW);

  } else if (digitalRead(controls[2]) == HIGH) {

    digitalWrite(testLight, HIGH);
    imidToggleOpen_HIGH();
    imidCollect();

    delay(5000);

    imidToggleClose_HIGH();
    mainToggleOpen_IMID();
    imidDispense();

    delay(15000);

    mainToggleClose_IMID();
    mainToggleOpen_PBS();
    pbsDispense();

    delay(15000);

    mainToggleClose_PBS();
    pbsCollect();

    delay(5000);

    imidToggleOpen_LOW();
    imidCollect();

    delay(5000);

    digitalWrite(testLight, LOW);

  }
}

void resetSystem() {
  mainToggleClose_PBS();
  pbsCollect();
  delay(5000);
  imidToggleOpen_LOW();
  imidCollect();
  delay(5000);

  blink();
  blink();
  blink();
}

void blink() {
  digitalWrite(testLight, HIGH);
  delay(200);
  digitalWrite(testLight, LOW);
  delay(200);
}

void pbsDispense() {
  for (posPbsAir = 0; posPbsAir <= 90; posPbsAir += 1) {
      servoPbsAir.write(posPbsAir);
      delay(15);
    }
}

void pbsCollect() {
  for (posPbsAir = 90; posPbsAir >= 0; posPbsAir -= 1) {
      servoPbsAir.write(posPbsAir);
      delay(15);
    }
}

void imidDispense() {
  for (posImidAir = 90; posImidAir >= 0; posImidAir -= 1) {
      servoImidAir.write(posImidAir);
      delay(15);
    }
}

void imidCollect() {
  for (posImidAir = 0; posImidAir <= 90; posImidAir += 1) {
      servoImidAir.write(posImidAir);
      delay(15);
    }
}

void mainToggleOpen_PBS() {
  for (posPbsToggle = 135; posPbsToggle >= 90; posPbsToggle -= 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
  }
}

void mainToggleClose_PBS() {
  for (posPbsToggle = 90; posPbsToggle <= 135; posPbsToggle += 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    }
}

void mainToggleOpen_IMID() {
  for (posPbsToggle = 135; posPbsToggle >= 0; posPbsToggle -= 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    }
}

void mainToggleClose_IMID() {
  for (posPbsToggle = 0; posPbsToggle <= 135; posPbsToggle += 1) {
      servoPbsToggle.write(posPbsToggle);
      delay(15);
    }
}

void imidToggleOpen_LOW() {
  for (posImidToggle = 45; posImidToggle <= 90; posImidToggle += 1) {
    servoImidToggle.write(posImidToggle);
    delay(15);
  }
}

void imidToggleClose_LOW() {
  for (posImidToggle = 90; posImidToggle >= 45; posImidToggle -= 1) {
    servoImidToggle.write(posImidToggle);
    delay(15);
  }
}

void imidToggleOpen_HIGH() {
  for (posImidToggle = 45; posImidToggle <= 180; posImidToggle += 1) {
      servoImidToggle.write(posImidToggle);
      delay(15);
    }
}

void imidToggleClose_HIGH() {
  for (posImidToggle = 180; posImidToggle >= 45; posImidToggle -= 1) {
      servoImidToggle.write(posImidToggle);
      delay(15);
    }
}

/* TODO:
 * 1. For some reason, the reset button does not function correctly.
 *    Control 3 seems to work fine as a reset function, however.
 */
