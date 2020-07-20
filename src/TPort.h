/**
 * File              : TPort.h
 * Author            : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 * Date              : 2020-03-31T20:45:09+0800
 * Last Modified Date: 2020-04-23T07:53:44+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */

#ifndef MY_TPORT_H
#define MY_TPORT_H

#include <Arduino.h>
#include <Servo.h>

class TPort {
  private:
    int pin;
    int position;
    int openPos1;
    int openPos2;
    int closePos;
    Servo servo;

  public:
    TPort(int pin, int openPos1, int openPos2, int closePos);
    void init();
    void detach();

    void open_mode1();
    void open_mode2();
    void close_mode1();
    void close2_mode2();

    // is it possible to fetch the name of the previous function run,
    // and fit it into a conditional statement?

};

#endif
