#include <Arduino.h>

void setup() {
    pinMode(13, OUTPUT);
}

void loop() {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
}

/**
 * File              : main.cpp
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-02-24T16:11:18+0800
 * Last Modified Date: 2020-02-25T14:05:58+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */

#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include "Button.h"
#include "LED.h"

const int controls[] = {5, 6, 9, 10};   // these need PWM
const int motors[] = {2, 4, 7, 11};      // these don't
LED led1(13);
Button button1(7);

int ledState = LOW;

Servo myservo;

void setup() {
  myservo.attach(11);
  
}

void loop() {
  myservo.write(90);
  delay(10000);
  myservo.write(0);
  
}