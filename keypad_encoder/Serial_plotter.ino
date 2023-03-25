#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(19200);
}

void loop()
{
  float t= millis();
  // put your main code here, to run repeatedly:
  float tRep = (millis() % 10000) / 10000.0;
  float x = sin(2*PI*((80-0)/(10.0*2))*pow(tRep,2));

  Serial.print(t);
  Serial.print("");
  Serial.print(x);
  Serial.println();
}