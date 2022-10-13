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
// Created 20221008
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Tests_h
#define Numerics_Tests_h

#include "Arduino.h"
#include "Motion.h"
#include "Angle.h"
#include "Point3.h"
#include "Matrix3x3.h"

using namespace Numerics;

template <typename real>
void printAngle(String s, int deg, Vector3<real> v, real result)
{
    Serial.print(s);
    Serial.print(" deg: ");
    Serial.print(deg);
    Serial.print(" DV(");
    Serial.print(v.x());
    Serial.print(", ");
    Serial.print(v.y());
    Serial.print(", ");
    Serial.print(v.z());
    Serial.print(") ");
    Serial.print("result: ");
    Serial.println(result);
}

template <typename real>
void printVector(String s, Vector3<real> v)
{
    Serial.println(s);
    for (int i = 0; i < 3; i++)
    {
        Serial.print(v.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}

template <typename real>
void printPoint(String s, Point3<real> p)
{
    Serial.println(s);
    for (int i = 0; i < 3; i++)
    {
        Serial.print(p.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}

template <typename real>
void printMatrix(String s, Matrix3x3<real> A)
{
    Serial.println(s);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Serial.print(A.Element(i, j));
            Serial.print(" ");
        }
        Serial.println("");
    }
}

void printTitle(String s)
{
    Serial.print("----------------- ");
    Serial.println(s);
}

void printSubTitle(String s)
{
    Serial.print("------ ");
    Serial.print(s);
    Serial.println(" ------");
}

void pointTest()
{
    printTitle("Point Test");
    Point3<float> p1(-3, -4, 10);
    printPoint("p1", p1);
    Point3<float> p2(15, 2, 21);
    printPoint("p2", p2);
    Vector3<float> v1 = p2 - p1;
    printVector("v1 = p2 - p1", v1);
    Vector3<float> v2(1, 2, 3);
    printVector("v2", v2);
    Point3<float> p3 = p1 + v2;
    printPoint("p3 = p1 + v2", p3);
}

void angleTest()
{
    printTitle("Angle Test");
    Angle<float> angle;
    Vector3<float> v;
    printVector("directional vector v", v);

    printSubTitle("Unit Circle (UC)");
    float rad;
    // Covers an entire unit circle
    for (int deg = 0; deg < 360; deg += 30)
    {
        // angle to directional unit vector
        v = angle.DirectionalVectorXY((float)deg * DEG_TO_RAD);
        // Vector back to radian
        rad = angle.AngleRadianXY(v);
        // Debug Test
        printAngle("UC: ", deg, v, rad);
    }
}

void mapTest()
{
    printTitle("Motion Test");
    Motion<float> dM;
    float fahrenheit = 77;
    float celcius = dM.map(fahrenheit, 32, 212, 0, 100);
    Serial.print("celcius: ");
    Serial.println(celcius);
}

void matrixMatrixMultiplicationTestM6()
{
    printTitle("Matrix Matrix Multiplication Test M6");

    Matrix3x3<float> A;
    printMatrix("A", A);

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3x3<float> B(array);
    printMatrix("B", B);

    Matrix3x3<float> C = A * B;
    printMatrix("C", C);

    float array1[] = {3, 1, -4, 1, 1, 0, -1, 1, 2};
    Matrix3x3<float> D(array1);
    printMatrix("D", D);
    float array2[] = {1, -2, -1, 6, -1, 0, 1, 0, 0};
    Matrix3x3<float> E(array2);
    printMatrix("E", E);
    // Ref: [ELA] by Shields, 1980. p.60 (5a), 477 (ans).
    // ans: 5, -7, -3, 7, -3, -1, 7, 1, 1
    C = D * E;
    printMatrix("C = D * E", C);
}

void matrixVectorMultiplicationTestM5()
{
    printTitle("Matrix Vector Multiplication Test M5");

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3x3<float> A(array);
    printMatrix("A", A);

    Vector3<float> v(1, 2, 3);
    printVector("v(1, 2, 3)", v);

    Vector3<float> result = A * v;
    printVector("result = A * v", result);
}

void matrixTransposeTestM4()
{
    printTitle("Matrix Determinant Test M4");

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3x3<float> A(array);
    printMatrix("A", A);
    Matrix3x3<float> B = A.Transpose();
    printMatrix("B = A.Transpose()", B);
}

void matrixDeterminantTestM3()
{
    printTitle("Matrix Determinant Test M3");

    float array[] = {1, 2, 4, 1, 2, 3, 2, 1, 0};
    // Ref: acronym [LA T,I,C] by Cohen, 2021, p,310.
    // Ans: -3
    Matrix3x3<float> A(array);
    printMatrix("A", A);
    float det = A.Determinant();
    Serial.print("det = A.Determinant(): ");
    Serial.println(det);
    if (A.IsInvertible())
        Serial.println("Invertible YES");
    else
        Serial.println("Invertible NO");
}

void matrixIndexElementTestM2()
{
    printTitle("Matrix Constructor Test M2");

    printSubTitle("array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}");
    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3x3<float> A(array);
    printMatrix("A", A);

    int index = A.Index(2, 1);
    Serial.print("index = A.Index(2, 1): ");
    Serial.println(index);

    float element21 = A.Element(2, 1);
    Serial.print("element21 = A.Element(2, 1): ");
    Serial.println(element21);
}

void matrixConstructorTestM1()
{
    printTitle("Matrix Constructor Test M1");
    printSubTitle("Notice no parenthesis used in the default constructor.");
    printSubTitle("also default constructor creates an identity matrix.");

    Matrix3x3<float> A;
    printMatrix("Matrix3x3<float> A", A);

    printSubTitle("array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}");
    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3x3<float> B(array);
    printMatrix("Matrix3x3<float> B()", B);
}

void vectorSubtractionTestV11()
{
    printTitle("Vector Subtraction Test V11");

    float array1[] = {3, -2, 6};
    Vector3<float> a(array1);
    printVector("a", a);

    float array2[] = {-4, 6, 5};
    Vector3<float> b(array2);
    printVector("b", b);

    Vector3<float> c = a - b;
    printVector("c = a - b", c);

    printSubTitle("Linear Combinations");
    float s = 2.0;
    Serial.println("s = 2.0");
    float t = 3.0;
    Serial.println("t = 3.0");
    c = a * s - -b * t;
    printVector("c = a * s - -b * t;", c);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
}

void vectorAdditionTestV10()
{
    printTitle("Vector Addition Test V10");

    float array1[] = {3, -2, 6};
    Vector3<float> a(array1);
    printVector("a", a);

    float array2[] = {-4, 6, 5};
    Vector3<float> b(array2);
    printVector("b", b);

    Vector3<float> c = a + b;
    printVector("c = a + b", c);

    printSubTitle("Linear Combinations");
    float s = 2.0;
    Serial.println("s = 2.0");
    float t = 3.0;
    Serial.println("t = 3.0");
    c = a * s + b * t;
    printVector("c = a * s + b * t;", c);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
}

void vectorScalarMultiplicationTestV9()
{
    printTitle("Vector Scalar Multiplication Test V9");

    float array[] = {3, -2, 6};
    Vector3<float> a(array);
    printVector("a", a);

    float s = 2.0;
    Vector3<float> b = a * s;
    printVector("b = a * s where s = 2", b);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
}

void vectorNegationTestV8()
{
    printTitle("Vector Negation Test V8");

    float array[] = {3, -2, 6};
    Vector3<float> a(array);
    printVector("a", a);
    a = -a;
    printVector("a = -a", a);
}

void vectorProjThisOntoV_TestV7()
{
    printTitle("Vector ProjThisOntoV Test V7");

    float array1[] = {3, -2, 6};
    Vector3<float> a(array1);
    printVector("a", a);

    float array2[] = {1, 4, 1};
    Vector3<float> b(array2);
    printVector("b", b);

    Vector3<float> c = a.ProjThisOntoV(b);
    printVector("c = a.ProjThisOntoV(b)", c);

    // This test has not been ref nor proven --- FIXME
}

void vectorPerpVectorXY_TestV6()
{
    printTitle("Vector PerpVectorXY Test V6");
    float array[] = {8, 3, 0};
    Vector3<float> v(array);
    printVector("v", v);
    Vector3<float> result = v.PerpVectorXY();
    printVector("result = v.PerpVectorXY()", result);
}

void vectorCrossProductTestV5()
{
    printTitle("Vector Cross Product Test V5");
    // Notice the two different methods for the dot product...

    printSubTitle("Basis i");
    float array1[] = {1, 0, 0};
    Vector3<float> a1(array1);
    printVector("a1", a1);

    printSubTitle("Basis j");
    float array2[] = {0, 1, 0};
    Vector3<float> a2(array2);
    printVector("a2", a2);

    printSubTitle("Basis k");
    Vector3<float> a3 = a1.Cross(a2);

    printVector("a1.Cross(a2)", a3);
    Vector3<float> a4 = a1 ^ a2;
    printVector("a1 ^ a2", a4);
}

void vectorDotProductTestV4()
{
    printTitle("Vector Dot Product Test V4");
    // Notice the two different methods for the dot product...

    Vector3<float> a(1, 2, 3);
    printVector("Vector3<float> a(1, 2, 3)", a);

    Vector3<float> b(3, -4, 8);
    printVector("Vector3<float> b(3, -4, 8)", b);

    float dot = a.Dot(b);
    Serial.print("dot = a.Dot(b) ");
    Serial.println(dot);

    printSubTitle("Unit-Circle Dot Pruduct");
    // This test includes the Angle Class
    // Reference-Angle = 45 degress
    Angle<float> rAngle;
    // reference directional vector
    Vector3<float> rDV = rAngle.DirectionalVectorXY((float)45 * DEG_TO_RAD);
    printVector("rDV directional vector at 45 degrees", rDV);

    // Variable-Angle = 0 to 360 degrees
    Angle<float> vAngle;
    // variable directional vector
    Vector3<float> vDV;

    printSubTitle("Degree - vDV vector - result: dot product");

    // Covers an entire unit circle
    for (int deg = 0; deg < 360; deg += 10)
    {
        // Assign rDV
        vDV = vAngle.DirectionalVectorXY((float)deg * DEG_TO_RAD);
        // dot product
        dot = rDV * vDV;
        // Debug Test
        printAngle("UC: ", deg, vDV, dot);
    }
}

void vectorNormalizeTestV3()
{
    printTitle("Vector Normalize Test V3");

    Vector3<float> a(1, 2, 3);
    printVector("Vector3<float> a(1, 2, 3)", a);

    Vector3<float> b = a.Normalize();
    printVector("Vector3<float> b = a.Normalize()", b);
    printSubTitle("x / magnitude, y / magnitude, etc");
}

void vectorMagnitudeTestV2()
{
    printTitle("Vector Magnitude Test V2");

    Vector3<float> a(1, 2, 3);
    printVector("Vector3<float> a(1, 2, 3)", a);

    float mag = a.Magnitude();
    Serial.print("a.Magnitude() ");
    Serial.println(mag);
    printSubTitle("square-root of 1*1 + 2*2 + 3*3 = 14 is 3.741...");
}

void vectorConstructorTestV1()
{
    printTitle("Vector Constructor Test V1");
    printSubTitle("Notice no parenthesis used in the default constructor.");

    Vector3<float> a;
    printVector("Vector3<float> a", a);

    Vector3<float> b(1, 2, 3);
    printVector("Vector3<float> b(1, 2, 3)", b);

    printSubTitle("float array[] = {1, 0, 0};");
    float array[] = {1, 0, 0};
    Vector3<float> c(array);
    printVector("Vector3<float> c(array)", c);
}

#endif
