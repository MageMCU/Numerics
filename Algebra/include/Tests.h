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
// ditto 20220926,-27
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
#include "Tuples.h"
#include "Vector.h"
#include "Point.h"

#ifndef Functions_Tests_h
#define Functions_Tests_h

void printPoint(String s, Numerics::Point<float> v)
{
  Serial.print(s);
  Serial.print("(");
  Serial.print(v.x());
  Serial.print(", ");
  Serial.print(v.y());
  Serial.print(", ");
  Serial.print(v.z());
  Serial.println(")");
}

void printVector(String s, Numerics::Vector<float> v)
{
  Serial.print(s);
  Serial.print("(");
  Serial.print(v.x());
  Serial.print(", ");
  Serial.print(v.y());
  Serial.print(", ");
  Serial.print(v.z());
  Serial.println(")");
}

void printVector(String s, double x, double y, double z)
{
  Serial.print(s);
  Serial.print("(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.print(z);
  Serial.println(")");
}

void printAngle(String s, double angle, double x, double y, double rad)
{
  Serial.print(s);
  Serial.print("(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(") ");
  Serial.print(angle);
  Serial.print(" ");
  Serial.println(rad);
}

void printTitle(String s)
{
  Serial.println("");
  Serial.print(s);
  Serial.println(" ------------------");
}

void pointVectorTest()
{
  printTitle("pointVectorTest()");

  Numerics::Point<float> p1{1, 2};
  printPoint("p1: ", p1);
  Numerics::Point<float> p2{3, 4};
  printPoint("p2: ", p2);
  Numerics::Vector<float> v{6, 7};
  printVector("v", v);

  Numerics::Point<float> p{};
  Numerics::Vector<float> u{};

  // When using points and vectors
  // these are only two allowable
  // operations...
  // At least until we get to affine 
  // transformations.
  //
  // When adding a vector to a point
  // it give another point.
  p = p1 + v;
  printPoint("p = p1 + v: ", p);
  if (p.IsPoint())
  {
    Serial.println("p is a Point");
  }
  // When subtracting two points,
  // it gives a vector.
  u = p2 - p1;
  printVector("u = p2 - p1: ", u);
  if (u.IsVector())
  {
    Serial.println("u is a Vector");
  }
}

void scalarDivisionTest()
{
  printTitle("scalarDivisionTest()");

  Numerics::Vector<float> a = {1, 2, 3};
  printVector("a", a);
  Numerics::Vector<float> c = {};
  float s = 3;
  Serial.print("s: ");
  Serial.println(s);

  c = a / s;
  printVector("c", c);
}

void scalarMultiplicationTest()
{
  printTitle("scalarMultiplicationTest()");

  Numerics::Vector<float> a = {1, 2, 3};
  printVector("a", a);
  Numerics::Vector<float> c = {};
  float s = 3;
  Serial.print("s: ");
  Serial.println(s);

  c = a * s;
  printVector("c", c);
}

void vectorSubtractionTest()
{
  printTitle("vectorSubtractionTest()");

  Numerics::Vector<float> a = {1, 2, 3};
  printVector("a", a);
  Numerics::Vector<float> b = {3, 2, 1};
  printVector("b", b);
  Numerics::Vector<float> c = {};

  c = a - b;
  printVector("c", c);

  a = b + c;
  printVector("a", a);
}

void vectorAdditionTest()
{
  printTitle("vectorAdditionTest()");

  Numerics::Vector<float> a = {1, 2, 3};
  printVector("a", a);
  Numerics::Vector<float> b = {3, 2, 1};
  printVector("b", b);
  Numerics::Vector<float> c = {};

  c = a + b;
  printVector("c", c);
}

void crossProductTest()
{
  printTitle("crossProductTest()");

  Numerics::Vector<float> a = {1, 2, 3};
  printVector("a", a);
  Numerics::Vector<float> b = {3, 2, 1};
  printVector("b", b);
  Numerics::Vector<float> c = {};

  // Mathematically
  // (2*1 - 3*2, 3*3 - 1*1, 1*2 - 2*3) = (-4, 8, -4)

  c = a ^ b;
  printVector("c = a ^ b: ", c);

  c = a.Cross(b);
  printVector("c = a.Cross(b): ", c);

  Serial.print("z-component of c: ");
  Serial.println(c.z());

  // Assign zeros to the z-component
  // in case dot product adds in z...
  a.z(0);
  b.z(0);

  // Notice this equals the previous
  // z-component of the cross product.
  float perpDot = a.PerpDot(b);
  Serial.print("perpDot: ");
  Serial.println(perpDot);

  if (a.IsVector())
  {
    Serial.println("a is a vector");
  }
}

void dotProductTest()
{
  printTitle("dotProductTest()");

  Numerics::Vector<float> a = {1, 2, 3};
  printVector("a", a);
  Numerics::Vector<float> b = {3, 2, 1};
  printVector("b", b);

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
  printTitle("vectorTest()");

  Numerics::Vector<float> v = {1, 2, 3};
  printVector("v", v.x(), v.y(), v.z());

  float m = v.Magnitude();
  Serial.print("v.Mag: ");
  Serial.println(m);

  Numerics::Vector<float> u = v.Normalize();
  printVector("u", u.x(), u.y(), u.z());
}

void angleTest()
{
  printTitle("angleTest()");

  Numerics::Angle<float> angle;
  float x;
  float y;
  float rad;

  // Covers an entire unit circle
  for (int i = 0; i < 360; i += 10)
  {
    // directional unit vector
    x = cos(i * (float)DEG_TO_RAD);
    y = sin(i * (float)DEG_TO_RAD);

    // TEST angle() or angle2()
    rad = angle.angle2(x, y);

    // Debug Test
    printAngle("rad", i, x, y, rad);
  }
}

void mapTest()
{
  printTitle("mapTest()");

  Numerics::Map<float> dM;
  float fahrenheit = 77;
  float celcius = dM.map(fahrenheit, 32, 212, 0, 100);

  Serial.print("celcius: ");
  Serial.println(celcius);
}

#endif
