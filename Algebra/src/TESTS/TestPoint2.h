//
// Carpenter Software
// File: TestPoint2.h
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

#ifndef Numerics_Test_Point2_h
#define Numerics_Test_Point2_h

#include "../TESTS/Common.h"

void Point2_T4_PointFromPointVectorAddition()
{
    printTitle("Point2 Point from Point Vector Additin");

    Point2<float> p1(8, -4);
    printPoint2("p1(8, -4) =", p1);

    Vector2<float> v(6, 2);
    printVector2("v(6, 2) =", v);

    printSubTitle("Point = Point + Vector");

    Point2<float> p2 = p1 + v;
    printPoint2("p2 = p1 + v =", p2);
}

void Point2_T3_VectorFromPointPointSubtraction()
{
    printTitle("Point2 Vector from Point Point Subtraction");

    Point2<float> p1(8, -4);
    printPoint2("p1(8, -4) =", p1);

    Point2<float> p2(2, 7);
    printPoint2("p2(2, 7) =", p2);

    printSubTitle("Vector = Point - Point");

    Vector2<float> v = p1 - p2;
    printVector2("v = p1 - p2 =", v);
}

void Point2_T2_GetPoint()
{
    printTitle("Point2 GetPoint");

    Point2<float> p1(3, 7);
    printPoint2("p1", p1);

    Point2<float> p2 = p1.GetPoint();
    printPoint2("p2", p2);
}

void Point2_T1_Constructor()
{
    printTitle("Point2 Constructor");

    Point2<float> p1;
    printPoint2("p1 =", p1);

    Point2<float> p2(1, 2);
    printPoint2("p2(1, 2) =", p2);

    printSubTitle("array[] = {3, 4};");
    float array[] = {3, 4};
    Point2<float> p3(array);
    printPoint2("p3(array) =", p3);
    
    printSubTitle("Vector2<float> v1(1, 2);");
    Vector2<float> v(1, 2);
    printVector2("v(1, 2) =", v);
    Point2<float> p4(v);
    printPoint2("p4(v) =", p4);
}

#endif /* Numerics_Test_Point2_h */