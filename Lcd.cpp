#include "Lcd.hpp"
#include "DumbAvrStatic.h"

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define EN_PIN 2
#define RW_PIN 1
#define RS_PIN 0
#define D4_PIN 4
#define D5_PIN 5
#define D6_PIN 6
#define D7_PIN 7

#define COLS 20
#define ROWS 4

Lcd::Lcd() :
   lcd(I2C_ADDR, EN_PIN, RW_PIN, RS_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN)
{
   lcd.begin(COLS, ROWS, LCD_5x8DOTS);
   lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
   lcd.setBacklight(HIGH);
}

void Lcd::home()
{
   lcd.home();
}

void Lcd::print(const char *str)
{
   lcd.print(str);
}

void Lcd::print(double d)
{
   lcd.print(d);
}

void Lcd::clear()
{
   lcd.clear();
}

void Lcd::setCursor(uint8_t col, uint8_t row)
{
   lcd.setCursor(col, row);
}

Lcd &Lcd::getInstance()
{
   static Lcd instance;  // avr-g++ is stupid and doesnt allow this magic
   return instance;
}
