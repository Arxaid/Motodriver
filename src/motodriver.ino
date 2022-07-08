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
Motor motor2 = Motor(3,4,5,ShieldDriversNames::L298N);

std::map<int8_t, Motor> motorList = { {1, motor1}, {2, motor2} };
MotoDriver motodriver = MotoDriver(motorList);

std::list<Motor> motorGroup = {motor1, motor2};
MovingGroup movinggroup = MovingGroup(motorGroup);

void loop() {
  motodriver.ForwardUntil(255, 1, 500);
  motodriver.ForwardUntil(255, 2, 500);
  delay(500);
  movinggroup.GroupBackward(255);
  delay(500);
  movinggroup.GroupForward(50);
  delay(500);
}