//
// Carpenter Software
// File: TestMisc.h
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
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Test_Misc_h
#define Numerics_Test_Misc_h

#include "../TESTS/Common.h"

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
        nmr::DirectionalVector(rad, x, y, z, nmr::XY);
        // 2D-Vector back to radian
        rad = nmr::AngleRadian(x, y);
        // Debug Test
        printAngle("UC: ", deg, x, y, z, rad);
    }
}

void celciusFahrenheitMapTest()
{
    printTitle("Celcius Fahrenheit Map Test");
    nmr::Motion<float> dM;
    printSubTitle("Map Function uses a Linear Equation");
    printSubTitle("x1 & x2 are two points on the x-axis");
    printSubTitle("y1 & y2 are two points on the y-axis");
    printSubTitle("where y = slope * x");
    // fahrenheit to celcius
    float fahrenheit = 77;
    Serial.print("fahrenheit: ");
    Serial.println(fahrenheit);
    // map() function
    float celcius = dM.map(fahrenheit, 32, 212, 0, 100);
    Serial.print("celcius = dM.map(fahrenheit, 32, 212, 0, 100): ");
    Serial.println(celcius);

    // celcius to fahrenheit
    celcius = 25;
    Serial.print("celcius: ");
    Serial.println(celcius);
    // map() function
    fahrenheit = dM.map(celcius, 0, 100, 32, 212);
    Serial.print("fahrenheit = dM.map(celcius, 0, 100, 32, 212): ");
    Serial.println(fahrenheit);

    // See other main.cpp.1.txt
}

void DontKillTheRedundancy() {}

#endif