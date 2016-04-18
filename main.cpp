#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Wire.h>
#include "Lcd.hpp"
#include "DistanceSensor.hpp"

#define ECHO 30
#define TRIG 31
DistanceSensor sensor(TRIG, ECHO);
Lcd &lcd = Lcd::getInstance();

void setup()
{
}

void dist_test()
{
   double distCm = sensor.getDistanceCm();
   double distIn = sensor.getDistanceIn();
   lcd.home();
   lcd.print(distCm);
   lcd.print(" cm");
   lcd.setCursor(0, 1);
   lcd.print(distIn);
   lcd.print(" in");
   delay(60);     // 60ms between measurements
}

void loop()
{
   lcd.clear();

   dist_test();

   delay(1000);
}
