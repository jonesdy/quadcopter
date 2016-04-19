#include <string.h>
#include "Lcd.hpp"
#include "DistanceSensor.hpp"
#include "GyroAccTemp.hpp"

#define ECHO 30
#define TRIG 31
DistanceSensor dist(TRIG, ECHO);
// I hate avr-gcc, it freezes my Arudino with any reference variables. So here's my crappy variable
#define lcd Lcd::getInstance()
#define MPU_ADDR 0x68
GyroAccTemp gyro(MPU_ADDR);

void setup()
{
   Wire.begin();
   gyro.begin();
}

void dist_test()
{
   double distCm = dist.getDistanceCm();
   double distIn = dist.getDistanceIn();
   lcd.home();
   lcd.print(distCm);
   lcd.print(" cm");
   lcd.setCursor(0, 1);
   lcd.print(distIn);
   lcd.print(" in");
   delay(60);     // 60ms between measurements
}

void gyro_test()
{
   GyroAccTempReading reading = gyro.read();
   lcd.home();
   lcd.print("acx: ");
   lcd.print(String(reading.acx));
   lcd.print(" acy: ");
   lcd.print(String(reading.acy));
   lcd.setCursor(0, 1);
   lcd.print("acz: ");
   lcd.print(String(reading.acz));
   lcd.print(" tmp: ");
   lcd.print(String(reading.tmp));
   lcd.setCursor(0, 2);
   lcd.print("gyx: ");
   lcd.print(String(reading.gyx));
   lcd.print(" gyy: ");
   lcd.print(String(reading.gyy));
   lcd.setCursor(0, 3);
   lcd.print("gyz: ");
   lcd.print(String(reading.gyz));
}

void loop()
{
   lcd.clear();

   //dist_test();
   gyro_test();

   delay(1000);
}
