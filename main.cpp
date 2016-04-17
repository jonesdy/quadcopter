#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Wire.h>
#include "Lcd.hpp"

#define ECHO 30
#define TRIG 31
uint32_t duration;
double dist_cm;
double dist_in;

void setup()
{
   pinMode(TRIG, OUTPUT);
   pinMode(ECHO, INPUT);

   delay(1000);
}

void dist_test()
{
   dist_cm = 0.0;
   dist_in = 0.0;

   // Send 10us pulse
   digitalWrite(TRIG, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIG, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG, LOW);
   duration = pulseIn(ECHO, HIGH);
   dist_cm = (double)duration / 58.0;
   dist_in = (double)duration / 148.0;

   Lcd::getInstance().home();
   Lcd::getInstance().print(dist_cm);
   Lcd::getInstance().print(" cm");
   Lcd::getInstance().setCursor(0, 1);
   Lcd::getInstance().print(dist_in);
   Lcd::getInstance().print(" in");
   delay(60);     // 60ms between measurements
}

void loop()
{
   Lcd::getInstance().clear();

   dist_test();

   delay(1000);
}
