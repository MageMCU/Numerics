//
// Carpenter Software
// File: TestPoints.h
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

#ifndef Numerics_Test_Points_h
#define Numerics_Test_Points_h

#include "../TESTS/Common.h"

void pointVectorAdditionTestP3()
{
    printTitle("Point Vector Addition Test P3");

    nmr::Vector<float> v1(1, 2, 3);
    printVector("v1", v1);

    nmr::Point<float> p1(-3, -4, 10);
    printPoint("p1", p1);

    nmr::Point<float> p2 = p1 + v1;
    printPoint("p2 = p1 + v1", p2);

    if (p2.IsPoint())
        Serial.println("p2 is POINT");
    else
        Serial.println("v1 is VECTOR");
}

void pointPointSubtractionTestP2()
{
    printTitle("Point Point Subtraction Test P2");

    nmr::Point<float> p1(-3, -4, 10);
    printPoint("p1", p1);

    nmr::Point<float> p2(15, 2, 21);
    printPoint("p2", p2);

    nmr::Vector<float> v1 = p2 - p1;
    printVector("v1 = p2 - p1", v1);

    if (v1.IsVector())
        Serial.println("v1 is VECTOR");
    else
        Serial.println("v1 is POINT");
}

void pointConstructorTestP1()
{
    printTitle("Point Constructor Test P1");
    printSubTitle("Notice no parenthesis used in the default constructor.");

    nmr::Point<float> p;
    printPoint("p", p);

    nmr::Point<float> p1(1, 2);
    printPoint("p1(1, 2)", p1);

    nmr::Point<float> p2(1, 2, 3);
    printPoint("p2(1, 2, 3)", p2);

    nmr::Point<float> p3(1, 2, 3, 1);
    printPoint("p3(1, 2, 3, 1)", p3);

    printSubTitle("float array[] = {1, 0, 0};");
    float array[] = {1, 0, 0};
    nmr::Point<float> p4(array);
    printPoint("p4(array)", p4);
}

void DontKillTheRedundancy()
{
}

#endif