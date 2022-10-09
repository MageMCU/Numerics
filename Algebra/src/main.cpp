//
// Carpenter Software
// File: Main main.cpp
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
//
// Algebra OOP Library
// The math is underneath the namespace
// called Numerics as in numeric computation.
//
// By Jesse Carpenter (carpentersoftware.com)
//
// CHANGELOG
// Created 20221008
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#include <Arduino.h>
#include "Tests.h"

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
  }
  // TEST-FUNCTIONS
  // vectorTest();
  pointTest();
  // angleTest();
  // mapTest();
  matrixTest();
}

void loop() {}