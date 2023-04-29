//
// Carpenter Software
// File: TestMatrix3x3.h
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

#ifndef Numerics_Test_Matrix3x3_h
#define Numerics_Test_Matrix3x3_h

#include "../TESTS/Common.h"

void Matrix3x3_T8_Solve()
{
    printTitle("Matrix3x3 T8 Solve (+Cramer)");

    float array[] = {1, 2, 1, 2, 2, 1, 1, 2, 3};
    nmr::Matrix3x3<float> A(array);
    printMatrix3x3("*A(array): ", A);

    nmr::Vector3<float> b(5, 6, 9);
    printVector3("*b(5, 6, 9): ", b);

    nmr::Matrix3x3<float> Ainv = A.Inverse();
    printMatrix3x3("*Ainv: ", Ainv);

    // Solve Ax = b; x = Ainv(b)
    nmr::Vector3<float> x = Ainv.Solve(b);
    printVector3("*Ainv.Solve(b): ", x);

    // Alternate Solution
    x = A.Cramer(b);
    printVector3("*A.Cramer(b): ", x);

}

void Matrix3x3_T7_Inverse()
{
    printTitle("Matrix3x3 T7 Inverse");

    float array[] = {2, 1, 2, 3, 2, 2, 1, 2, 3};
    nmr::Matrix3x3<float> M(array);
    printMatrix3x3("M(array): ", M);
    M = M.Inverse();
    printMatrix3x3("M.Inverse(): ", M);
    // Verified Output
    
}

void Matrix3x3_T6_Adjoint()
{
    printTitle("Matrix3x3 T6 Adjoint");

    float array[] = {2, 1, 2, 3, 2, 2, 1, 2, 3};
    nmr::Matrix3x3<float> M(array);
    printMatrix3x3("M(array): ", M);
    M = M.Adjoint();
    printMatrix3x3("M.Adjoint(): ", M);
}

void Matrix3x3_T5_Transpose()
{
    printTitle("Matrix3x3 T5 Transpose");

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix3x3<float> M(array);
    printMatrix3x3("M(array): ", M);
    M = M.Transpose();
    printMatrix3x3("M.Transpose(): ", M);

}

void Matrix3x3_T4_Invertible()
{
    printTitle("Matrix3x3 T4 Invertible");

    float min = -1.0;
    float max = 1.0;
    nmr::Matrix3x3<float> M(min, max);
    printMatrix3x3("M(-1.0, 1.0): ", M);
    float det = M.Determinant();
    printResult("det: ", det);
    if (M.Invertible())
        Serial.println("M is invertible...");
    else
        Serial.println("M is NOT invertible...");
}

void Matrix3x3_T3_Determinate()
{
    printTitle("Matrix3x3 T3 Determinate");

    float min = -9.0;
    float max = 9.0;
    nmr::Matrix3x3<float> M(min, max);
    printMatrix3x3("M(-9.0, 9.0): ", M);
    float det = M.Determinant();
    printResult("det: ", det);
}

void Matrix3x3_T2_Access()
{
    printTitle("Matrix3x3 T2 Access");

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix3x3<float> M(array);
    printMatrix3x3("M(array): ", M);
    int index = M.GetIndex(0, 1);
    float element = M.GetElement(index);

    Serial.print("M.GetElement(");
    Serial.print(index);
    printResult("): ",element);

    M.SetElement(1, 2.05);
    printMatrix3x3("M.SetElement(1, 2.05): ", M);

}

void Matrix3x3_T1_Constructor()
{
    printTitle("Matrix3x3 T1 Constructor");

    nmr::Matrix3x3<float> M1;
    printMatrix3x3("M(): ", M1);

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix3x3<float> M2(array);
    printMatrix3x3("M(array): ", M2);

    float min = 0.001;
    float max = 0.999;
    nmr::Matrix3x3<float> M3(min, max);
    printMatrix3x3("M(0.001, 0.999): ", M3);
}

#endif
