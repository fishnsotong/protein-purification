/**
 * File              : TPort.cpp
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-04-04T02:44:50+0800
 * Last Modified Date: 2020-04-21T22:53:31+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */

TPort::TPort(int pin, int openPos1, int openPos2, int closePos) {
  this -> pin = pin;
  init();
}

void TPort::init() {
  // TPort starts assuming valves are closed
  // We didn't write values to the servo for LLPort, but we should run
  // some tests or compare with stable before making any assumptions.
  
  pos = closePos;
  servo.attach(pin);
}

void TPort::detach() {
  servo.detach();
}

void TPort::open_mode1() {
  if (openPos1 < closePos) {
    for (pos = closePos; pos >= openPos1; pos -= 1) {
      servo.write(pos);
      delay(15);
    }
  }
  
}

void TPort::open1() {
  if (openPos1 > closePos) {
    // enter code here
  } else if (openPos1 <= closePos) {
    // enter code here
  }
}

void TPort::open2() {
  // enter code here
  
}

void TPort::close() {
  // enter code here
  // is there a way to track the previous function ran?
  // save function name as a string variable
  // or is comparing variables ok?
}
