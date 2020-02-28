#include <Button.h>

Button::Button(int pin) {
    this -> pin = pin;
    lastReading = LOW;
    init();
}

void Button::init() {
    pinMode(pin, INPUT);
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