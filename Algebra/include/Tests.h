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

#include "Arduino.h"
#include "Angle.h"
#include "Map.h"
#include "Vector3.h"

#ifndef Functions_Tests_h
#define Functions_Tests_h

void printVector(char c, Numerics::Vector3<float> v)
{
  Serial.print(c);
  Serial.print("(");
  Serial.print(v.x());
  Serial.print(", ");
  Serial.print(v.y());
  Serial.print(", ");
  Serial.print(v.z());
  Serial.println(")");
}

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

void crossProductTest()
{
  Numerics::Vector3<float> a = {1, 2, 3};
  Numerics::Vector3<float> b = {3, 2, 1};
  Numerics::Vector3<float> c = {};

  // Mathematically
  // (2*1 - 3*2, 3*3 - 1*1, 1*2 - 2*3) = (-4, 8, -4)

  c = a ^ b;
  printVector('c', c);

  c = a.Cross(b);
  printVector('c', c);

  Serial.print("z-component of c: ");
  Serial.println(c.z());

  // Assign zeros to the z-component
  a.z(0);
  b.z(0);

  // Notice this equals the previous
  // z-component of the cross product.
  float perpDot = a.PerpDot(b);
  Serial.print("perpDot: ");
  Serial.println(perpDot);

  if (a.IsVector())
  {
    Serial.print("'a' is a vector...");
  }
}

void dotProductTest()
{
  Numerics::Vector3<float> a = {1, 2, 3};
  Numerics::Vector3<float> b = {1, 2, 3};

  // Mathematically
  // dot = 1 * 1 + 2 * 2 + 3 * 3 = 14

  // Method 1
  float dot = a.Dot(b);
  Serial.print("Dot1: ");
  Serial.println(dot);

  // Method 2
  dot = a * b;
  Serial.print("Dot2: ");
  Serial.println(dot);
}

void vectorTest()
{
  Numerics::Vector3<float> v = {1, 2, 3};
  printVector('v', v.x(), v.y(), v.z());

  float m = v.Magnitude();
  Serial.print("v.Mag: ");
  Serial.println(m);

  Numerics::Vector3<float> u = v.Normalize();
  printVector('u', u.x(), u.y(), u.z());
}

void angleTest()
{
  Numerics::Angle<float> angle;
  float x;
  float y;
  float rad;

  // Covers an entire unit circle
  for (int i = 0; i < 360; /* i++  */ i += 5)
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

void mapTest()
{
  Numerics::Map<float> dM;
  float fahrenheit = 77;
  float celcius = dM.map(fahrenheit, 32, 212, 0, 100);
  
  Serial.print("celcius: ");
  Serial.println(celcius);
}

#endif
