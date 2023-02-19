#include <Arduino.h>
#include <Servo.h>

Servo servo1;
int pos = 0;
int lastSensorState = HIGH;   // dark to light
int threshold = 0-1023;   // what is the threshold for light?

void setup() {
  Serial.begin(9600);
  pinMode (A0, INPUT_PULLUP);
  servo1.attach(9);
}

void loop() {
  // read the sensor:
  int lightValue = analogRead(A0);
  int lastlightValue = lightValue; 

  lightValue = map (lightValue, 0, 1023, 0, 180);
 
  // if it's below the threshold?
  if (lightValue >= threshold) {
     if (lastlightValue < threshold) {
        // the sensor just crossed the threshold
        Serial.println("Light Value crossed the threshold");
     }
  }
  lastlightValue = lightValue;

  servo1.write (lightValue);
}