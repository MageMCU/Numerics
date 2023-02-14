//
// Carpenter Software
// File: TestQuaternions.h
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
// Created 20221015
// Updated 20221217
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Test_Quaternion_h
#define Numerics_Test_Quaternion_h

#include "../TESTS/Common.h"

// Undergoing further TESTS 20230114 jc
void Quaternion_T9_Quaternion_to_Angle_Axis()
{
    printTitle("Quaternion T9 Quaternion to Angle Axis");

    // Intialization
    // This becomes a half-angle in
    // quaternion multiplication...
    float radian = 2.0 * DEG_TO_RAD;
    float angle;
    nmr::Vector3<float> axis(1, 0, 0);
    // Constant
    nmr::Quaternion<float> c(axis, radian); // Constant set to 2-degrees
    // Multiplicative
    nmr::Quaternion<float> q(axis, 0.0);

    // Game Loop 1 with first quaternion multiplication
    int iAngle = 0;
    do
    {
        String s = String(iAngle) + " ";
        // Prints four columns with 7 decimal digits
        // data for a csv-file
        angle = q.GetEulerAngle();
        printQuaternion(s, q, angle);
        // Quaternion Multiplication --- FIRST method
        q = q * c;
        // Counter
        iAngle += 2; // --------------------- Constant set to 2-degrees
    } while (iAngle < 360);
}

void Quaternion_T8_QuaternionMultiplication()
{
    printTitle("Quaternion T8 Quaternion Multiplication");
    // This prints out a stream of 4-columns of data
    // it could take a minute or two to finish...

    // Intialization
    // This becomes a half-angle in
    // quaternion multiplication...
    float radian = 1.0 * DEG_TO_RAD;
    nmr::Vector3<float> axis(1, 2, 3);
    // Constant
    nmr::Quaternion<float> c(axis, radian);
    // Multiplicative
    nmr::Quaternion<float> q(axis, 0.0);

    // Game Loop 1 with first quaternion multiplication
    int i = 0;
    /*
    do
    {
        // Prints four columns with 7 decimal digits
        // data for a csv-file
        printQuaternion(q);
        // Quaternion Multiplication --- FIRST method
        q = q * c;
        // Counter
        i++;
    } while (i < 721);
    */

    // Game Loop 2 with second quaternion multiplication
    // int i = 0;
    do
    {
        // Prints four columns with 7 decimal digits
        // data for a csv-file
        printQuaternion(q);
        // Quaternion Multiplication --- SECOND method
        q = q.Multiply(c);
        // Counter
        i++;
    } while (i < 721);
}

void Quaternion_T7_Inverse()
{
    printTitle("Quaternion T7 Inverse");

    float angleRadian = 30.0 * DEG_TO_RAD;
    nmr::Vector3<float> axis(1, 1, 1);
    printVector3("axis(1, 1, 1)", axis);
    nmr::Quaternion<float> q(axis, angleRadian);
    printQuaternion("q(axis, angleRadian)", q);

    nmr::Quaternion<float> qI = q.Inverse();
    printQuaternion("qI = q.Inverse(): ", qI);

    nmr::Quaternion<float> identity = q * qI;
    printQuaternion("identity = q * qI: ", identity);
}

void Quaternion_T6_Conjugate()
{
    printTitle("Quaternion T6 Conjugate");

    nmr::Quaternion<float> q(1, 2, 3, 4);
    printQuaternion("q: ", q);
    nmr::Quaternion<float> conjugate = q.Conjugate();
    printQuaternion("conjugate = q.Conjugate(): ", conjugate);
}

void Quaternion_T5_UnitQuaternion()
{
    printTitle("Quaternion T5 Unit Quaternion");

    nmr::Quaternion<float> q(1, 2, 3, 4);
    printQuaternion("q: ", q);
    nmr::Quaternion<float> uQ = q.UnitQuaternion();
    printQuaternion("uQ = q.UnitQuaternion(): ", uQ);
    // The norm ought to be 1
    float n = uQ.Norm();
    Serial.print("n = uQ.Norm(): ");
    Serial.println(String(n, 4));
}

void Quaternion_T4_Scale()
{
    printTitle("Quaternion T4 Scale");

    nmr::Quaternion<float> q(1, 2, 3, 4);
    printQuaternion("q: ", q);

    float s = 0.5;
    Serial.print("s = 0.5: ");
    Serial.println(String(s, 4));
    nmr::Quaternion<float> p = q.Scale(s);
    printQuaternion("p = q.Scale(s): ", p);
}

void Quaternion_T3_Norm()
{
    printTitle("Quaternion T3 Norm");

    nmr::Quaternion<float> q(1, 2, 3, 4);
    printQuaternion("q: ", q);

    float n = q.Norm();
    Serial.print("n = q.Norm(): ");
    Serial.println(String(n, 4));
}

void Quaternion_T2_NormSquared()
{
    printTitle("Quaternion T2 Norm Squared");

    nmr::Quaternion<float> q(-1, -2, -3, -4);
    printQuaternion("q: ", q);
    q = q.UnitQuaternion();
    printQuaternion("q: ", q);

    float n = q.NormSquared();
    Serial.print("n = q.NormSquared(): ");
    Serial.println(String(n, 4));

    bool flag = q.NormDeviation(n);
    Serial.print("Norm Deviation: ");
    if (flag) Serial.println("TRUE");
    else Serial.println("FALSE");
}

void Quaternion_T1_Constructor()
{
    printTitle("Quaternion T1 Constructors");

    nmr::Quaternion<float> q1;
    printQuaternion("q1", q1);

    nmr::Quaternion<float> q2(1, 2, 3, 4);
    printQuaternion("q2", q2);

    float angleRadian = 0.0 * DEG_TO_RAD;
    nmr::Vector3<float> axis1(1, 1, 1);
    printVector3("axis1(1, 1, 1)", axis1);
    nmr::Quaternion<float> q3(axis1, angleRadian);
    printQuaternion("q3(axis1, angleRadian)", q3);

    angleRadian = 45.0 * DEG_TO_RAD;
    nmr::Vector3<float> axis2(1, 2, 3);
    printVector3("axis2(1, 2, 3)", axis2);
    nmr::Quaternion<float> q4(axis2, angleRadian);
    printQuaternion("q4(axis2, angleRadian)", q4);
}

#endif /* Numerics_Test_Quaternion_h */