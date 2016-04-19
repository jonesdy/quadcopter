#include "GyroAccTemp.hpp"

GyroAccTemp::GyroAccTemp(int address)
{
   addr = address;
}

// Only need to call once. Assumes you already called Wire.begin()
void GyroAccTemp::begin()
{
   Wire.beginTransmission(addr);
   Wire.write(0x6B);    // PWR_MGMT_1 register
   Wire.write(0);       // Set to 0, wakes up the MPU-6050
   Wire.endTransmission(true);
}

GyroAccTempReading GyroAccTemp::read()
{
   GyroAccTempReading reading;

   Wire.beginTransmission(addr);
   Wire.write(0x3b);    // Starting with register 0x3B (ACCEL_XOUT_H)
   Wire.endTransmission(false);
   Wire.requestFrom(addr, 14, true);   // 14 registers

   int16_t acx = Wire.read() << 8 | Wire.read();   // 0x3B (ACCEL_XOUT_H) | 0x3C (ACCEL_XOUT_L)
   int16_t acy = Wire.read() << 8 | Wire.read();   // 0x3D (ACCEL_YOUT_H) | 0x3E (ACCEL_YOUT_L)
   int16_t acz = Wire.read() << 8 | Wire.read();   // 0x3F (ACCEL_ZOUT_H) | 0x40 (ACCEL_ZOUT_L)
   int16_t tmp = Wire.read() << 8 | Wire.read();   // 0x41 (TEMP_OUT_H) | 0x42 (TEMP_OUT_L)
   int16_t gyx = Wire.read() << 8 | Wire.read();   // 0x43 (GYRO_XOUT_H) | 0x44 (GYRO_XOUT_L)
   int16_t gyy = Wire.read() << 8 | Wire.read();   // 0x45 (GYRO_YOUT_H) | 0x46 (GYRO_YOUT_L)
   int16_t gyz = Wire.read() << 8 | Wire.read();   // 0x47 (GYRO_ZOUT_H) | 0x47 (GYRO_ZOUT_L)

   reading.acx = (MAX_ACCEL * acx) / INT16_MAX;
   reading.acy = (MAX_ACCEL * acy) / INT16_MAX;
   reading.acz = (MAX_ACCEL * acz) / INT16_MAX;
   reading.tmp = ((tmp / 340.00 + 36.53) * 1.8) + 32.0; // In F
   reading.gyx = (MAX_GYRO * gyx) / INT16_MAX;
   reading.gyy = (MAX_GYRO * gyy) / INT16_MAX;
   reading.gyz = (MAX_GYRO * gyz) / INT16_MAX;

   return reading;
}
