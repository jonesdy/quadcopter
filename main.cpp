#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Wire.h>

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define EN_PIN 2
#define RW_PIN 1
#define RS_PIN 0
#define D4_PIN 4
#define D5_PIN 5
#define D6_PIN 6
#define D7_PIN 7

LiquidCrystal_I2C lcd(I2C_ADDR, EN_PIN, RW_PIN, RS_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

#define ECHO 30
#define TRIG 31
uint32_t duration;
double dist_cm;
double dist_in;

void setup()
{
   lcd.begin(20, 4, LCD_5x8DOTS);
   lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
   lcd.setBacklight(HIGH);

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

   lcd.home();
   lcd.print(dist_cm);
   lcd.print(" cm");
   lcd.setCursor(0, 1);
   lcd.print(dist_in);
   lcd.print(" in");
   delay(60);     // 60ms between measurements
}

void loop()
{
   lcd.clear();

   dist_test();

   delay(1000);
}
