#ifndef LCD_HPP
#define LCD_HPP

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class Lcd
{
private:
   LiquidCrystal_I2C lcd;
   Lcd();
public:
   Lcd(Lcd const&) = delete;
   void operator=(Lcd const&) = delete;
   static Lcd &getInstance();
   void home();
   void print(const char *str);
   void print(double d);
   void clear();
   void setCursor(uint8_t col, uint8_t row);
};

#endif
