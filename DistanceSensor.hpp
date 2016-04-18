#ifndef DISTANCE_SENSOR_HPP
#define DISTANCE_SENSOR_HPP

#include <Arduino.h>
#include <Wire.h>

class DistanceSensor
{
private:
   uint8_t trig;
   uint8_t echo;
   unsigned long getDuration();
public:
   DistanceSensor(uint8_t trigPin, uint8_t echoPin);
   double getDistanceCm();
   double getDistanceIn();
};

#endif
