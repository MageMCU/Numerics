//
// Carpenter Software
// File: Class MiscMath.h - was Math.h
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
//
// Algebra OOP Library
// The math is underneath the namespace
// nmr for Numerics as in numeric computation.
//
// By Jesse Carpenter (carpentersoftware.com)
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Test_Misc_Math_h
#define Numerics_Test_Misc_Math_h

#include "../TESTS/Common.h"

void MiscMath_T5_DirectionVector()
{
    printTitle("Misc Math T2 Direction Components");

    float rad;
    nmr::Vector3<float> vector;

    // Covers an entire unit circle
    for (int deg = 0; deg < 360; deg += 5)
    {
        rad = (float)deg * DEG_TO_RAD;
        // angle to 3D directional unit vector
        // Note: x, y, and z are referenced as outputs....
        vector = nmr::DirectionVector(rad, nmr::XZ);
        // 2D-Vector back to radian using nmr::XZ...
        rad = nmr::AngleRadian(vector.x(), vector.z());
        // Debug Test
        printAngle("DirectionVector: ", deg, vector, rad);
    }
}

void MiscMath_T4_DirectionComponents()
{
    printTitle("Misc Math T2 Direction Components");

    float x;
    float y;
    float z;
    float rad;

    // Covers an entire unit circle
    for (int deg = 0; deg < 360; deg += 5)
    {
        rad = (float)deg * DEG_TO_RAD;
        // angle to 3D directional unit vector
        // Note: x, y, and z are referenced as outputs....
        nmr::DirectionComponents(rad, x, y, z, nmr::XY);
        // 2D-Vector back to radian using nmr::XY...
        rad = nmr::AngleRadian(x, y);
        // Debug Test
        printAngle("DirectionComponents: ", deg, x, y, z, rad);
    }
}

void MiscMath_T3_Angle2Radian()
{
    float x;
    float y;
    float rad;

    // Covers an entire unit circle
    for (int deg = 0; deg < 360; deg += 5)
    {
        rad = (float)deg * DEG_TO_RAD;
        x = cos(rad);
        y = sin(rad);
        rad = nmr::Angle2Radian(x, y);
        // Debug Test
        printAngle("Angle2Radian: ", deg, x, y, rad);
    }
}

void MiscMath_T2_AngleRadian()
{
    float x;
    float y;
    float rad;

    // Covers an entire unit circle
    for (int deg = 0; deg < 360; deg += 5)
    {
        rad = (float)deg * DEG_TO_RAD;
        x = cos(rad);
        y = sin(rad);
        rad = nmr::AngleRadian(x, y);
        // Debug Test
        printAngle("AngleRadian: ", deg, x, y, rad);
    }
}

void MiscMath_T1_Map()
{
    printTitle("Misc Math T1 Map");

    printSubTitle("Fahrenheit to Celcius");
    // fahrenheit to celcius
    float fahrenheit = 77;
    Serial.print("fahrenheit: ");
    Serial.println(fahrenheit);
    float celcius = nmr::Map<float>(fahrenheit, (float)32, (float)212, (float)0, (float)100);
    Serial.print("celcius = dM.map(fahrenheit, 32, 212, 0, 100): ");
    Serial.println(celcius);

    printSubTitle("Celcius to Fahrenheit");
    celcius = 25;
    Serial.print("celcius: ");
    Serial.println(celcius);
    fahrenheit = nmr::Map<float>(celcius, (float)0, (float)100, (float)32, (float)212);
    Serial.print("fahrenheit = dM.map(celcius, 0, 100, 32, 212): ");
    Serial.println(fahrenheit);
}

#endif
