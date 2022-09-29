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

// TODO
// Comment-out USE_SERIAL_PRINT to
// test everything for memory size... 40%

#define USE_SERIAL_PRINT

#include "Arduino.h"

#include "Map.h"
#include "Tuples.h"
#include "Vector.h"
#include "Point.h"
#include "Angle.h"
#include "Matrix.h"

#ifndef Functions_Tests_h
#define Functions_Tests_h

void printMatrix(String s, Numerics::Matrix<float> m)
{
#ifdef USE_SERIAL_PRINT
  Serial.println(s);
  // Using only the 3x3 but actually
  // it's an 4x4 affine matrix
  int size2x2 = 2;
  for (int row = 0; row < size2x2; row++)
  {
    for (int col = 0; col < size2x2; col++)
    {
      Serial.print(m.GetValue(row, col));
      Serial.print(" ");
    }
    Serial.println("");
  }
  
  Serial.println(s);
  int size3x3 = 3;
  for (int row = 0; row < size3x3; row++)
  {
    for (int col = 0; col < size3x3; col++)
    {
      Serial.print(m.GetValue(row, col));
      Serial.print(" ");
    }
    Serial.println("");
  }
  
  Serial.println(s);
  int size4x4 = 4;
  for (int row = 0; row < size4x4; row++)
  {
    for (int col = 0; col < size4x4; col++)
    {
      Serial.print(m.GetValue(row, col));
      Serial.print(" ");
    }
    Serial.println("");
  }
#endif
}

void printPoint(String s, Numerics::Point<float> v)
{
#ifdef USE_SERIAL_PRINT
  Serial.print(s);
  Serial.print("(");
  Serial.print(v.x());
  Serial.print(", ");
  Serial.print(v.y());
  Serial.print(", ");
  Serial.print(v.z());
  Serial.println(")");
#endif
}

void printVector(String s, Numerics::Vector<float> v)
{
#ifdef USE_SERIAL_PRINT
  Serial.print(s);
  Serial.print("(");
  Serial.print(v.x());
  Serial.print(", ");
  Serial.print(v.y());
  Serial.print(", ");
  Serial.print(v.z());
  Serial.println(")");
#endif
}

void printVector(String s, double x, double y, double z)
{
#ifdef USE_SERIAL_PRINT
  Serial.print(s);
  Serial.print("(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.print(z);
  Serial.println(")");
#endif
}

void printAngle(String s, int deg, Numerics::Vector<float> v, double rad)
{
#ifdef USE_SERIAL_PRINT
  Serial.print(s);
  Serial.print(" deg: ");
  Serial.print(deg);
  Serial.print(" (");
  Serial.print(v.x());
  Serial.print(", ");
  Serial.print(v.y());
  Serial.print(", ");
  Serial.print(v.z());
  Serial.print(") ");
  Serial.print("radian: ");
  Serial.println(rad);
#endif
}

void printTitle(String s)
{
#ifdef USE_SERIAL_PRINT
  Serial.println("");
  Serial.print(s);
  Serial.println(" ------------------");
#endif
}

void matrixTest()
{
  printTitle("matrixTest()");

  Numerics::Matrix<float> m{};
  printMatrix("m", m);
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
#ifdef USE_SERIAL_PRINT
    Serial.println("p is a Point");
#endif
  }
  // When subtracting two points,
  // it gives a vector.
  u = p2 - p1;
  printVector("u = p2 - p1: ", u);
  if (u.IsVector())
  {
#ifdef USE_SERIAL_PRINT
    Serial.println("u is a Vector");
#endif
  }
}

void scalarDivisionTest()
{
  printTitle("scalarDivisionTest()");

  Numerics::Vector<float> a = {1, 2, 3};
  printVector("a", a);
  Numerics::Vector<float> c = {};
  float s = 3;
#ifdef USE_SERIAL_PRINT
  Serial.print("s: ");
  Serial.println(s);
#endif

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
#ifdef USE_SERIAL_PRINT
  Serial.print("s: ");
  Serial.println(s);
#endif

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

#ifdef USE_SERIAL_PRINT
  Serial.print("z-component of c: ");
  Serial.println(c.z());
#endif

  // Assign zeros to the z-component
  // in case dot product adds in z...
  a.z(0);
  b.z(0);

  // Notice this equals the previous
  // z-component of the cross product.
  float perpDot = a.PerpDot(b);
#ifdef USE_SERIAL_PRINT
  Serial.print("perpDot: ");
  Serial.println(perpDot);
#endif

  if (a.IsVector())
  {
#ifdef USE_SERIAL_PRINT
    Serial.println("a is a vector");
#endif
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
#ifdef USE_SERIAL_PRINT
  Serial.print("Dot1: ");
  Serial.println(dot);
#endif

  // Method 2
  dot = a * b;
#ifdef USE_SERIAL_PRINT
  Serial.print("Dot2: ");
  Serial.println(dot);
#endif
}

void vectorTest()
{
  printTitle("vectorTest()");

  Numerics::Vector<float> v = {1, 2, 3};
  printVector("v", v.x(), v.y(), v.z());

  float m = v.Magnitude();
#ifdef USE_SERIAL_PRINT
  Serial.print("v.Mag: ");
  Serial.println(m);
#endif

  Numerics::Vector<float> u = v.Normalize();
  printVector("u", u.x(), u.y(), u.z());
}

void angleTest2()
{
  // This test checks the vectors
  printTitle("angleTest2()");

  Numerics::Angle<float> angle;
  Numerics::Vector<float> v = {1, 2, 3};
  printVector("v", v.x(), v.y(), v.z());

  float angleXY = angle.AngleRadianXY(v);
#ifdef USE_SERIAL_PRINT
  Serial.print("angleXY: ");
  Serial.print(angleXY);
  Serial.print(" ");
  Serial.println(angleXY * RAD_TO_DEG);
#endif

  float angleXZ = angle.AngleRadianXZ(v);
#ifdef USE_SERIAL_PRINT
  Serial.print("angleXZ: ");
  Serial.print(angleXZ);
  Serial.print(" ");
  Serial.println(angleXZ * RAD_TO_DEG);
#endif

  float angleYZ = angle.AngleRadianYZ(v);
#ifdef USE_SERIAL_PRINT
  Serial.print("angleYZ: ");
  Serial.print(angleYZ);
  Serial.print(" ");
  Serial.println(angleYZ * RAD_TO_DEG);
#endif
}

void angleTest1()
{
  // This checks the quadrants...
  printTitle("angleTest1()");

  Numerics::Angle<float> angle;
  Numerics::Vector<float> v = {};
  float rad;

  // Covers an entire unit circle
  for (int deg = 0; deg < 360; deg += 10)
  {
    // angle to directional unit vector
    v = angle.DirectionalVectorXY((float)deg * DEG_TO_RAD);

    // Vector back to radian
    rad = angle.AngleRadianXY(v);

    // Debug Test
    printAngle("angTest1: ", deg, v, rad);
  }
}

void mapTest()
{
  printTitle("mapTest()");

  Numerics::Map<float> dM;
  float fahrenheit = 77;
  float celcius = dM.map(fahrenheit, 32, 212, 0, 100);

#ifdef USE_SERIAL_PRINT
  Serial.print("celcius: ");
  Serial.println(celcius);
#endif
}

#endif
