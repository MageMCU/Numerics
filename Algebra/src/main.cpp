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

  matrixMatrixMultiplicationTestM6();
  // matrixVectorMultiplicationTestM5();
  // matrixTransposeTestM4();
  // matrixDeterminantTestM3();
  // matrixIndexElementTestM2();
  // matrixConstructorTestM1();

  // vectorSubtractionTestV11();
  // vectorAdditionTestV10();
  // vectorScalarMultiplicationTestV9();
  // vectorNegationTestV8();
  // vectorProjThisOntoV_TestV7();
  // vectorPerpVectorXY_TestV6();
  // vectorCrossProductTestV5();
  // vectorDotProductTestV4();
  // vectorNormalizeTestV3();
  // vectorMagnitudeTestV2();
  // vectorConstructorTestV1();

  // pointTest();
  // angleTest();
  // mapTest();
}

void loop() {}