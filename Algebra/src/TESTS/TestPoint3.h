//
// Carpenter Software
// File: TestPoint3.h
// Github: MageMCU
// Repository: Numerics
// Folder: TESTS
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

    Point3<float> p1(8, -4, 21);
    printPoint3("p1(8, -4, 21) =", p1);

    Vector3<float> v(6, 2, -10);
    printVector3("v(6, 2, -10) =", v);

    printSubTitle("Point = Point + Vector");

    Point3<float> p2 = p1 + v;
    printPoint3("p2 = p1 + v =", p2);
}

void Point3_T3_VectorFromPointPointSubtraction()
{
    printTitle("Point3 Vector from Point Point Subtraction");

    Point3<float> p1(8, -4, 12);
    printPoint3("p1(8, -4, 12) =", p1);

    Point3<float> p2(2, 7, 6);
    printPoint3("p2(2, 7, 6) =", p2);

    printSubTitle("Vector = Point - Point");

    Vector3<float> v = p1 - p2;
    printVector3("v = p1 - p2 =", v);
}

void Point3_T2_GetPoint()
{
    printTitle("Point3 GetPoint");

    Point3<float> p1(3, 7, 4);
    printPoint3("p1", p1);

    Point3<float> p2 = p1.GetPoint();
    printPoint3("p2", p2);
}

void Point3_T1_Constructor()
{
    printTitle("Point3 Constructor");

    Point3<float> p1;
    printPoint3("p1 =", p1);

    Point3<float> p2(1, 2, 3);
    printPoint3("p2(1, 2, 3) =", p2);

    printSubTitle("array[] = {4, 5, 6};");
    float array[] = {4, 5, 6};
    Point3<float> p3(array);
    printPoint3("p3(array) =", p3);
    
    Vector3<float> v(1, 2, 3);
    printVector3("v(1, 2, 3) =", v);
    Point3<float> p4(v);
    printPoint3("p4(v) =", p4);
}

#endif /* Numerics_Test_Point3_h */