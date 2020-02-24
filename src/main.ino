/**
 * File              : main.ino
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-02-24T16:11:18+0800
 * Last Modified Date: 2020-02-24T22:00:58+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */

#include <Servo.h>
#include <Wire.h>

const int controls[] = {5, 6, 9, 10};   // these need PWM
const int motors[] = {2, 4, 7, 8};      // these don't

void setup() {
  for (int a = 0; a < 4; a++)
    pinMode(controls[a], INPUT);

  for (int a = 0; a < 4; a++) {
    pinMode(motors[a], OUTPUT);
    Servo motors[a];
  }
}

void loop() {
  pinMode(13, HIGH);
  delay(100);
  pinMode(13, LOW);
  delay(100);
}
