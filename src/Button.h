/**
 * File              : Button.h
 * Author            : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 * Date              : 2020-03-26T06:25:52+0800
 * Last Modified Date: 2020-03-31T22:11:53+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */

#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <Arduino.h>

class Button {

    private:
        int pin;
        byte state;
        byte lastReading;
        unsigned long lastDebounceTime = 0;
        unsigned long debounceDelay = 50;

    public:
        Button(int pin);

        void init();
        void update();

        byte getState();
        bool isPressed();
};

#endif
