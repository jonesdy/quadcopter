#ifndef GYRO_ACC_TEMP_HPP
#define GYRO_ACC_TEMP_HPP

#include <Arduino.h>
#include <Wire.h>

#define MAX_ACCEL 2.0
#define MAX_GYRO 250.0

struct GyroAccTempReading
{
   double acx;
   double acy;
   double acz;
   double tmp; // In F
   double gyx;
   double gyy;
   double gyz;
};

class GyroAccTemp
{
private:
   int addr;
public:
   GyroAccTemp(int address);
   void begin();  // Only need to call once. Assumes you already called Wire.begin()
   GyroAccTempReading read();
};

#endif
