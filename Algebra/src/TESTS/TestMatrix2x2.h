//
// Carpenter Software
// File: TestMatrix2x2.h
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

#ifndef Numerics_Test_Matrix2x2_h
#define Numerics_Test_Matrix2x2_h

#include "../TESTS/Common.h"

void Matrix2x2_T7_Solve()
{
    printTitle("Matrix2x2 T7 Solve");

    nmr::Matrix2x2<float> A((float)3, (float)2, (float)2, (float)4);
    printMatrix2x2("A: ", A);
    nmr::Vector2<float> b(5, -2);
    printVector2("b: ", b);
    printVector2("Ax = b where x: ", A.Solve(b));
}

void Matrix2x2_T6_Inverse()
{
    printTitle("Matrix2x2 T6 Inverse");

    nmr::Matrix2x2<float> m1((float)1, (float)2, (float)3, (float)4);
    printMatrix2x2("Original", m1);
    printMatrix2x2("Inverse", m1.Inverse());
}

void Matrix2x2_T5_Transpose()
{
    printTitle("Matrix2x2 T5 Transpose");

    nmr::Matrix2x2<float> m1((float)1, (float)2, (float)3, (float)4);
    printMatrix2x2("Original", m1);
    printMatrix2x2("Transpose", m1.Transpose());
}

void Matrix2x2_T4_Determinate()
{
    printTitle("Matrix2x2 T4 Determinate");

    nmr::Matrix2x2<float> m1((float)1, (float)2, (float)3, (float)4);
    printResult("Determinate: ", m1.Determinant());
}

void Matrix2x2_T3_IsInvertible()
{
    printTitle("Matrix2x2 T3 IsInvertible");

    nmr::Matrix2x2<float> m1((float)1, (float)2, (float)3, (float)4);
    if (m1.IsInvertible())
        Serial.println("Is Invertible");
    else
        Serial.println("Is not Invertible");

    nmr::Matrix2x2<float> m2((float)1, (float)2, (float)2, (float)4);
    if (m2.IsInvertible())
        Serial.println("Is Invertible");
    else
        Serial.println("Is not Invertible");
}

void Matrix2x2_T2_Getters()
{
    printTitle("Matrix2x2 T2 Getters");

    nmr::Matrix2x2<float> m1((float)1, (float)2, (float)3, (float)4);

    Serial.print(String(m1.E11(), 2));
    Serial.print(" ");
    Serial.println(String(m1.E12(), 2));

    Serial.print(String(m1.E21(), 2));
    Serial.print(" ");
    Serial.println(String(m1.E22(), 2));
}

void Matrix2x2_T1_Constructor()
{
    printTitle("Matrix2x2 T1 Constructor");

    nmr::Matrix2x2<float> m1;
    printMatrix2x2("m1", m1);

    nmr::Matrix2x2<float> m2((float)1, (float)2, (float)3, (float)4);
    printMatrix2x2("m2", m2);
}

#endif
