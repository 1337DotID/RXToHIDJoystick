#include "Joystick.h"

//new for version 2.0 -> Joystick must be a variable
Joystick_ Joystick;

int throttle = 0;
int throttleValue;
int throttleValueOld;

int yaw = 1;
int yawValue;
int yawValueOld;

int pitch = 2;
int pitchValue;
int pitchValueOld;

int roll = 3;
int rollValue;
int rollValueOld;

void setup() {
  attachInterrupt(throttle, throttleRising, RISING);
  attachInterrupt(yaw, yawRising, RISING);
  attachInterrupt(pitch, pitchRising, RISING);
  attachInterrupt(roll, rollRising, RISING);
  
  Joystick.begin(true);
}

void throttleRising() {
  attachInterrupt(throttle, throttleFalling, FALLING);
  throttleValueOld = micros();
}

void throttleFalling() {
  attachInterrupt(throttle, throttleRising, RISING);
  throttleValue = micros() - throttleValueOld;
}

void yawRising() {
  attachInterrupt(yaw, yawFalling, FALLING);
  yawValueOld = micros();
}

void yawFalling() {
  attachInterrupt(yaw, yawRising, RISING);
  yawValue = micros() - yawValueOld;
}

void pitchRising() {
  attachInterrupt(pitch, pitchFalling, FALLING);
  pitchValueOld = micros();
}

void pitchFalling() {
  attachInterrupt(pitch, pitchRising, RISING);
  pitchValue = micros() - pitchValueOld;
}

void rollRising() {
  attachInterrupt(roll, rollFalling, FALLING);
  rollValueOld = micros();
}

void rollFalling() {
  attachInterrupt(roll, rollRising, RISING);
  rollValue = micros() - rollValueOld;
}

void loop() {
  //new for version 2.0 -> mapping must be done differently
  Joystick.setYAxis(map(throttleValue, 1050, 1960, 512, 1023));
  Joystick.setXAxis(map(yawValue, 1050, 1960, 512, 1023));
  Joystick.setZAxis(map(pitchValue, 1050, 1960, 512, 1023));
  Joystick.setRxAxis(map(rollValue, 1050, 1960, 512, 1023));
}
