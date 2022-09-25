//
// Carpenter Software
// File: Functions Tests.h
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
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#include "Arduino.h"
#include "Angle.h"
#include "Map.h"
#include "Vector3f.h"

#ifndef Functions_Tests_h
#define Functions_Tests_h

void printVector(char c, double x, double y, double z)
{
  Serial.print(c);
  Serial.print("(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.print(z);
  Serial.println(")");
}

void printAngle(char c, double angle, double x, double y, double rad)
{
  Serial.print(c);
  Serial.print("(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(") ");
  Serial.print(angle);
  Serial.print(" ");
  Serial.println(rad);
}

void mapTest()
{
  Numerics::Map<double> dM;
  double fahrenheit = 77;
  double celcius = dM.map(fahrenheit, 32, 212, 0, 100);
  
  Serial.print("celcius: ");
  Serial.println(celcius);
}

void vectorTest()
{
  Numerics::Vector3f<double> v = {1, 2, 3};
  printVector('v', v.x(), v.y(), v.z());

  double m = v.Magnitude();
  Serial.print("v.Mag: ");
  Serial.println(m);

  Numerics::Vector3f<double> u = v.Normalize();
  printVector('u', u.x(), u.y(), u.z());
}

void angleTest()
{
  Numerics::Angle<float> angle;
  float x;
  float y;
  float rad;

  // Covers an entire unit circle
  for (int i = 0; i < 360; i++  /* i += 5 */)
  {
    // directional unit vector
    x = cos(i * (float) DEG_TO_RAD);
    y = sin(i * (float) DEG_TO_RAD);

    // TEST angle() or angle2()
    rad = angle.angle2(x, y);

    // Debug Test
    printAngle('>', i, x, y, rad);
  }
}

#endif
