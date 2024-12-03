//
// Carpenter Software
// File: main.cpp
// Github: MageMCU
// Repository: Numerics
// Folder: MAIN
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

#include <Arduino.h>

// Common utility functions.
#include "TESTS/Common.h"
#include "TESTS/TestBitwise.h"
#include "TESTS/TestButton.h"
#include "TESTS/TestLinearMap.h"
#include "TESTS/TestMatrix.h"
#include "TESTS/TestMatrix2x2.h"
#include "TESTS/TestMatrix3x3.h"
#include "TESTS/TestMatrix4x4.h"
#include "TESTS/TestMiscMath.h"
#include "TESTS/TestPoint2.h"
#include "TESTS/TestPoint3.h"
#include "TESTS/TestQuaternion.h"
#include "TESTS/TestRandomNumber.h"
#include "TESTS/TestStatistics.h"
#include "TESTS/TestTimer.h"
#include "TESTS/TestTypeConv.h"
#include "TESTS/TestVector2.h"
#include "TESTS/TestVector3.h"

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        /* code */
    }

    //
    // --------------------------------------
    // TESTING IN PROGRESS
    // --------------------------------------

    // Bitwise Tests ----------------------- 20241201 ok
    // Bitwise_T6_ReverseBits();
    // Bitwise_T5_GetBitsValue();
    // Bitwise_T4_SetBitsValue();
    // Bitwise_T3_ClearBitNUmber();
    // Bitwise_T2_SetBitNumber();
    // Bitwise_T1_Constructor();

    // Button Tests -------------------------
    Button_Setup();
    // See loop() for Button_Loop()
    
    // Matrix4x4 Test -----------------------
    // Matrix4x4_T2_Translation();
    // Matrix4x4_T1_Constructor();

    // Matrix3x3 Test -----------------------
    // Matrix3x3_Find_Invertible_Matrix(); // Gives Ax = b
    // Matrix3x3_T14_Rotation();
    // Matrix3x3_T13_Identity();
    // Matrix3x3_T12_MatrixMatrixMultiplication();
    // Matrix3x3_T11_MatrixVectorMultiplication();
    // Matrix3x3_T10_MatrixScalarMultiplication();
    // Matrix3x3_T9_UnitaryOperation();
    // Matrix3x3_T8_Solve(); // Includes Alternate Solve() called Cramer()...
    // Matrix3x3_T7_Inverse();
    // Matrix3x3_T6_Adjoint();
    // Matrix3x3_T5_Transpose();
    // Matrix3x3_T4_Invertible();
    // Matrix3x3_T3_Determinate();
    // Matrix3x3_T2_Access();
    // Matrix3x3_T1_Constructor();

    // Matrix2x2 Test -----------------------
    // Matrix2x2_T13_Rotation();
    // Matrix2x2_T12_Identity();
    // Matrix2x2_T11_MatrixMatrixMultiplication();
    // Matrix2x2_T10_MatrixVectorMultiplication();
    // Matrix2x2_T9_MatrixScalarMultiplication();
    // Matrix2x2_T8_UnitaryOperation();
    // Matrix2x2_T7_Solve();
    // Matrix2x2_T6_Inverse();
    // Matrix2x2_T5_Transpose();
    // Matrix2x2_T4_Invertible();
    // Matrix2x2_T3_Determinate();
    // Matrix2x2_T2_Getters();
    // Matrix2x2_T1_Constructor();

    // LinearMap Tests ---------------------- 20241201 ok
    // LinearMap_T2_Reverse();
    // LinearMap_T1_Inclusive_Test();

    // MiscMath Tests ----------------------- 20241201 ok
    // MiscMath_T6_AbsoluteValue();
    // MiscMath_T5_DirectionVector();
    // MiscMath_T4_DirectionComponents();
    // MiscMath_T3_Angle2Radian();
    // MiscMath_T2_AngleRadian();
    // MiscMath_T1_Map(); // redundant (see file LinearMap.h)

    // Point3 Tests -------------------------- 20241201 ok
    // Point3_T4_PointFromPointVectorAddition();
    // Point3_T3_VectorFromPointPointSubtraction();
    // Point3_T2_GetPoint();
    // Point3_T1_Constructor();

    // Point2 Tests -------------------------- 20241201 ok
    // Point2_T4_PointFromPointVectorAddition();
    // Point2_T3_VectorFromPointPointSubtraction();
    // Point2_T2_GetPoint();
    // Point2_T1_Constructor();

    // RandomNumber Test -------------------- 20241201 ok
    // RandomNumber_T1_RandomNumber_Test();

    // Statistics Test ---------------------- 20241201 ok
    // Statistics_T6_Queue();
    // Statistics_T5_Queue();
    // Statistics_T4_Median();
    // Statistics_T3_Standard_Deviation();
    // Statistics_T2_Average();
    // Statistics_T1_Constructor();

    // Quaternion Tests ---------------------- 20241201 ok
    // Quaternion_T9_Quaternion_to_Angle_Axis();
    // Quaternion_T8_QuaternionMultiplication();
    // Quaternion_T7_Inverse();
    // Quaternion_T6_Conjugate();
    // Quaternion_T5_UnitQuaternion();
    // Quaternion_T4_Scale();
    // Quaternion_T3_Norm();
    // Quaternion_T2_NormSquared();
    // Quaternion_T1_Constructor();

    // Timer Tests --------------------------- 20241201 ok
    // Timer_T1_Inclusive_Test();

    // TypeConv Tests ------------------------ 20241201 ok
    // TypeConv_T2_DWordTo4Bytes();
    // TypeConv_T1_WordTo2Bytes();

    // Vector3 Tests ------------------------- 20241201 ok
    // Vector3_T15_COPY();
    // Vector3_T14_CrossProduct();
    // Vector3_T13_DotProduct();
    // Vector3_T12_VectorVectorSubtraction();
    // Vector3_T11_VectorVectorAddition();
    // Vector3_T10_VectorScalarProduct();
    // Vector3_T9_NegateVector();
    // Vector3_T8_ProjV();
    // Vector3_T7_Angle();
    // Vector3_T6_A_UnitCross_Product();
    // Vector3_T6_Cross_Product();
    // Vector3_T5_Dot_Product();
    // Vector3_T4_UnitVector_Normalize();
    // Vector3_T3_Magnitude_Distance();
    // Vector3_T2_GetVector();
    // Vector3_T1_Constructor();

    // Vector2 Tests ------------------------- 20241201 ok
    // Vector2_T15_COPY();
    // Vector2_T14_DotProduct();
    // Vector2_T13_VectorVectorSubtraction();
    // Vector2_T12_VectorVectorAddition();
    // Vector2_T11_VectorScalarProduct();
    // Vector2_T10_NegateVector();
    // Vector2_T9_ProjV();
    // Vector2_T8_A_ZComp();
    // Vector2_T8_DotPerp();
    // Vector2_T7_A_UnitPerp(); // New
    // Vector2_T7_Perp();
    // Vector2_T6_Angle();
    // Vector2_T5_Dot_Product();
    // Vector2_T4_UnitVector_Normalize();
    // Vector2_T3_Magnitude_Distance();
    // Vector2_T2_GetVector();
    // Vector2_T1_Constructor();
}

void loop()
{
    Button_Loop();
}
