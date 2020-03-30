/**
 * File              : main.cpp
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-03-27T14:15:26+0800
 * Last Modified Date: 2020-03-27T14:20:57+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */

#include <Arduino.h>
#include "Led.h"

#define LED_1_PIN 13

LED led1(LED_1_PIN);

void setup() { }

void loop() {
  led1.on();
  delay(2000);
  led1.off();
  delay(2000);
}
