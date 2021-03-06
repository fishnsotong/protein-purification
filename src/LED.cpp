/**
 * File              : LED.cpp
 * Author            : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 * Date              : 2020-03-25T17:06:43+0800
 * Last Modified Date: 2020-03-31T22:13:11+0800
 * Last Modified By  : Wayne Yeo [fishnsotong@gosigs] <wwzyeo@gmail.com>
 */

#include "LED.h"

LED::LED(int pin) {
    this -> pin = pin;
    init();
}

void LED::init() {
    pinMode(pin, OUTPUT);
    off();
}

void LED::on() {
    digitalWrite(pin, HIGH);
}

void LED::off() {
    digitalWrite(pin, LOW);
}

void LED::switchState() {

    state = !state;

    if (state == HIGH) {
        on();
    } else if (state == LOW) {
        off();
    }
    
}
