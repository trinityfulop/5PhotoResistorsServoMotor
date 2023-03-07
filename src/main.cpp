#include <Arduino.h>
#include <Servo.h>
Servo Serv1;

int pos = 0;
int lastlightValue1 = 0;
int lastlightValue2 = 0;
int lastlightValue3 = 0;
int lastlightValue4 = 0;
int lastlightValue5 = 0; //I feel like this should be above the threshold?
int threshold = 250; 

int minVal = 999;
int minSensor = 0;
int currentLowest;
int prevLowest = 0;

void setup() {
  Serial.begin(9600);

  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (A3, INPUT);
  pinMode (A4, INPUT);
  Serv1.attach(9);
  }

void loop() {

// Reading the photresistors
  int lightValueSensor1 = analogRead(A0);
  int lightValueSensor2 = analogRead(A1);
  int lightValueSensor3 = analogRead(A2);
  int lightValueSensor4 = analogRead(A3);
  int lightValueSensor5 = analogRead(A4);
  


// Finding the lowest light value, telling me the senso

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

//find current & prev lowest. 
// min sensor value from prev = currentLowest?
currentLowest = minSensor;

if (currentLowest != prevLowest) {
   Serial.print(minSensor); // this is just repeating when it's not supposed to?
   Serial.print(" / ");
   Serial.println(prevLowest);  
  Serial.print(lightValueSensor1);
  Serial.print(",");
  Serial.print(lightValueSensor2); 
  Serial.print(",");
  Serial.print(lightValueSensor3);
  Serial.print(",");
  Serial.print(lightValueSensor4);
  Serial.print(",");
  Serial.println(lightValueSensor5);

}
prevLowest = currentLowest;

}

