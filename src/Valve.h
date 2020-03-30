/**
 * File              : Valve.h
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-03-26T05:59:26+0800
 * Last Modified Date: 2020-03-27T14:24:37+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */

// class describing a simple on/off valve: air pressure and selection of
// imidazole concentration

#ifndef MY_VALVE_H
#define MY_VALVE_H

#include <Arduino.h>
#include <Servo.h>

class Valve : public Servo {
  private:
    byte pin;
    int position;
    int openPos;
    int closePos;

  public:
    Valve(byte pin, int openPos, int closePos);
    void init();
    void update();

    void open();
    void close();
};

#endif
