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
#ifdef DEBUG
   lcd.begin(COLS, ROWS, LCD_5x8DOTS);
   lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
   lcd.setBacklight(HIGH);
#endif
}

void Lcd::home()
{
#ifdef DEBUG
   lcd.home();
#endif
}

void Lcd::print(const char *str)
{
#ifdef DEBUG
   lcd.print(str);
#endif
}

void Lcd::print(double d)
{
#ifdef DEBUG
   lcd.print(d);
#endif
}

void Lcd::print(String str)
{
#ifdef DEBUG
   lcd.print(str);
#endif
}

void Lcd::clear()
{
#ifdef DEBUG
   lcd.clear();
#endif
}

void Lcd::setCursor(uint8_t col, uint8_t row)
{
#ifdef DEBUG
   lcd.setCursor(col, row);
#endif
}

Lcd &Lcd::getInstance()
{
   static Lcd instance;  // avr-g++ is stupid and doesnt allow this magic without the DumbAvrStatic.h
   return instance;
}
