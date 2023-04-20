//
// Carpenter Software
// File: Main main.cpp
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
// Testing: DeltaTime.h & Motion.h
//
// Algebra OOP Library
// The math is underneath the namespace
// called Numerics as in numeric computation.
//
// By Jesse Carpenter (carpentersoftware.com)
//
// CHANGELOG
// Created 20221008
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

  // Matrix3x3 Test ----------------------- Working
  // Pendin

  // Matrix2x2 Test ----------------------- Completed
  Matrix2x2_T12_Rotation();
  // Matrix2x2_T11_Identity();
  // Matrix2x2_T10_MatrixMatrixMultiplication();
  // Matrix2x2_T9_MatrixScalarMultiplication();
  // Matrix2x2_T8_UnitaryOperation();
  // Matrix2x2_T7_Solve();
  // Matrix2x2_T6_Inverse();
  // Matrix2x2_T5_Transpose();
  // Matrix2x2_T4_Invertible();
  // Matrix2x2_T3_Determinate();
  // Matrix2x2_T2_Getters();
  // Matrix2x2_T1_Constructor();

  // Statistics Test ---------------------- Working
  // Statistics_T5_Queue();
  // Statistics_T4_Median();
  // Statistics_T3_Standard_Deviation();
  // Statistics_T2_Average();
  // Statistics_T1_Constructor();

  // RandomNumber Test -------------------- COMPLETED
  // Caught several bugs here 20230127 jc
  // RandomNumber_T1_Inclusive_Test();

  // The following also includes ** RandomNuber.h **
  // LinearMap Tests ---------------------- COMPLETED
  // LinearMap_T2_Reverse();
  // LinearMap_T1_Inclusive_Test();

  // Timer Tests ----------------------- COMPLETED
  // Timer_T1_Inclusive_Test();

  // MiscMath Tests -------------------- COMPLETED
  // MiscMath_T5_DirectionVector();
  // MiscMath_T4_DirectionComponents();
  // MiscMath_T3_Angle2Radian();
  // MiscMath_T2_AngleRadian();
  // MiscMath_T1_Map();

  // Bitwise Tests ---------------------- COMPLETED
  // Bitwise_T5_GetBitsValue();
  // Bitwise_T4_SetBitsValue();
  // Bitwise_T3_ClearBitNUmber();
  // Bitwise_T2_SetBitNumber();
  // Bitwise_T1_Contructor();

  // Quaternion Tests ---------------------- NEARLY COMPLETED
  // Quaternion_T9_Quaternion_to_Angle_Axis(); // Further Testing
  // Quaternion_T8_QuaternionMultiplication();
  // Quaternion_T7_Inverse();
  // Quaternion_T6_Conjugate();
  // Quaternion_T5_UnitQuaternion();
  // Quaternion_T4_Scale();
  // Quaternion_T3_Norm();
  // Quaternion_T2_NormSquared();
  // Quaternion_T1_Constructor();

  // Matrix Tests -------------------------- COMPLETED
  // Matrix_T9_MatrixMatrixMultiplication(); ------------------- FIXME
  // Matrix_T8_MatrixVectorMultiplication();
  // Matrix_T7_MatrixScalarMultiplication();
  // Matrix_T6_Negate();
  // Matrix_T5_Transpose();
  // Matrix_T4_Determinant_IsInvertible();
  // Matrix_T3_GetMatrix();
  // Matrix_T2_Getters_NoSetters();
  // Matrix_T1_Constructor();

  // Point3 Tests -------------------------- COMPLETED
  // Point3_T4_PointFromPointVectorAddition();
  // Point3_T3_VectorFromPointPointSubtraction();
  // Point3_T2_GetPoint();
  // Point3_T1_Constructor();

  // Point2 Tests -------------------------- COMPLETED
  // Point2_T4_PointFromPointVectorAddition();
  // Point2_T3_VectorFromPointPointSubtraction();
  // Point2_T2_GetPoint();
  // Point2_T1_Constructor();

  // Vector3 Tests ------------------------- COMPLETED
  // Vector3_T15_COPY();
  // Vector3_T14_CrossProduct();
  // Vector3_T13_DotProduct();
  // Vector3_T12_VectorVectorSubtraction();
  // Vector3_T11_VectorVectorAddition();
  // Vector3_T10_VectorScalarProduct();
  // Vector3_T9_NegateVector();
  // Vector3_T8_ProjV();
  // Vector3_T7_Angle();
  // Vector3_T6_Cross_Product();
  // Vector3_T5_Dot_Product();
  // Vector3_T4_UnitVector_Normalize();
  // Vector3_T3_Magnitude_Distance();
  // Vector3_T2_GetVector();
  // Vector3_T1_Constructor();

  // Vector2 Tests ------------------------- COMPLETED
  // Vector2_T15_COPY();
  // Vector2_T14_DotProduct();
  // Vector2_T13_VectorVectorSubtraction();
  // Vector2_T12_VectorVectorAddition();
  // Vector2_T11_VectorScalarProduct();
  // Vector2_T10_NegateVector();
  // Vector2_T9_ProjV();
  // Vector2_T8_PerpDot();
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
  // Un-comment when testing DeltaTime.h
  //
  // DeltaTimeLoop();
}
