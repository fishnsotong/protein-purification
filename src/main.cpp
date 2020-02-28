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

const int controls[] = {5, 6, 9, 10};   // these need PWM
const int motors[] = {2, 4, 7, 8};      // these don't

class Button {
  private:
    byte pin;
    byte state;
    byte lastReading;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;

  public:
    Button(byte pin) {
      this -> pin = pin;
      lastReading = LOW;
      init();
    }

    void init() {
      pinMode(pin, INPUT);
      update();
    }

    void update() {
      byte newReading = digitalRead(pin);

      if (newReading != lastReading) {
        lastDebounceTime = millis();
      }

      if (millis() - lastDebounceTime > debounceDelay) {
        state = newReading;
      }

      lastReading = newReading;
    }

    byte getState() {
      update();
      return state;
    }

    bool isPressed() {
      return (getState() == HIGH);
    }

};

void setup() {
  Button button1(4);
  for (int a = 0; a < 4; a++) {
    Button controls[a](a);
  }

  for (int a = 0; a < 4; a++) {
    pinMode(motors[a], OUTPUT); // TODO: You don't need to assign pinMode for the Servo class.
    Servo motors[a];
    motors[a].attach(a);
  }
  pinMode(13, OUTPUT);
}

void loop() {
  pinMode(13, HIGH);
  delay(100);
  pinMode(13, LOW);
  delay(100);
}