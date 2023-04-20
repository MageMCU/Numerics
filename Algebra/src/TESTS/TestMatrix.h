//
// Carpenter Software
// File: TestMatrix.h
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

#ifndef Numerics_Test_Matrix_h
#define Numerics_Test_Matrix_h

#include "../TESTS/Common.h"

void Matrix_T9_MatrixMatrixMultiplication()
{
    printTitle("Matrix T8 Matrix Matrix Multiplication");

    float array1[] = {1, 2, 3, 4};
    
    nmr::Matrix<float> A(array1, nmr::a2x2);
    printMatrix("A", A);

    nmr::Matrix<float> I;
    printMatrix("I", I);

    nmr::Matrix<float> C = A * I;
    printMatrix("A * I = C", C);
    
    nmr::Matrix<float> B(array1, nmr::a2x2);
    printMatrix("B", B);

    C = A * B;
    printMatrix("A * B = C", C);
}

void Matrix_T8_MatrixVectorMultiplication()
{
    printTitle("Matrix T8 Matrix Vector Multiplication");

    nmr::Matrix<float> A;
    printMatrix("A", A);
    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);
    nmr::Vector2<float> v2 = A * v1;
    printVector2("v2 = A * v1", v2);

    nmr::Matrix<float> B;
    printMatrix("B", B);
    nmr::Vector3<float> v3(1, 2, 3);
    printVector3("v3", v3);
    nmr::Vector3<float> v4 = B * v3;
    printVector3("v4 = B * v3", v4);

    float array1[] = {1, 2, 3, 4};
    nmr::Matrix<float> C(array1, nmr::a2x2);
    printMatrix("C", C);
    nmr::Vector2<float> v5(1, 2);
    printVector2("v5", v5);
    nmr::Vector2<float> v6 = C * v5;
    printVector2("v6 = C * v5", v6);

    float array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> D(array2, nmr::a3x3);
    printMatrix("D", D);
    nmr::Vector3<float> v7(1, 2, 3);
    printVector3("v7", v7);
    nmr::Vector3<float> v8 = D * v7;
    printVector3("v8 = D * v7", v8);
}

void Matrix_T7_MatrixScalarMultiplication()
{
    printTitle("Matrix T7 Matrix Scalar Multiplication");

    float array1[] = {1, 2, 3, 4};
    nmr::Matrix<float> A(array1, nmr::a2x2);
    printMatrix("A", A);
    float a = 3;
    Serial.println("a = 3");
    nmr::Matrix<float> B = A * a;
    printMatrix("B = A * a", B);

    float array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> C(array2, nmr::a3x3);
    printMatrix("C", C);
    nmr::Matrix<float> D = C * -4;
    printMatrix("D = C * -4", D);
}

void Matrix_T6_Negate()
{
    printTitle("Matrix T6 Negate Matrix");

    float array1[] = {1, 2, 3, 4};
    nmr::Matrix<float> A(array1, nmr::a2x2);
    printMatrix("A", A);
    nmr::Matrix<float> B = -A.Transpose();
    printMatrix("B = -A.Transpose()", B);

    float array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> C(array2, nmr::a3x3);
    printMatrix("C", C);
    nmr::Matrix<float> D = -C.Transpose();
    printMatrix("D = -C.Transpose()", D);
}

void Matrix_T5_Transpose()
{
    printTitle("Matrix T5 Transpose");

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

void Matrix_T4_Determinant_IsInvertible()
{
    printTitle("Matrix T4 Determinant - IsInvertible");

    nmr::Vector2<float> aRow1(2, 3);
    nmr::Vector2<float> aRow2(1, 4);
    // det = 5
    nmr::Matrix<float> A(aRow1, aRow2);
    printMatrix("A(aRow1, aRow2)", A);
    if (A.IsInvertible())
        Serial.println("Matrix A is Invertible: ");
    else
        Serial.println("Matrix A is not Invertible: ");
    Serial.print("Has determinant: ");
    Serial.println(A.Determinant());

    float array2[] = {3, 2, -1, 2, 4, 2, 1, 3, 2};
    // det = 0
    nmr::Matrix<float> B(array2, nmr::a3x3);
    printMatrix("B(array2, nmr::a3x3)", B);
    if (B.IsInvertible())
        Serial.println("Matrix B is Invertible: ");
    else
        Serial.println("Matrix B is not Invertible...");
    Serial.print("Has determinant: ");
    Serial.println(B.Determinant());

    nmr::Vector3<float> cRow1(2, -5, 3);
    nmr::Vector3<float> cRow2(1, 3, 4);
    nmr::Vector3<float> cRow3(-2, 3, 7);
    // det = 120
    nmr::Matrix<float> C(cRow1, cRow2, cRow3);
    printMatrix("C(bRow1, bRow2, bRow3)", C);
    if (C.IsInvertible())
        Serial.println("Matrix C is Invertible: ");
    else
        Serial.println("Matrix C is not Invertible...");
    Serial.print("Has determinant: ");
    Serial.println(C.Determinant());
}

void Matrix_T3_GetMatrix()
{
    printTitle("Matrix T3 Get Matrix");

    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> A(array, nmr::a3x3);
    printMatrix("A(array, nmr::a3x3)", A);

    nmr::Matrix<float> B = A.GetMatrix();
    printMatrix("B = A.GetMatrix", B);
}

void Matrix_T2_Getters_NoSetters()
{
    printTitle("Matrix T2 Getters - no Setters");

    nmr::Vector3<float> aRow1(1, 2, 3);
    nmr::Vector3<float> aRow2(4, 5, 6);
    nmr::Vector3<float> aRow3(7, 8, 9);
    nmr::Matrix<float> A(aRow1, aRow2, aRow3);
    printMatrix("A(aRow1, aRow2, aRow3)", A);

    float e02 = A.Element(0, 2);
    Serial.print("e02 ");
    Serial.println(e02);

    float rowSize = A.GetRowSizeSquareMatrix();
    Serial.print("rowSize ");
    Serial.println(rowSize);

    float matrixSize = A.GetSizeSquareMatrix();
    Serial.print("matrixSize ");
    Serial.println(matrixSize);
}

void Matrix_T1_Constructor()
{
    printTitle("Matrix T1 Constructor");
    nmr::Matrix<float> A;
    printMatrix("Matrix<float> A", A);

    printSubTitle("2x2 matrix using 2 vectos.");
    nmr::Vector2<float> bRow1(1, 2);
    nmr::Vector2<float> bRow2(3, 4);
    nmr::Matrix<float> B(bRow1, bRow2);
    printMatrix("B(bRow1, bRow2)", B);

    printSubTitle("3x3 matrix using 3 vectors.");
    nmr::Vector3<float> cRow1(1, 2, 3);
    nmr::Vector3<float> cRow2(4, 5, 6);
    nmr::Vector3<float> cRow3(7, 8, 9);
    nmr::Matrix<float> C(cRow1, cRow2, cRow3);
    printMatrix("C(cRow1, cRow2, cRow3)", C);

    printSubTitle("array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}");
    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    nmr::Matrix<float> D(array, nmr::a3x3);
    printMatrix(" D(array, nmr::a3x3)", D);
}

#endif /* Numerics_Test_Matrix_h */