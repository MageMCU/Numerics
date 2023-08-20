//
// Carpenter Software
// File: TestVector2.h
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

#ifndef Numerics_Test_Vector2_h
#define Numerics_Test_Vector2_h

#include "Arduino.h"
#include "../TESTS/Common.h"

void Vector2_T15_COPY()
{
    printTitle("Vector2 COPY using the equal sign");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    printSubTitle("This does not always work unless using an operator=");
    nmr::Vector2<float> v2 = v1;
    printVector2("v2", v2);
}

void Vector2_T14_DotProduct()
{
    printTitle("Vector2 Dot Product");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2(3, 4);
    printVector2("v2", v2);

    float dot = v1 * v2;
    Serial.print("dot = v1 * v2 ");
    Serial.println(dot);
}

void Vector2_T13_VectorVectorSubtraction()
{
    printTitle("Vector2 Vector Vector Subtraction");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2(3, 4);
    printVector2("v2", v2);

    nmr::Vector2<float> v3 = v1 - v2;
    printVector2("v3 = v1 - v2", v3);
}

void Vector2_T12_VectorVectorAddition()
{
    printTitle("Vector2 Vector Vector Addition");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2(3, 4);
    printVector2("v2", v2);

    nmr::Vector2<float> v3 = v1 + v2;
    printVector2("v3 = v1 + v2", v3);
}

void Vector2_T11_VectorScalarProduct()
{
    printTitle("Vector2 Vector Scalar Product");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    float scalar = 3;

    nmr::Vector2<float> v2 = v1 * scalar;
    printVector2("v2 = v1 * scalar", v2);
}

void Vector2_T10_NegateVector()
{
    printTitle("Vector2 Negate Vector");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2 = -v1;
    printVector2("v2 = -v1", v2);
}

void Vector2_T9_ProjV()
{
    printTitle("Vector2 Project v1 onto v2");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2(3, 4);
    printVector2("v2", v2);

    nmr::Vector2<float> v3 = v1.ProjV(v2);
    printVector2("v3 = v1.ProjV(v2)", v3);

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

void Vector2_T8_A_ZComp()
{
    printTitle("Vector2 z-component of a cross prosuct");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2(3, 4);
    printVector2("v2", v2);

    float ZComp = v1.ZComp(v2);
    Serial.print("ZComp = v1.ZComp(v2) ");
    Serial.println(ZComp);
}

void Vector2_T8_DotPerp()
{
    printTitle("Vector2 Dot-Perpendicular Product");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2(3, 4);
    printVector2("v2", v2);

    float DotPerp = v1.DotPerp(v2);
    Serial.print("DotPerp = v1.DotPerp(v2) ");
    Serial.println(DotPerp);

    nmr::Vector3<float> v3(1, 2, 0);
    printVector3("v3", v3);

    nmr::Vector3<float> v4(3, 4, 0);
    printVector3("v4", v4);

    nmr::Vector3<float> v5 = v3 ^ v4;
    float zComponent = v5.z();
    Serial.print("zComponent = v5.z() ");
    Serial.println(zComponent);

    printSubTitle("Notice PerpDot and zComponent must be equal...");
}

void Vector2_T7_A_UnitPerp()
{
    printTitle("Vector2 Unit-Perpendicular");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2 = v1.Perp();
    printVector2("v2 = v1.Perp()", v2);

    float mag = v2.Magnitude();
    Serial.print("mag = v1 * v2 = ");
    Serial.println(mag);

    // Comparison with Perp()
    nmr::Vector2<float> v3 = v1.UnitPerp();
    printVector2("v3 = v1.UnitPerp()", v3);

    printSubTitle("The dot product of perpendicular vectors ought to be zero...");
    float dot = v1 * v2;
    Serial.print("dot = v1 * v2 = ");
    Serial.println(dot);
    // zero result
    dot = v1 * v3;
    Serial.print("dot = v1 * v3 = ");
    Serial.println(dot);
}

void Vector2_T7_Perp() // ----------------------- BUGFIX ok
{
    printTitle("Vector2 Perpendicular");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2 = v1.Perp();
    printVector2("v2 = v1.Perp()", v2);

    printSubTitle("The dot product of perpendicular vectors ought to be zero...");
    float dot = v1 * v2;
    Serial.print("dot = v1 * v2 ");
    Serial.println(dot);
}

void Vector2_T6_Angle()
{
    printTitle("Vector2 Angle");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2(3, 4);
    printVector2("v2", v2);

    float angle = v1.Angle(v2) * RAD_TO_DEG;
    Serial.print("angle = v1.Angle(v2) * RAD_TO_DEG ");
    Serial.println(angle);
}

void Vector2_T5_Dot_Product()
{
    printTitle("Vector2 Dot Product");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2(3, 4);
    printVector2("v2", v2);

    float dot = v1.Dot(v2);
    Serial.print("dot = v1.Dot(v2) ");
    Serial.println(dot);

    dot = v1 * v2;
    Serial.print("dot = v1 * v2 ");
    Serial.println(dot);
}

void Vector2_T4_UnitVector_Normalize()
{
    printTitle("Vector2 UnitVector & Normalize");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    nmr::Vector2<float> v2 = v1.UnitVector();
    printVector2("v2 = v1.UnitVector", v2);

    float magnitude = v2.Magnitude();
    Serial.print("magnitude = v2.Magnitude ");
    Serial.println(magnitude);

    nmr::Vector2<float> v3 = v1.Normalize();
    printVector2("v3 = v1.Normalize", v3);

    float distance = v3.Distance();
    Serial.print("distance = v3.Distance ");
    Serial.println(distance);
}

void Vector2_T3_Magnitude_Distance()
{
    printTitle("Vector2 Magnitude & Distance");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);

    float magnitude = v1.Magnitude();
    Serial.print("magnitude ");
    Serial.println(magnitude);

    float distance = v1.Distance();
    Serial.print("distance ");
    Serial.println(distance);
}

void Vector2_T2_GetVector()
{
    printTitle("Vector2 GetVector");

    nmr::Vector2<float> v1(1, 2);
    printVector2("v1", v1);
    nmr::Vector2<float> v2 = v1.GetVector();
    printVector2("v2 = v1.GetVector", v2);
}

void Vector2_T1_Constructor()
{
    printTitle("Vector2 Constructor");

    nmr::Vector2<float> v1;
    printVector2("v1", v1);

    float size = v1.Size();
    Serial.print("v1 size ");
    Serial.println(size);

    nmr::Vector2<float> v2(1, 2);
    printVector2("v2", v2);

    float x = v2.x();
    Serial.print("v2 x ");
    Serial.println(x);

    printSubTitle("array[] = {3, 4};");
    float array[] = {3, 4};
    nmr::Vector2<float> v3(array);
    printVector2("v3", v3);

    float y = v3.y();
    Serial.print("v3 y ");
    Serial.println(y);

    float element = v3.Element(0);
    Serial.print("v3 element(0) ");
    Serial.println(element);
}

#endif /* Numerics_Test_Vector2_h */
