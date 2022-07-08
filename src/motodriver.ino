// This file is part of the Motodriver project.
//
// Copyright (c) 2022 Institute of Control Sciences RAS.
//
// Feel free to use, copy, modify, merge, and publish this software

#include <Arduino.h>
#include "motodriver.h"

void setup() {
  Serial.begin(9600);
}

Motor motor1 = Motor(10,8,9,ShieldDriversNames::L298N);
std::map<int8_t, Motor> motorList = { {1, motor1} };
MotoDriver motodriver = MotoDriver(motorList);

void loop() {
  motodriver.Forward(255, 1);
  delay(5000);
  motodriver.Backward(50, 1);
  delay(5000);
  motodriver.Shutdown(1);
  delay(10000);
}
