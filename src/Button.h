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