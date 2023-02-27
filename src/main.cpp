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
  delay (3000);
}