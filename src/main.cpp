#include <Arduino.h>

int lastlightValueSensor1 = 800;
int lastlightValueSensor2 = 800;
int lastlightValueSensor3 = 800;
int threshold = 810;   // what is the threshold for light?

void setup() {
  Serial.begin(9600);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
}

void loop() {

  int lightValueSensor1 = analogRead(A0);
  int lightValueSensor2 = analogRead(A1);
  int lightValueSensor3 = analogRead(A2);
  
  Serial.print(lightValueSensor1);
  Serial.print(",");
  Serial.print(lightValueSensor2);
  Serial.print(",");
  Serial.println(lightValueSensor3);
}