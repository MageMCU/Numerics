//
// Carpenter Software
// File: Tests TestVector3.h
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
// Created 20221030 - Testing in Progress
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Test_Vector3_h
#define Numerics_Test_Vector3_h

#include "../TESTS/Common.h"

void Vector3_T1_Constructor()
{
    printTitle("Vector3 Constructor Test V1");
    printSubTitle("Notice no parenthesis used in the default constructor.");

    nmr::Vector3<float> v1;
    printVector3("Vector3<float> v1", v1);

    nmr::Vector3<float> v2(1, 2, 3);
    printVector3("Vector3<float> v2(1, 2)", v2);

    printSubTitle("float array[] = {4, 5, 6};");
    float array[] = {4, 5, 6};
    nmr::Vector3<float> v3(array);
    printVector3("Vector3<float> v3(array)", v3);
}

#endif /* Numerics_Test_Vector3_h */
