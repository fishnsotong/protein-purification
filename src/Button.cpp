/**
 * File              : Button.cpp
 * Author            : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 * Date              : 2020-03-26T06:25:52+0800
 * Last Modified Date: 2020-03-31T22:11:09+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */
#include <Button.h>

Button::Button(int pin) {
    this -> pin = pin;
    lastReading = LOW;
    init();
}

void Button::init() {
    pinMode(pin, INPUT_PULLUP);
    update();
}

void Button::update() {
    byte newReading = digitalRead(pin);

    if (newReading != lastReading) {
        lastDebounceTime = millis();
    }

    if (millis() - lastDebounceTime > debounceDelay) {
        state = newReading;
    }

    lastReading = newReading;
}

byte Button::getState() {
    update();
    return state;
}

bool Button::isPressed() {
    return (getState() == HIGH);
}
