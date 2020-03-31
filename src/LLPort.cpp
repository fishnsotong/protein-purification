/**
 * File              : LLPort.cpp
 * Author            : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 * Date              : 2020-03-31T22:03:41+0800
 * Last Modified Date: 2020-04-01T01:13:42+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */

#include "LLPort.h"

LLPort::LLPort(int pin, int dispensePos, int collectPos) {
  this -> pin = pin;
  init();
}

void LLPort::init() {
  // LLPort starts assuming well is empty
  pos = collectPos;
  Servo servo;
  servo.attach(pin);
}

void LLPort::detach() {
  servo.detach(pin);
}

void LLPort::dispense() {
  if (dispensePos > collectPos) {
    for (pos = collectPos; pos <= dispensePos; pos += 1) {
      servo.write(pos);
      delay(15);
    }
  } else if (dispensePos < collectPos) {
    for (pos = collectPos; pos >= dispensePos; pos -= 1) {
      servo.write(pos);
      delay(15);
    }
  }
}

void LLPort::collect() {
  if (dispensePos > collectPos) {
    for (pos = dispensePos; pos >= collectPos; pos -=1) {
      servo.write(pos);
      delay(15);
    }
  } else if (dispensePos < collectPos) {
    for (pos = dispensePos; pos >= collectPos; pos += 1) {
      servo.write(pos);
      delay(15);
    }
  }
}
