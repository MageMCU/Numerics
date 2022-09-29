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
// Created 20220927
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#include <Arduino.h>
#include "Tuples.h"
#include "Point.h"
#include "Vector.h"
#include "Angle.h"
#include "Matrix.h"

#include "Tests.h"

void setup()
{
  Serial.begin(9600);
  while (!Serial) {};

  // Please note that Serial Print eats
  // up a lot of memory...
  //////////////////////////////////////
  // Numerics Tests 
  //////////////////////////////////////
  // mapTest();                    // ok
  // vectorTest();                 // ok
  // angleTest1();                 // ok
  // angleTest2();                 // ok
  // dotProductTest();             // ok
  // crossProductTest();           // ok
  // vectorAdditionTest();         // ok
  // vectorSubtractionTest();      // ok
  // scalarMultiplicationTest();   // ok
  // scalarDivisionTest();         // ok
  // pointVectorTest();            // ok
  matrixTest();
  //////////////////////////////////////
}

void loop()
{
  // put your main code here, to run repeatedly:
}