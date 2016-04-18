#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Wire.h>
#include "Lcd.hpp"
#include "DistanceSensor.hpp"

#define ECHO 30
#define TRIG 31
DistanceSensor sensor(TRIG, ECHO);

void setup()
{
}

void dist_test()
{
   double distCm = sensor.getDistanceCm();
   double distIn = sensor.getDistanceIn();
   Lcd::getInstance().home();
   Lcd::getInstance().print(distCm);
   Lcd::getInstance().print(" cm");
   Lcd::getInstance().setCursor(0, 1);
   Lcd::getInstance().print(distIn);
   Lcd::getInstance().print(" in");
   delay(60);     // 60ms between measurements
}

void loop()
{
   Lcd::getInstance().clear();

   dist_test();

   delay(1000);
}
