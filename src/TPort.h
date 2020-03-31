/**
 * File              : TPort.h
 * Author            : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 * Date              : 2020-03-31T20:45:09+0800
 * Last Modified Date: 2020-03-31T21:57:51+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */

#ifndef MY_TPORT_H
#define MY_TPORT_H

#include <Arduino.h>
#include <Servo.h>

class TPort {
  private:
    byte pin;
    int position;
    int openPos1;
    int openPos2;
    int closePos;

  public:
    Valve(byte pin, int openPos1, int openPos2, int closePos);
    void init();
    void update();

    void open1();
    void open2();
    void close();

};

#endif
