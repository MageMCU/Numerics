//
// Carpenter Software
// File: TestQuaternion.h
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

#ifndef Numerics_Test_Quaternion_h
#define Numerics_Test_Quaternion_h

#include "../TESTS/Common.h"

void Quaternion_T1_Constructor()
{
    printTitle("Quaternion T1 Constructors");

    nmr::Quaternion<float> q1;
    printQuaternion("q1", q1);

    nmr::Quaternion<float> q2(1, 2, 3, 4);
    printQuaternion("q2", q2);

    float angleRadian = 45 * DEG_TO_RAD;
    nmr::Vector3<float> v1(0, 1, 0);
    printVector3("v1(0, 1, 0)", v1);
    nmr::Quaternion<float> q3(v1, angleRadian);
    printQuaternion("q3(v1, angleRadian)", q3);

    // Test its Getters & Setters
    nmr::Quaternion<float> q4 = q3.GetQuaternion();
    printQuaternion("q4 = q3.GetQuaternion3", q4);
    nmr::Vector3<float> v2 = q3.GetVector();
    printVector3("v2 = q3.GetVector", v2);
    float angleDegrees = q3.GetAngle() * RAD_TO_DEG;
    Serial.print("angleDegrees: ");
    Serial.println(angleDegrees);
    float w = q3.w();
    Serial.print("w = q3.w(): ");
    Serial.println(w);
    nmr::Vector3<float> v3 = q3.GetAxis();
    printVector3("v3 = q3.GetAxis", v3);
    nmr::Quaternion<float> q5 = q3.GetConjugate();
    printQuaternion("q5 = q3.GetConjugate", q5);
}

#endif /* Numerics_Test_Quaternion_h */