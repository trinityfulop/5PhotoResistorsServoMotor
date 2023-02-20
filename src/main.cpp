#include <Arduino.h>

int lastlightValueSensor1 = 700;
int lastlightValueSensor2 = 700;
int lastlightValueSensor3 = 700;
int threshold = 800;   // what is the threshold for light?

void setup() {
  Serial.begin(9600);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
}

void loop() {
  // Sensor 1
  int lightValueSensor1 = analogRead(A0);
  // if it's below the threshold?
  if (lightValueSensor1 >= threshold) {
     if (lastlightValueSensor1 < threshold) {
        // the sensor just crossed the threshold
        Serial.println("Light Value right sensor 1 crossed the threshold");
     }
  }
  lastlightValueSensor1 = lightValueSensor1;

    // Sensor 2
  int lightValueSensor2 = analogRead(A1);
  // if it's below the threshold?
  if (lightValueSensor2 >= threshold) {
     if (lastlightValueSensor2 < threshold) {
        // the sensor just crossed the threshold
        Serial.println("Light Value center sensor 2 crossed the threshold");
     }
  }
  lastlightValueSensor2 = lightValueSensor2;

    // Sensor 3
  int lightValueSensor3 = analogRead(A2);
  // if it's below the threshold?
  if (lightValueSensor3 >= threshold) {
     if (lastlightValueSensor3 < threshold) {
        // the sensor just crossed the threshold
        Serial.println("Light Value right sensor 1 crossed the threshold");
     }
  }
  lastlightValueSensor3 = lightValueSensor3;
}