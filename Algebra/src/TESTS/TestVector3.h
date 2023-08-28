//
// Carpenter Software
// File: TestVector3.h
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

#ifndef Numerics_Test_Vector3_h
#define Numerics_Test_Vector3_h

#include "../TESTS/Common.h"

void Vector3_T15_COPY()
{
    printTitle("Vector3 COPY using the equal sign");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    printSubTitle("v2 = v1; does not always work unless using an operator=");
    nmr::Vector3<float> v2 = v1;
    printVector3("v2 = v1", v2);
}

void Vector3_T14_CrossProduct()
{
    printTitle("Vector3 Cross Product");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(4, 5, 6);
    printVector3("v2", v2);

    nmr::Vector3<float> v3 = v1 ^ v2;
    printVector3("v3 = v1 ^ v2", v3);

    printSubTitle("Test for perpendicularity");

    float dot1 = v1 * v3;
    Serial.print("dot1 = v1 * v3 ");
    Serial.println(dot1);

    float dot2 = v2 * v3;
    Serial.print("dot2 = v2 * v3 ");
    Serial.println(dot2);
}

void Vector3_T13_DotProduct()
{
    printTitle("Vector3 Dot Product");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(4, 5, 6);
    printVector3("v2", v2);

    float dot = v1 * v2;
    Serial.print("dot = v1 * v2 ");
    Serial.println(dot);
}

void Vector3_T12_VectorVectorSubtraction()
{
    printTitle("Vector3 Vector Vector Subtraction");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(4, 5, 6);
    printVector3("v2", v2);

    nmr::Vector3<float> v3 = v1 - v2;
    printVector3("v3 = v1 - v2", v3);
}

void Vector3_T11_VectorVectorAddition()
{
    printTitle("Vector3 Vector Vector Addition");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(4, 5, 6);
    printVector3("v2", v2);

    nmr::Vector3<float> v3 = v1 + v2;
    printVector3("v3 = v1 + v2", v3);
}

void Vector3_T10_VectorScalarProduct()
{
    printTitle("Vector3 Vector Scalar Product");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    float scalar = 3;
    printResult("scalar: ", scalar);

    nmr::Vector3<float> v2 = v1 * scalar;
    printVector3("v2 = v1 * scalar", v2);
}

void Vector3_T9_NegateVector()
{
    printTitle("Vector3 Negate Vector");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2 = -v1;
    printVector3("v2 = -v1", v2);
}

void Vector3_T8_ProjV()
{
    printTitle("Vector3 Project v1 onto v2");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(4, 5, 6);
    printVector3("v2", v2);

    nmr::Vector3<float> v3 = v1.ProjV(v2);
    printVector3("v3 = v1.ProjV(v2)", v3);

    float angle = v1.Angle(v2) * RAD_TO_DEG;
    Serial.print("angle = v1.Angle(v2) * RAD_TO_DEG ");
    Serial.println(angle);

    angle = v1.Angle(v3) * RAD_TO_DEG;
    Serial.print("angle = v1.Angle(v3) * RAD_TO_DEG ");
    Serial.println(angle);

    printSubTitle("Zero Degrees");
    angle = v2.Angle(v3) * RAD_TO_DEG;
    Serial.print("angle = v2.Angle(v3) * RAD_TO_DEG ");
    Serial.println(angle);

    printSubTitle("Normalized v2 & v3 have identical directions if dot is ONE");
    float dot = v2.Normalize() * v3.Normalize();
    Serial.print(" dot = v2.Normalize() * v3.Normalize() ");
    Serial.println(dot);
}

void Vector3_T7_Angle()
{
    printTitle("Vector3 Angle");

    nmr::Vector3<float> v1(1, 0, 0);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(0, 0, -1);
    printVector3("v2", v2);

    float angle = v1.Angle(v2) * RAD_TO_DEG;
    Serial.print("angle = v1.Angle(v2) * RAD_TO_DEG ");
    Serial.println(angle);
}

void Vector3_T6_A_UnitCross_Product()
{
    printTitle("Vector3 UnitCross Product");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(4, 5, 6);
    printVector3("v2", v2);

    nmr::Vector3<float> v3 = v1.Cross(v2);
    printVector3("v3 = v1.Cross(v2)", v3);

    nmr::Vector3<float> v4 = v1.UnitCross(v2);
    printVector3("v4 = v1.UnitCross(v2)", v4);

    nmr::Vector3<float> v5 = v3.Normalize();
    printVector3("v5 = v3.Normalize()", v5);

    float mag = v5.Magnitude();
    printResult("v5.Magnitude() ", mag);
}

void Vector3_T6_Cross_Product()
{
    printTitle("Vector3 Cross Product");

    nmr::Vector3<float> v1(1, 0, 0);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(0, 1, 0);
    printVector3("v2", v2);

    nmr::Vector3<float> v3 = v1.Cross(v2);
    printVector3("v3 = v1.Cross(v2)", v3);

    nmr::Vector3<float> v4 = v1 ^ v2;
    printVector3("v4 = v1 ^ v2", v4);
}

void Vector3_T5_Dot_Product()
{
    printTitle("Vector3 Dot Product");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2(4, 5, 6);
    printVector3("v2", v2);

    float dot = v1.Dot(v2);
    Serial.print("dot = v1.Dot(v2) ");
    Serial.println(dot);

    dot = v1 * v2;
    Serial.print("dot = v1 * v2 ");
    Serial.println(dot);
}

void Vector3_T4_UnitVector_Normalize()
{
    printTitle("Vector3 UnitVector & Normalize");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    nmr::Vector3<float> v2 = v1.UnitVector();
    printVector3("v2 = v1.UnitVector", v2);

    float magnitude = v2.Magnitude();
    Serial.print("magnitude = v2.Magnitude ");
    Serial.println(magnitude);

    nmr::Vector3<float> v3 = v1.Normalize();
    printVector3("v3 = v1.Normalize", v3);

    float distance = v3.Distance();
    Serial.print("distance = v3.Distance ");
    Serial.println(distance);
}

void Vector3_T3_Magnitude_Distance()
{
    printTitle("Vector3 Magnitude & Distance");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);

    float magnitude = v1.Magnitude();
    Serial.print("magnitude ");
    Serial.println(magnitude);

    float distance = v1.Distance();
    Serial.print("distance ");
    Serial.println(distance);
}

void Vector3_T2_GetVector()
{
    printTitle("Vector3 GetVector");

    nmr::Vector3<float> v1(1, 2, 3);
    printVector3("v1", v1);
    nmr::Vector3<float> v2 = v1.GetVector();
    printVector3("v2 = v1.GetVector", v2);
}

void Vector3_T1_Constructor()
{
    printTitle("Vector3 Constructor Test V1");
    printSubTitle("Notice no parenthesis used in the default constructor.");

    nmr::Vector3<float> v1;
    printVector3("Vector3<float> v1", v1);

    nmr::Vector3<float> v2(1, 2, 3);
    printVector3("Vector3<float> v2(1, 2, 3)", v2);

    printSubTitle("float array[] = {4, 5, 6};");
    float array[] = {4, 5, 6};
    nmr::Vector3<float> v3(array);
    printVector3("Vector3<float> v3(array)", v3);
}

#endif /* Numerics_Test_Vector3_h */
