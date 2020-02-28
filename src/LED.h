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