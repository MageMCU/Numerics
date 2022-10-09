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

#ifndef Tests_h
#define Tests_h

#include "Arduino.h"
#include "Map.h"
#include "Angle.h"
#include "Point3.h"
#include "Matrix3x3.h"

using namespace Numerics;

template <typename real>
void printAngle(String s, int deg, Vector3<real> v, double rad)
{
    Serial.print(s);
    Serial.print(" deg: ");
    Serial.print(deg);
    Serial.print(" d-vector (");
    Serial.print(v.x());
    Serial.print(", ");
    Serial.print(v.y());
    Serial.print(", ");
    Serial.print(v.z());
    Serial.print(") ");
    Serial.print("rad: ");
    Serial.println(rad);
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

void matrixTest()
{
    printTitle("Matrix Test");
    float array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix3x3<float> A(array1);
    printMatrix("A", A);

    Matrix3x3<float> B;
    printMatrix("B", B);

    printSubTitle("Matrix Matrix Multiplication");
    Matrix3x3<float> C = A * B;
    printMatrix("C = A * B", C);

    printSubTitle("Matrix Transpose");
    C = A.Transpose();
    printMatrix("AT", C);

    printSubTitle("Matrix Vector Multiplication");
    printMatrix("A", A);
    Vector3<float> x(1, 2, 3);
    printVector("x", x);
    // b = 14, 32, 50
    Vector3<float> b = A * x;
    printVector("b = A * x", b);
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
    printTitle("Map Test");
    Map<float> dM;
    float fahrenheit = 77;
    float celcius = dM.map(fahrenheit, 32, 212, 0, 100);
    Serial.print("celcius: ");
    Serial.println(celcius);
}

void vectorTest()
{
    printTitle("Vector Test");

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

    printSubTitle("Scalar Product");
    a3 = a1 * (float)6;
    printVector("a1 * (float) 6", a3);

    printSubTitle("Vector Addtion");
    a3 = a1 + a2;
    printVector("a1 + a2", a3);

    printSubTitle("Vector Sutraction");
    a3 = a1 - a2;
    printVector("a1 - a2", a3);

    printSubTitle("Dot Product");
    float dot = a1.Dot(a2);
    Serial.print("a1.Dot(a2): ");
    Serial.println(dot);
    dot = a1 * a2;
    Serial.print("a1 * a2: ");
    Serial.println(dot);

    printSubTitle("Misc");
    a3 = a1 + a2;
    printVector("a1 + a2", a3);
    float array3[] = {-5, 10, 2};
    Vector3<float> a5(array3);
    printVector("a5", a5);
    float magnitude = a5.Magnitude();
    Serial.print("a5.Magnitude(): ");
    Serial.println(magnitude);
    a5 = a5.Normalize();
    printVector("a5.Normalize()", a5);
    magnitude = a5.Magnitude();
    Serial.print("a5.Magnitude(): ");
    Serial.println(magnitude);

    printSubTitle("PerpVectorXY");
    a3 = a1 + a2;
    printVector("a1 + a2", a3);
    float array4[] = {3, 8, 0};
    Vector3<float> a6(array4);
    printVector("a6", a6);
    float array5[] = {1, 1, 0};
    Vector3<float> a7(array5);
    printVector("a7", a7);
    a3 = a6.PerpVectorXY();
    printVector("a3 = a6.PerpVectorXY", a3);
    dot = a3 * a7;
    Serial.print("a3 * a7: ");
    Serial.println(dot);
    a3 = a6 ^ a7;
    printVector("a6 ^ a7", a3);
    Serial.print("a3.z: ");
    Serial.println(a3.z());

    printSubTitle("ProjThisOntoV");
    float array7[] = {3, -2, 0};
    Vector3<float> a8(array7);
    printVector("a8", a8);
    float array8[] = {1, 4, 0};
    Vector3<float> a9(array8);
    printVector("a9", a9);
    a3 = a9.Normalize();
    printVector("a9.Normalize", a3);
    Vector3<float> a10 = a8.ProjThisOntoV(a9);
    printVector("a10 = a8.ProjThisOntoV(a9)", a10);
    a3 = a10.Normalize();
    printVector("a10.Normalize", a3);
}

#endif
