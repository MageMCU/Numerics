
//
// Carpenter Software
// File: Main Function main.cpp
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
// Created 20220924
// Corrections & Additions 20220925
// ditto 20220926
// 
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#include "Tests.h"

void setup() {
  Serial.begin(9600);
  while (!Serial)
  {
    /* code */
  }

  //////////////////////////////////////
  // Numerics Tests 
  //////////////////////////////////////
  mapTest();
  vectorTest();
  angleTest();
  dotProductTest();
  crossProductTest();
  //////////////////////////////////////
}

void loop() {
  // put your main code here, to run repeatedly:
}