#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>
#include <Servo.h>

class Motor
{
private:
   Servo servo;
   int pin;
public:
   Motor(int motorPin);
   void begin();
   void setMotorSpeed(int value);      // 0 to 180, doesn't start until 50, haven't gone above 60
   // TODO: Switch to a percentage? Find out what values actually make it run to calc percentage
};

#endif
