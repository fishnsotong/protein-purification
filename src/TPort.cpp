/**
 * File              : TPort.cpp
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-04-04T02:44:50+0800
 * Last Modified Date: 2020-04-04T02:50:47+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */

TPort::TPort(int pin, int openPos1, int openPos2, int closePos) {
  this -> pin = pin;
  init();
}

void TPort::init() {
  // TPort starts assuming valves are closed
  pos = closePos;
  servo.attach(pin);
  // Do we need to write the position? Or just assume
}

void TPort::detach() {
  servo.detach();
}

void TPort::open1() {
  // enter code here
}

void TPort::open2() {
  // enter code here
  
}

void TPort::close() {
  // enter code here
  // is there a way to track the previous function ran?
  // save function name as a string variable
}
