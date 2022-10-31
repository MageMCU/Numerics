//
// Carpenter Software
// File: ain main.cpp
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
// Created 20221030
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#include <Arduino.h>

#include "Vector2.h"
#include "Vector3.h"
#include "Point2.h"
#include "Point3.h"
#include "Matrix.h"
#include "Quaternion.h"

// Common utility function
#include "TESTS/Common.h"
// recommended to un-comment one at a time...
// Sync includes with each set of test functions.
#include "TESTS/TestVector2.h"
#include "TESTS/TestVector3.h"
#include "TESTS/TestPoint2.h"
#include "TESTS/TestPoint3.h"
#include "TESTS/TestMatrix.h"

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    /* code */
  }

  //
  // --------------------------------------
  // TESTING IN PROGRESS
  // --------------------------------------

  // Quaternion Tests ---------------------- NOT STARTED
  // Matrix Tests -------------------------- NOT STARTED
  // Point3 Tests -------------------------- NOT STARTED
  // Point2 Tests -------------------------- NOT STARTED

  // Vector3 Tests ------------------------- NOT COMPLETED
  Vector3_T1_Constructor();

  // Vector2 Tests ------------------------- COMPLETED
  // Vector2_T14_DotProduct();
  // Vector2_T13_VectorVectorSubtraction();
  // Vector2_T12_VectorVectorAddition();
  // Vector2_T11_VectorScalarProduct();
  // Vector2_T10_NegateVector();
  // Vector2_T9_ProjV();
  // Vector2_T8_PerpDot();
  // Vector2_T7_Perp();
  // Vector2_T6_Angle();
  // Vector2_T5_Dot_Product();
  // Vector2_T4_UnitVector_Normalize();
  // Vector2_T3_Magnitude_Distance();
  // Vector2_T2_GetVector();
  // Vector2_T1_Constructor();
}

void loop()
{
  // put your main code here, to run repeatedly:
}