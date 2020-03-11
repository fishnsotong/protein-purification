/**
 * File              : photo-calibration.ino
 * Author            : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 * Date              : 2020-03-10T13:02:19+0800
 * Last Modified Date: 2020-03-10T17:46:16+0800
 * Last Modified By  : Wayne Yeo [fishnsotong] <wwzyeo@gmail.com>
 */

const int sensorPin = A0;
const int ledPin = 9;
const int indicator = 13;

int sensorValue = 0;
int sensorMin = 1023;
int sensorMax = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(indicator, OUTPUT);
  digitalWrite(indicator, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    if (sensorValue < sensorMax) {
      sensorMax = sensorValue;
    }

    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }
  digitalWrite(indicator, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  sensorValue = constrain(sensorValue, 0, 255);
  analogWrite(ledPin, sensorValue);
}

