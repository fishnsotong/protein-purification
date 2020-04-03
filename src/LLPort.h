/**
 * File              : LLPort.h
 * Author            : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 * Date              : 2020-03-31T21:55:52+0800
 * Last Modified Date: 2020-04-01T22:00:18+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */

// defining the series of 4-2 LL port valves that actuate the compressed air

#ifndef MY_LLPORT_H
#define MT_LLPORT_H

#include <Arduino.h>
#include <Servo.h>

class LLPort {
  private:
    int pin;
    int pos;
    int dispensePos;
    int collectPos;
    Servo servo;

  public:
    LLPort(int pin, int dispensePos, int collectPos);
    void init();
    void detach();

    void dispense();
    void collect();
    
};

#endif
