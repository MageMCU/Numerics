//
// Carpenter Software
// File: main.cpp
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
// Testing: DeltaTime.h & Motion.h
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

#include <Arduino.h>

#include "Vector2.h"
#include "Vector3.h"
#include "Point2.h"
#include "Point3.h"
#include "Matrix.h"
#include "Quaternion.h"

// Common utility function
#include "TESTS/Common.h"
// recommended to un-comment one at a time...
// Sync includes with each set of test functions.
#include "TESTS/TestVector2.h"
#include "TESTS/TestVector3.h"
#include "TESTS/TestPoint2.h"
#include "TESTS/TestPoint3.h"
#include "TESTS/TestMatrix.h"
#include "TESTS/TestQuaternion.h"

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

  // Quaternion Tests ---------------------- NEARLY COMPLETED
  Quaternion_T8_QuaternionMultiplication();
  // Quaternion_T7_Inverse();
  // Quaternion_T6_Conjugate();
  // Quaternion_T5_UnitQuaternion();
  // Quaternion_T4_Scale();
  // Quaternion_T3_Norm();
  // Quaternion_T2_NormSquared();
  // Quaternion_T1_Constructor();

  // Matrix Tests -------------------------- COMPLETED
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
  // put your main code here, to run repeatedly:
}
