#include "Motor.hpp"

Motor::Motor(int motorPin)
{
   pin = motorPin;
}

void Motor::begin()
{
   servo.attach(pin);
   servo.write(0);
}

void Motor::setMotorSpeed(int value)
{
   servo.write(value);
}
