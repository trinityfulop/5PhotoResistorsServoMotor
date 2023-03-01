#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (A3, INPUT);
  pinMode (A4, INPUT);
}

void loop() {

// Reading the photresistors
  int lightValueSensor1 = analogRead(A0);
  int lightValueSensor2 = analogRead(A1);
  int lightValueSensor3 = analogRead(A2);
  int lightValueSensor4 = analogRead(A3);
  int lightValueSensor5 = analogRead(A4);
  
  Serial.print(lightValueSensor1);
  Serial.print(",");
  Serial.print(lightValueSensor2); 
  Serial.print(",");
  Serial.print(lightValueSensor3);
  Serial.print(",");
  Serial.print(lightValueSensor4);
  Serial.print(",");
  Serial.println(lightValueSensor5);

// Finding the lowest light value, telling me the sensor.
int minVal = 999;
int minSensor;

if (lightValueSensor1 < minVal) {
  minVal = lightValueSensor1;
  minSensor = 1;
}
if (lightValueSensor2 < minVal) {
  minVal = lightValueSensor2;
  minSensor = 2;
}
if (lightValueSensor3 < minVal) {
  minVal = lightValueSensor3;
  minSensor = 3;
}
if (lightValueSensor4 < minVal) {
  minVal = lightValueSensor4;
  minSensor = 4;
}
if (lightValueSensor5 < minVal) {
  minVal = lightValueSensor5;
  minSensor = 5;
}

}