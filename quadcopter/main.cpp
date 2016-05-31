#include <string.h>
#include "Lcd.hpp"
#include "DistanceSensor.hpp"
#include "GyroAccTemp.hpp"
#include "Motor.hpp"
#include <Arduino.h>
#include <Servo.h>

#define ECHO 30
#define TRIG 31
DistanceSensor dist(TRIG, ECHO);
// I hate avr-gcc, it freezes my Arudino with any reference variables. So here's my crappy variable
#define lcd Lcd::getInstance()
#define MPU_ADDR 0x68
GyroAccTemp gyro(MPU_ADDR);
#define FRONT_MOTOR_PIN 9
#define RIGHT_MOTOR_PIN 10
#define BACK_MOTOR_PIN 11
#define LEFT_MOTOR_PIN 12
Motor frontMotor(FRONT_MOTOR_PIN);
Motor rightMotor(RIGHT_MOTOR_PIN);
Motor backMotor(BACK_MOTOR_PIN);
Motor leftMotor(LEFT_MOTOR_PIN);
//Servo servo;

void setup()
{
   Wire.begin();
   gyro.begin();
   frontMotor.begin();
   rightMotor.begin();
   backMotor.begin();
   leftMotor.begin();
   //servo.attach(9);
   //servo.write(0);
   delay(1000);
}

void distTest()
{
   double distCm = dist.getDistanceCm();
   delay(60);     // 60ms between measurements
   double distIn = dist.getDistanceIn();
   lcd.home();
   lcd.print(distCm);
   lcd.print(" cm");
   lcd.setCursor(0, 1);
   lcd.print(distIn);
   lcd.print(" in");
   delay(60);     // 60ms between measurements
}

void gyroTest()
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

void motorTest()
{
   frontMotor.setMotorSpeed(0);
   rightMotor.setMotorSpeed(0);
   backMotor.setMotorSpeed(0);
   leftMotor.setMotorSpeed(0);

   lcd.clear();
   lcd.home();
   lcd.print("Front");
   frontMotor.setMotorSpeed(50);
   delay(5000);
   frontMotor.setMotorSpeed(0);
   lcd.clear();
   lcd.home();
   lcd.print("Right");
   rightMotor.setMotorSpeed(50);
   delay(5000);
   rightMotor.setMotorSpeed(0);
   lcd.clear();
   lcd.home();
   lcd.print("Back");
   backMotor.setMotorSpeed(50);
   delay(5000);
   backMotor.setMotorSpeed(0);
   lcd.clear();
   lcd.home();
   lcd.print("Left");
   leftMotor.setMotorSpeed(50);
   delay(5000);
   leftMotor.setMotorSpeed(0);
   //servo.write(50);
   //delay(1000);
   //servo.write(0);
   //delay(1000);
}

void loop()
{
   lcd.clear();

   //distTest();
   //gyroTest();
   motorTest();

   delay(1000);
}
