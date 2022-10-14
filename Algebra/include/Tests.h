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
#include "Vector.h"
#include "Point.h"
#include "Matrix.h"
#include "Math.h"

using namespace Numerics;

template <typename real>
void printAngle(String s, int deg, real x, real y, real z, real result)
{
    Serial.print(s);
    Serial.print(" deg: ");
    Serial.print(deg);
    Serial.print(" dv(");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(", ");
    Serial.print(z);
    Serial.print(") ");
    Serial.print("result: ");
    Serial.println(result);
}

template <typename real>
void printAngle(String s, int deg, Vector<real> v, real result)
{
    Serial.print(s);
    Serial.print(" deg: ");
    Serial.print(deg);
    Serial.print(" dv(");
    Serial.print(v.x());
    Serial.print(", ");
    Serial.print(v.y());
    Serial.print(", ");
    Serial.print(v.z());
    Serial.print(") ");
    Serial.print("result: ");
    Serial.println(result);
}

/*
template <typename real>
void printQuaternion(String s, Quaternion<real> q)
{
    Serial.println(s);
    for (int i = 0; i < 4; i++)
    {
        Serial.print(q.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}
*/

template <typename real>
void printVector(String s, Vector<real> v)
{
    Serial.println(s);
    for (int i = 0; i < 4; i++)
    {
        Serial.print(v.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}

template <typename real>
void printPoint(String s, Point<real> p)
{
    Serial.println(s);
    for (int i = 0; i < 4; i++)
    {
        Serial.print(p.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}

/*
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
*/

template <typename real>
void printMatrix(String s, Matrix<real> A)
{
    Serial.println(s);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Serial.print(A.Element(i, j));
            Serial.print(" ");
        }
        Serial.println("");
    }
}

void printTitle(String s)
{
    Serial.print("---------------- + ");
    Serial.print(s);
    Serial.println(" +");
}

void printSubTitle(String s)
{
    Serial.print(" ** ");
    Serial.print(s);
    Serial.println(" **");
}

void printNewLine()
{
    Serial.println("");
}

void quaternionConstructorTestQ1()
{
    printTitle("Quaternion Constructor Test Q1");

    // Quaternion<float> q;
    // printQuaternion("", q);
}

void matrixMatrixMultiplicationTestM6()
{
    printTitle("Matrix Matrix Multiplication Test M6");

    Matrix<float> I;
    printMatrix("I", I);

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<float> A(array);
    printMatrix("A", A);

    Matrix<float> B = A * I;
    printMatrix("B = A * I", B);

    Matrix<float> C = I * A;
    printMatrix("C = I * A", C);

    float array1[] = {3, 1, -4, 1, 1, 0, -1, 1, 2};
    Matrix<float> D(array1);
    printMatrix("D", D);

    float array2[] = {1, -2, -1, 6, -1, 0, 1, 0, 0};
    Matrix<float> E(array2);
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
    Matrix<float> A(array);
    printMatrix("A", A);

    Vector<float> v(1, 2, 3);
    printVector("v(1, 2, 3)", v);

    Vector<float> result = A * v;
    printVector("result = A * v", result);
}

void matrixTransposeTestM4()
{
    printTitle("Matrix Determinant Test M4");

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<float> A(array);
    printMatrix("A", A);
    Matrix<float> B = A.Transpose();
    printMatrix("B = A.Transpose()", B);
}

void matrixDeterminantTestM3()
{
    printTitle("Matrix Determinant Test M3");

    float array[] = {1, 2, 4, 1, 2, 3, 2, 1, 0};
    // Ref: acronym [LA T,I,C] by Cohen, 2021, p,310.
    // Ans: -3
    Matrix<float> A(array);
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
    Matrix<float> A(array);
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

    Matrix<float> A;
    printMatrix("Matrix3x3<float> A", A);

    printSubTitle("array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}");
    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<float> B(array);
    printMatrix("Matrix3x3<float> B()", B);
}

void vectorAngleTestV12()
{
    printTitle("Vector Angle between 3D-Vectors Test V12");

    float x = cos((float)45 * DEG_TO_RAD);
    float y = sin((float)45 * DEG_TO_RAD);
    Vector<float> a(x, y);
    printVector("a", a);

    x = cos((float)0 * DEG_TO_RAD);
    y = sin((float)0 * DEG_TO_RAD);
    Vector<float> b(x, y);
    printVector("b", b);

    float angle = a.Angle(b);
    Serial.print("angle = a.Angle(b): ");
    Serial.println(angle * RAD_TO_DEG);

    // To Compare with Angle Class the vectors
    // have to be 2D instead of 3D as it is here...

    // Interesting to view Unit-Circle
    printSubTitle("Unit-Circle");
    for (int deg = 0; deg < 360; deg += 5)
    {
        x = cos((float)deg * DEG_TO_RAD);
        y = sin((float)deg * DEG_TO_RAD);

        b.x(x);
        b.y(y);

        angle = a.Angle(b) * RAD_TO_DEG;

        printAngle("a=45 b=", deg, b, angle);
    }
}

void vectorSubtractionTestV11()
{
    printTitle("Vector Subtraction Test V11");

    float array1[] = {3, -2, 6};
    Vector<float> a(array1);
    printVector("a", a);

    float array2[] = {-4, 6, 5};
    Vector<float> b(array2);
    printVector("b", b);

    Vector<float> c = a - b;
    printVector("c = a - b", c);

    printSubTitle("Linear Combinations");
    float s = 2.0;
    Serial.println("s = 2.0");
    float t = 3.0;
    Serial.println("t = 3.0");

    // This test includes the operator=(Vector<real> v)
    printSubTitle("Reassigned 'c' using operator=(Vector<real> v)");
    c = a * s - -b * t;
    //      a =  3,  -2    6
    //     -b =  4,  -6,  -5
    // ----------------------
    //  a * 2 =  6,  -4,  12
    // -b * 3 = 12, -18, -15
    //          --  ---  ---
    //          -6   14   27
    printVector("c = a * s - -b * t;", c);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
}

void vectorAdditionTestV10()
{
    printTitle("Vector Addition Test V10");

    float array1[] = {3, -2, 6};
    Vector<float> a(array1);
    printVector("a", a);

    float array2[] = {-4, 6, 5};
    Vector<float> b(array2);
    printVector("b", b);

    Vector<float> c = a + b;
    printVector("c = a + b", c);

    printSubTitle("Linear Combinations");
    float s = 2.0;
    Serial.println("s = 2.0");
    float t = 3.0;
    Serial.println("t = 3.0");

    // This test includes the operator=(Vector<real> v)
    printSubTitle("Reassigned 'c' using operator=(Vector<real> v)");
    c = a * s + b * t;
    printVector("c = a * s + b * t", c);

    Vector<float> d = a * s + b * t;
    printVector("d = a * s + b * t;", d);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
}

void vectorScalarMultiplicationTestV9()
{
    printTitle("Vector Scalar Multiplication Test V9");

    float array[] = {3, -2, 6};
    Vector<float> a(array);
    printVector("a", a);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
    printSubTitle("Constraint scalar right side of '*' ONLY");
    float s = 2.0;
    Vector<float> b = a * s;
    printVector("b = a * s where s = 2", b);
}

void vectorNegationTestV8()
{
    printTitle("Vector Negation Test V8");

    float array[] = {3, -2, 6};
    Vector<float> a(array);
    printVector("a", a);

    // This test includes the operator=(Vector<real> v)
    printSubTitle("This test includes operator=(Vector<real> v)");
    Vector<float> b = a;
    printVector("b = a", b);

    // This test includes the operator-()
    printSubTitle("This test includes operator-()");
    a = -a;
    printVector("a = -a", a);
}

void vectorProjectionTestV7()
{
    printTitle("Vector Projection Test V7");

    float array1[] = {3, -2, 6};
    Vector<float> a(array1);
    printVector("a", a);

    float array2[] = {1, 4, 1};
    Vector<float> b(array2);
    printVector("b", b);

    Vector<float> c = a.ProjV(b);
    printVector("c = a.ProjV(b)", c);

    // See methods for references...
    // This test has not been proven --- FIXME
}

void vectorPerpVectorXY_TestV6()
{
    printTitle("Vector PerpVectorXY Test V6");
    float array[] = {8, 3, 0};
    Vector<float> v(array);
    printVector("v", v);
    Vector<float> result = v.PerpVectorXY();
    printVector("result = v.PerpVectorXY()", result);
}

void vectorCrossProductTestV5()
{
    printTitle("Vector Cross Product Test V5");
    // Notice the two different methods for the dot product...

    printSubTitle("Basis i");
    float array1[] = {1, 0, 0};
    Vector<float> a1(array1);
    printVector("a1", a1);

    printSubTitle("Basis j");
    float array2[] = {0, 1, 0};
    Vector<float> a2(array2);
    printVector("a2", a2);

    printSubTitle("Basis k");
    Vector<float> a3 = a1.Cross(a2);

    printVector("a1.Cross(a2)", a3);
    Vector<float> a4 = a1 ^ a2;
    printVector("a1 ^ a2", a4);
}

void vectorDotProductTestV4()
{
    printTitle("Vector Dot Product Test V4");
    // Notice the two different methods for the dot product...

    Vector<float> a(1, 2, 3);
    printVector("Vector<float> a(1, 2, 3)", a);

    Vector<float> b(3, -4, 8);
    printVector("Vector<float> b(3, -4, 8)", b);

    float dot = a.Dot(b);
    Serial.print("dot = a.Dot(b): ");
    Serial.println(dot);

    // dot ok  reassigned
    dot = a * b;
    Serial.print("dot = a * b: ");
    Serial.println(dot);

    // printSubTitle("Unit-Circle Dot Pruduct");
    // This test includes the Angle Class
    // Reference-Angle = 45 degress
    // Angle<float> rAngle();
    // reference directional vector ------------------------------------------- FIXME
    // Vector3<float> rDV = rAngle.DirectionalVectorXY((float)45 * DEG_TO_RAD);
    // printVector("rDV directional vector at 45 degrees", rDV);

    // Variable-Angle = 0 to 360 degrees
    // Angle<float> vAngle;
    // variable directional vector
    // Vector3<float> vDV;

    // printSubTitle("Degree - vDV vector - result: dot product");

    // Covers an entire unit circle
    // for (int deg = 0; deg < 360; deg += 10)
    // {
    // Assign rDV ------------------------------------------- FIXME
    // Vector3<float> vDV = vAngle.DirectionalVectorXY((float)deg * DEG_TO_RAD);
    // dot product
    // dot = rDV * vDV;
    // Debug Test
    // printAngle("UC: ", deg, vDV, dot);
    // }
}

void vectorNormalizeTestV3()
{
    printTitle("Vector Normalize Test V3");

    Vector<float> a(1, 2, 3);
    printVector("Vector<float> a(1, 2, 3)", a);

    Vector<float> b = a.Normalize();
    printVector("Vector<float> b = a.Normalize()", b);
    printSubTitle("x / magnitude, y / magnitude, etc");

    // Magnitude ought to be one
    float mag = b.Magnitude();
    Serial.print("b.Magnitude() ");
    Serial.println(mag);
}

void vectorMagnitudeTestV2()
{
    printTitle("Vector Magnitude Test V2");

    Vector<float> a(1, 2, 3);
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

    Vector<float> a;
    printVector("Vector<float> a", a);

    Vector<float> b(1, 2);
    printVector("Vector<float> b(1, 2)", b);

    Vector<float> c(1, 2, 3);
    printVector("Vector<float> c(1, 2, 3)", c);

    Vector<float> d(1, 2, 3, 0);
    printVector("Vector<float> d(1, 2, 3, 0)", d);

    printSubTitle("float array[] = {1, 0, 0, 0};");
    float array[] = {1, 0, 0, 0};
    Vector<float> e(array);
    printVector("Vector<float> c(array)", e);
}

void angleTestA1()
{
    printTitle("Angle Test A1");

    float x;
    float y;
    float z;
    float rad;

    // Covers an entire unit circle
    for (int deg = 0; deg < 360; deg += 30)
    {
        rad = (float)(deg * DEG_TO_RAD);
        // angle to 2D directional unit vector
        DirectionalVector(rad, x, y, z, XY);
        // 2D-Vector back to radian
        rad = AngleRadian(x, y);
        // Debug Test
        printAngle("UC: ", deg, x, y, z, rad);
    }
}

void pointTest()
{
    printTitle("Point Test");

    Point<float> p1(1, 2);
    printPoint("p1", p1);

    Point<float> p2(1, 2, 3, 1);
    printPoint("p2", p2);

    Point<float> p3(-3, -4, 10);
    printPoint("p3", p3);

    Point<float> p4(15, 2, 21);
    printPoint("p4", p4);

    Vector<float> v1 = p4 - p3;
    printVector("v1 = p4 - p3", v1);
    if (v1.IsVector())
        Serial.println("v1 is VECTOR");
    else
        Serial.println("v1 is POINT");

    Vector<float>
        v2(1, 2, 3);
    printVector("v2", v2);

    Point<float> p5 = p3 + v2;
    printPoint("p5 = p3 + v2", p5);
    if (p5.IsVector())
        Serial.println("p5 is VECTOR");
    else
        Serial.println("p5 is POINT");
}

void mapTest()
{
    printTitle("Motion Test");
    Motion<float> dM;
    float fahrenheit = 77;
    float celcius = dM.map(fahrenheit, 32, 212, 0, 100);
    Serial.print("celcius: ");
    Serial.println(celcius);

    // See other main.cpp.1.txt
}

#endif
