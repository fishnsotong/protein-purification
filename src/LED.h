/**
 * File              : LED.h
 * Author            : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 * Date              : 2020-03-25T22:05:31+0800
 * Last Modified Date: 2020-03-31T22:12:53+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */
#ifndef MY_LED_H
#define MY_LED_H

#include <Arduino.h>

class LED {

    private:
        int pin;
        byte state = LOW;
    
    public:
        LED(int pin);
        void init();
        void on();
        void off();
        void switchState();
};


#endif
