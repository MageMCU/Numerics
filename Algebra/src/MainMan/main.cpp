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
// Updated 20221017
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#include <Arduino.h>

// Common utility function
#include "../TESTS/Common.h"
// recommended to un-comment one at a time...
// Sync includes with each set of test functions.
#include "../TESTS/TestMisc.h"
// #include "../TESTS/TestVectors.h"
// #include "../TESTS/TestPoints.h"
// #include "../TESTS/TestMatrices.h"

// Motion.h & DeltaTime.h tested MainDied

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
  }

  // TEST-FUNCTIONS
  // WARNING: While learning the library, it is
  // recommended to view each 'test' individually.
  // Otherwise, a black-circled-white-question-mark will appear
  // in the serial-monitor indicating memory overflow...

  // Check Redundancies
  DontKillTheRedundancy();

  // TestQuaternions.h ---------------
  // quaternionConstructorTestQ1();

  // TestMatrices.h ---------------
  // matrixScalarMultiplicationTestM9();
  // matrixNegationTestM8();
  // matrixCopyMatrixTestM7();
  // matrixMatrixMultiplicationTestM6();
  // matrixVectorMultiplicationTestM5();
  // matrixTransposeTestM4();
  // matrixDeterminantTestM3();
  // matrixElementTestM2();
  // matrixConstructorTestM1();

  // TestPointers.h ---------------
  // pointVectorAdditionTestP3();
  // pointPointSubtractionTestP2();
  // pointConstructorTestP1();

  // TestVectors.h ---------------
  // vectorAngleTestV12();
  // vectorSubtractionTestV11();
  // vectorAdditionTestV10();
  // vectorScalarMultiplicationTestV9();
  // vectorNegationTestV8();
  // vectorProjectionTestV7();
  // vectorPerpVectorXY_TestV6();
  // vectorCrossProductTestV5();
  // vectorDotProductTestV4();
  // vectorNormalizeTestV3();
  // vectorMagnitudeTestV2();
  // vectorConstructorTestV1();

  // TestMisc.h ---------------
  angleTestA1();
  celciusFahrenheitMapTest();
}

void loop() {}