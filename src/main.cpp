#include <Arduino.h>
#include <Servo.h>
Servo Serv1;

int pos = 0;
int lastlightValue0 = 0; // I feel like this should be above the threshold?
int lastlightValue1 = 0;
int lastlightValue2 = 0;
int lastlightValue3 = 0;
int lastlightValue4 = 0;

int threshold = 250;

int minVal = 999;
int minSensor = 0;
int currentLowestLight;
int prevLowestLight = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  Serv1.attach(9);
}

void loop()
{

  // Reading the photresistors
  int lightValueSensor0 = analogRead(A0); // far left sensor
  int lightValueSensor1 = analogRead(A1); // left sensor
  int lightValueSensor2 = analogRead(A2); // center sensor
  int lightValueSensor3 = analogRead(A3); // right sensor
  int lightValueSensor4 = analogRead(A4); // far right sensor

  // Finding the lowest light value, telling me the sensor
  if (lightValueSensor0 < minVal)
  {
    minVal = lightValueSensor0;
    minSensor = 0;
  }
  if (lightValueSensor1 < minVal)
  {
    minVal = lightValueSensor1;
    minSensor = 1;
  }
  if (lightValueSensor2 < minVal)
  {
    minVal = lightValueSensor2;
    minSensor = 2;
  }
  if (lightValueSensor3 < minVal)
  {
    minVal = lightValueSensor3;
    minSensor = 3;
  }
  if (lightValueSensor4 < minVal)
  {
    minVal = lightValueSensor4;
    minSensor = 4;
  }

  currentLowestLight = minSensor;

  if (currentLowestLight != prevLowestLight)
  {
    Serial.print(minSensor);
    Serial.print(" / ");
    Serial.println(prevLowestLight);

    if (minSensor == 0)
    {
      Serv1.write(90);
    }
    if (minSensor == 1)
    {
      Serv1.write(120);
    }
    if (minSensor == 2)
    {
      Serv1.write(20);
    }
    if (minSensor == 3)
    {
      Serv1.write(60);
    }
    if (minSensor == 4)
    {
      Serv1.write(160);
    }
  }
  prevLowestLight = currentLowestLight;

  // Serv

  // Serial.print(lightValueSensor0);
  // Serial.print(",");
  // Serial.print(lightValueSensor1);
  // Serial.print(",");
  // Serial.print(lightValueSensor2);
  // Serial.print(",");
  // Serial.print(lightValueSensor3);
  // Serial.print(",");
  // Serial.println(lightValueSensor4);
  // array:
  //  int currentServPos = ServDegrees[minSensor];
  // array?
  //  int ServDegrees[5] = {90, 120, 20, 60, 160};
  //  Serv1.write([ServDegrees[0])
}
