//
// Carpenter Software
// File: TestMatrices.h
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

#ifndef Numerics_Test_Matrices_h
#define Numerics_Test_Matrices_h

#include "../TESTS/Common.h"

void matrixScalarMultiplicationTestM9()
{
    printTitle("Matrix Scalar Multiplication Test M9");

    float array[] = {1, 2, 3, 4};
    nmr::Matrix<float> A(array, nmr::a2x2);
    printMatrix("A", A);
    float s = 3;
    Serial.print("s: ");
    Serial.println(s);
    A = A * s;
    printMatrix("A = A * s", A);
}

void matrixNegationTestM8()
{
    printTitle("Matrix Negation Test M8");

    float array[] = {1, 2, 3, 4};
    nmr::Matrix<float> A(array, nmr::a2x2);
    printMatrix("A", A);

    A = -A;
    printMatrix("A", A);
}

void matrixCopyMatrixTestM7()
{
    printTitle("Matrix Copy Matrix Test M7");

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> A(array, nmr::a3x3);
    printMatrix("A", A);

    // Create a Identity Matrix B
    nmr::Matrix<float> B;
    printMatrix("B", B);

    // Copy (assign) A into Matrix B
    // B here has been reassigned from
    // an identity matrix to the contents
    // of matrix A...
    B = A;
    printMatrix("B = A", B);
}

void matrixMatrixMultiplicationTestM6()
{
    printTitle("Matrix Matrix Multiplication Test M6");

    nmr::Matrix<float> I;
    printMatrix("I", I);

    printSubTitle("3x3 Identity Multiplication");
    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> A(array, nmr::a3x3);
    printMatrix("A", A);

    nmr::Matrix<float> B = A * I;
    printMatrix("B = A * I", B);

    nmr::Matrix<float> C = I * A;
    printMatrix("C = I * A", C);

    printSubTitle("3x3 Matrix Multiplication");
    float array1[] = {3, 1, -4, 1, 1, 0, -1, 1, 2};
    nmr::Matrix<float> D(array1, nmr::a3x3);
    printMatrix("D", D);

    float array2[] = {1, -2, -1, 6, -1, 0, 1, 0, 0};
    nmr::Matrix<float> E(array2, nmr::a3x3);
    printMatrix("E", E);

    // Ref: [ELA] by Shields, 1980. p.60 (5a), 477 (ans).
    // ans: 5, -7, -3, 7, -3, -1, 7, 1, 1
    C = D * E;
    printMatrix("C = D * E", C);

    printSubTitle("2x2 Matrix Multiplication");
    float array3[] = {3, 1, -4, 1};
    // nmr::Matrix<float> F(array3, nmr::a2x2);
    nmr::Matrix<float> G(array3, nmr::a2x2);
    printMatrix("G", G);

    float array4[] = {1, -2, -1, 6};
    nmr::Matrix<float> H(array4, nmr::a2x2);
    printMatrix("H", H);

    C = G * H;
    printMatrix("C = G * H", C);
}

void matrixVectorMultiplicationTestM5()
{
    printTitle("Matrix Vector Multiplication Test M5");

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> A(array, nmr::a3x3);
    printMatrix("A", A);

    nmr::Vector<float> v(1, 2, 3);
    printVector("v(1, 2, 3)", v);

    nmr::Vector<float> result = A * v;
    printVector("result = A * v", result);
}

void matrixTransposeTestM4()
{
    printTitle("Matrix Determinant Test M4");

    float array1[] = {1, 2, 3, 4};
    nmr::Matrix<float> A(array1, nmr::a2x2);
    printMatrix("A", A);
    nmr::Matrix<float> B = A.Transpose();
    printMatrix("B = A.Transpose()", B);

    float array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> C(array2, nmr::a3x3);
    printMatrix("C", C);
    nmr::Matrix<float> D = C.Transpose();
    printMatrix("D = C.Transpose()", D);
}

void matrixDeterminantTestM3()
{
    printTitle("Matrix Determinant Test M3");

    float array[] = {1, 2, 4, 1, 2, 3, 2, 1, 0};
    // Ref: acronym [LA T,I,C] by Cohen, 2021, p,310.
    // Ans: -3
    nmr::Matrix<float> A(array, nmr::a3x3);
    printMatrix("A", A);
    float det = A.Determinant();
    Serial.print("det = A.Determinant(): ");
    Serial.println(det);
    if (A.IsInvertible())
        Serial.println("Invertible YES");
    else
        Serial.println("Invertible NO");
}

void matrixElementTestM2()
{
    printTitle("Matrix Constructor Test M2");

    printSubTitle("array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}");
    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> A(array, nmr::a3x3);
    printMatrix("A", A);

    float element21 = A.Element(2, 1);
    Serial.print("element21 = A.Element(2, 1): ");
    Serial.println(element21);
}

void matrixConstructorTestM1()
{
    printTitle("Matrix Constructor Test M1");

    nmr::Matrix<float> A;
    printMatrix("Matrix<float> A", A);

    printSubTitle("2x2 matrix using 2 vectos.");
    nmr::Vector<float> aRow1(1, 2);
    nmr::Vector<float> aRow2(3, 4);
    nmr::Matrix<float> B(aRow1, aRow2);
    printMatrix("B(aRow1, aRow2)", B);

    printSubTitle("3x3 matrix using 3 vectors.");
    nmr::Vector<float> bRow1(1, 2, 3);
    nmr::Vector<float> bRow2(4, 5, 6);
    nmr::Vector<float> bRow3(7, 8, 9);
    nmr::Matrix<float> C(bRow1, bRow2, bRow3);
    printMatrix("C(bRow1, bRow2, bRow3)", C);

    printSubTitle("array[] = {1, 2, 3, 4}");
    float array1[] = {1, 2, 3, 4};
    nmr::Matrix<float> D(array1, nmr::a2x2);
    printMatrix("Matrix<float> D()", D);

    printSubTitle("array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}");
    float array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> E(array2, nmr::a3x3);
    printMatrix("Matrix<float> E()", E);
}

void DontKillTheRedundancy() {}

#endif