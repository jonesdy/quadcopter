#include "DistanceSensor.hpp"

DistanceSensor::DistanceSensor(uint8_t trigPin, uint8_t echoPin)
{
   trig = trigPin;
   echo = echoPin;
   pinMode(trig, OUTPUT);
   pinMode(echo, INPUT);
}

// NOTE: MUST DELAY AT LEAST 60 MS BETWEEN DURATIONS
unsigned long DistanceSensor::getDuration()
{
   // Send 10 us pulse
   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);
   return pulseIn(echo, HIGH);
}

double DistanceSensor::getDistanceCm()
{
   unsigned long duration = getDuration();
   return (double)duration / 58.0;
}

double DistanceSensor::getDistanceIn()
{
   unsigned long duration = getDuration();
   return (double)duration / 148.0;
}
