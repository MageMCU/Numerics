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

#include "Tests.h"

void setup()
{
  Serial.begin(9600);
  while (!Serial) {};

  //////////////////////////////////////
  // Numerics Tests 
  //////////////////////////////////////
  mapTest();                    // ok
  // vectorTest();                 // ok
  // angleTest();                  // ok
  // dotProductTest();             // ok
  crossProductTest();           // ok
  // vectorAdditionTest();         // ok
  // vectorSubtractionTest();      // ok
  // scalarMultiplicationTest();   // ok
  // scalarDivisionTest();         // ok
  pointVectorTest(); // Notice the use of both 
  // Point & Vector classes together *
  // * Decided to do Hierachies instead of Associative 
  //   Relationships with pointers... Too many static globals.
  //////////////////////////////////////
}

void loop()
{
  // put your main code here, to run repeatedly:
}