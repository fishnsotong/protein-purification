/**
 * File              : Valve.cpp
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-03-26T06:06:28+0800
 * Last Modified Date: 2020-03-26T06:30:45+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */

#include <Valve.h>

Valve::Valve(int pin, int openPos, int closePos) {
  this -> pin = pin;    // what is the 'this' pointer supposed to do?
  position = 0;
  init();
}

void Valve::init() {

}

void Valve::update() {

}

void Valve::open() {

}

void Valve::close() {

}

