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