//
// Carpenter Software
// File: TestPoint3.h
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

#ifndef Numerics_Test_Point3_h
#define Numerics_Test_Point3_h

#include "../TESTS/Common.h"

void Point3_T4_PointFromPointVectorAddition()
{
    printTitle("Point3 Point from Point Vector Additin");

    nmr::Point3<float> p1(8, -4, 21);
    printPoint3("p1", p1);

    nmr::Vector3<float> v(6, 2, -10);
    printVector3("v", v);

    printSubTitle("Point = Point + Vector");

    nmr::Point3<float> p2 = p1 + v;
    printPoint3("p2 = p1 + v", p2);
}

void Point3_T3_VectorFromPointPointSubtraction()
{
    printTitle("Point3 Vector from Point Point Subtraction");

    nmr::Point3<float> p1(8, -4, 12);
    printPoint3("p1", p1);

    nmr::Point3<float> p2(2, 7, 6);
    printPoint3("p2", p2);

    printSubTitle("Vector = Point - Point");

    nmr::Vector3<float> v = p1 - p2;
    printVector3("v = p1 - p2", v);
}

void Point3_T2_GetPoint()
{
    printTitle("Point3 GetPoint");

    nmr::Point3<float> p1(3, 7, 4);
    printPoint3("p1", p1);

    nmr::Point3<float> p2 = p1.GetPoint();
    printPoint3("p2", p2);
}

void Point3_T1_Constructor()
{
    printTitle("Point3 Constructor");

    nmr::Point3<float> p1;
    printPoint3("p1", p1);

    float size = p1.Size();
    Serial.print("p1 size ");
    Serial.println(size);

    nmr::Point3<float> p2(1, 2, 3);
    printPoint3("p2", p2);

    float z = p2.z();
    Serial.print("p2 z ");
    Serial.println(z);

    printSubTitle("array[] = {4, 5, 6};");
    float array[] = {4, 5, 6};
    nmr::Point3<float> p3(array);
    printPoint3("p3", p3);

    float y = p3.y();
    Serial.print("p3 y ");
    Serial.println(y);

    float element = p3.Element(2);
    Serial.print("p3 element(2) ");
    Serial.println(element);
}

#endif /* Numerics_Test_Point3_h */