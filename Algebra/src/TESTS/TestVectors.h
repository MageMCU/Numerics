//
// Carpenter Software
// File: TestVectors.h
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
//
// Algebra OOP Library
// The math is underneath the namespace
// called Numerics as in numeric computation.
//
// By Jesse Carpenter (carpentersoftware.com)
//
// CHANGELOG
// Created 20221015
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Test_Vectors_h
#define Numerics_Test_Vectors_h

#include "../TESTS/Common.h"

void matrixNegationTestM8()
{
    printTitle("Matrix Negation Test M7");

    nmr::Matrix<float> A;
    printMatrix("Matrix<float> A", A);
    //
    printSubTitle("3x3 operation");
    nmr::Matrix<float> B = -A;
    // printMatrix(" A = -A", A);
    printMatrix(" B = -A", B);

    /*
    printSubTitle("2x2 matrix using 2 vectos.");
    Vector<float> aRow1(1, 2);
    Vector<float> aRow2(3, 4);
    Matrix<float> B(aRow1, aRow2);
    printMatrix("B(aRow1, aRow2)", B);
    //
    printSubTitle("Notice 16th-element unaffected");
    B = -B;
    printMatrix(" B = -B", B);

    printSubTitle("3x3 matrix using 3 vectors.");
    Vector<float> bRow1(1, 2, 3);
    Vector<float> bRow2(4, 5, 6);
    Vector<float> bRow3(7, 8, 9);
    Matrix<float> C(bRow1, bRow2, bRow3);
    printMatrix("C(bRow1, bRow2, bRow3)", C);
    //
    printSubTitle("Notice 16th-element unaffected");
    C = -C;
    printMatrix(" C = -C", C);

    printSubTitle("3x3 matrix using an array, It uses 9-elements even though it has 16.");
    printSubTitle("array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}");
    float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<float> D(array);
    printMatrix("Matrix<float> D()", D);
    //
    printSubTitle("Notice 16th-element unaffected");
    D = -D;
    printMatrix(" D = -D", D);
    */
}

void vectorAngleTestV12()
{
    printTitle("Vector Angle between 3D-Vectors Test V12");

    float x = cos((float)45 * DEG_TO_RAD);
    float y = sin((float)45 * DEG_TO_RAD);
    nmr::Vector<float> a(x, y);
    printVector("a", a);

    x = cos((float)0 * DEG_TO_RAD);
    y = sin((float)0 * DEG_TO_RAD);
    nmr::Vector<float> b(x, y);
    printVector("b", b);

    float angle = a.Angle(b);
    Serial.print("angle = a.Angle(b): ");
    Serial.println(angle * RAD_TO_DEG);

    // To Compare with Angle Class the vectors
    // have to be 2D instead of 3D as it is here...

    // Interesting to view Unit-Circle
    printSubTitle("Unit-Circle");
    for (int deg = 0; deg < 360; deg += 5)
    {
        x = cos((float)deg * DEG_TO_RAD);
        y = sin((float)deg * DEG_TO_RAD);

        b.x(x);
        b.y(y);

        angle = a.Angle(b) * RAD_TO_DEG;

        printAngle("a=45 b=", deg, b, angle);
    }
}

void vectorSubtractionTestV11()
{
    printTitle("Vector Subtraction Test V11");

    float array1[] = {3, -2, 6};
    nmr::Vector<float> a(array1);
    printVector("a", a);

    float array2[] = {-4, 6, 5};
    nmr::Vector<float> b(array2);
    printVector("b", b);

    nmr::Vector<float> c = a - b;
    printVector("c = a - b", c);

    printSubTitle("Linear Combinations");
    float s = 2.0;
    Serial.println("s = 2.0");
    float t = 3.0;
    Serial.println("t = 3.0");

    // This test includes the operator=(Vector<real> v)
    printSubTitle("Reassigned 'c' using operator=(Vector<real> v)");
    c = a * s - -b * t;
    //      a =  3,  -2    6
    //     -b =  4,  -6,  -5
    // ----------------------
    //  a * 2 =  6,  -4,  12
    // -b * 3 = 12, -18, -15
    //          --  ---  ---
    //          -6   14   27
    printVector("c = a * s - -b * t;", c);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
}

void vectorAdditionTestV10()
{
    printTitle("Vector Addition Test V10");

    float array1[] = {3, -2, 6};
    nmr::Vector<float> a(array1);
    printVector("a", a);

    float array2[] = {-4, 6, 5};
    nmr::Vector<float> b(array2);
    printVector("b", b);

    nmr::Vector<float> c = a + b;
    printVector("c = a + b", c);

    printSubTitle("Linear Combinations");
    float s = 2.0;
    Serial.println("s = 2.0");
    float t = 3.0;
    Serial.println("t = 3.0");

    // This test includes the operator=(Vector<real> v)
    printSubTitle("Reassigned 'c'");
    c = a * s + b * t;
    printVector("c = a * s + b * t", c);

    nmr::Vector<float> d = a * s + b * t;
    printVector("d = a * s + b * t;", d);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
}

void vectorScalarMultiplicationTestV9()
{
    printTitle("Vector Scalar Multiplication Test V9");

    float array[] = {3, -2, 6};
    nmr::Vector<float> a(array);
    printVector("a", a);

    // Constraint where scalar has to be on the
    // right side of the vector as skown above.
    printSubTitle("Constraint scalar right side of '*' ONLY");
    float s = 2.0;
    nmr::Vector<float> b = a * s;
    printVector("b = a * s where s = 2", b);
}

void vectorNegationTestV8()
{
    printTitle("Vector Negation Test V8");

    float array[] = {3, -2, 6};
    nmr::Vector<float> a(array);
    printVector("a", a);

    // This test includes the operator=(Vector<real> v)
    printSubTitle("This test includes operator=(Vector<real> v)");
    nmr::Vector<float> b = a;
    printVector("b = a", b);

    // This negation test includes the operator-()
    printSubTitle("This negation test includes operator-()");
    a = -a;
    printVector("a = -a", a);
}

void vectorProjectionTestV7()
{
    printTitle("Vector Projection Test V7");

    float array1[] = {3, -2, 6};
    nmr::Vector<float> a(array1);
    printVector("a", a);

    float array2[] = {1, 4, 1};
    nmr::Vector<float> b(array2);
    printVector("b", b);

    nmr::Vector<float> c = a.ProjV(b);
    printVector("c = a.ProjV(b)", c);

    // See methods for references...
    // This test has not been proven --- FIXME
}

void vectorPerpVectorXY_TestV6()
{
    printTitle("Vector PerpVectorXY Test V6");
    float array[] = {8, 3, 0};
    nmr::Vector<float> v(array);
    printVector("v", v);
    nmr::Vector<float> result = v.PerpVectorXY();
    printVector("result = v.PerpVectorXY()", result);
}

void vectorCrossProductTestV5()
{
    printTitle("Vector Cross Product Test V5");
    // Notice the two different methods for the dot product...

    printSubTitle("Basis i");
    float array1[] = {1, 0, 0};
    nmr::Vector<float> a1(array1);
    printVector("a1", a1);

    printSubTitle("Basis j");
    float array2[] = {0, 1, 0};
    nmr::Vector<float> a2(array2);
    printVector("a2", a2);

    printSubTitle("Basis k");
    nmr::Vector<float> a3 = a1.Cross(a2);

    printVector("a1.Cross(a2)", a3);
    nmr::Vector<float> a4 = a1 ^ a2;
    printVector("a1 ^ a2", a4);
}

void vectorDotProductTestV4()
{
    printTitle("Vector Dot Product Test V4");
    // Notice the two different methods for the dot product...

    nmr::Vector<float> a(1, 2, 3);
    printVector("Vector<float> a(1, 2, 3)", a);

    nmr::Vector<float> b(3, -4, 8);
    printVector("Vector<float> b(3, -4, 8)", b);

    float dot = a.Dot(b);
    Serial.print("dot = a.Dot(b): ");
    Serial.println(dot);

    // dot ok  reassigned
    dot = a * b;
    Serial.print("dot = a * b: ");
    Serial.println(dot);

    // printSubTitle("Unit-Circle Dot Pruduct");
    // This test includes the Angle Class
    // Reference-Angle = 45 degress
    // Angle<float> rAngle();
    // reference directional vector ------------------------------------------- FIXME
    // Vector3<float> rDV = rAngle.DirectionalVectorXY((float)45 * DEG_TO_RAD);
    // printVector("rDV directional vector at 45 degrees", rDV);

    // Variable-Angle = 0 to 360 degrees
    // Angle<float> vAngle;
    // variable directional vector
    // Vector3<float> vDV;

    // printSubTitle("Degree - vDV vector - result: dot product");

    // Covers an entire unit circle
    // for (int deg = 0; deg < 360; deg += 10)
    // {
    // Assign rDV ------------------------------------------- FIXME
    // Vector3<float> vDV = vAngle.DirectionalVectorXY((float)deg * DEG_TO_RAD);
    // dot product
    // dot = rDV * vDV;
    // Debug Test
    // printAngle("UC: ", deg, vDV, dot);
    // }
}

void vectorNormalizeTestV3()
{
    printTitle("Vector Normalize Test V3");

    nmr::Vector<float> a(1, 2, 3);
    printVector("Vector<float> a(1, 2, 3)", a);

    // Normalize 'a'
    nmr::Vector<float> b = a.Normalize();
    printVector("After a.Normalize(), 'a' no change", a);
    printVector("Vector<float> b = a.Normalize()", b);

    // Magnitude of 'b' ought to be one
    printSubTitle("After a.Normalize(), Magnitude 'b' ought to be one");
    float mag = b.Magnitude();
    Serial.print("b.Magnitude() ");
    Serial.println(mag);
}

void vectorMagnitudeTestV2()
{
    printTitle("Vector Magnitude Test V2");

    nmr::Vector<float> a(1, 2, 3);
    printVector("Vector3<float> a(1, 2, 3)", a);

    float mag = a.Magnitude();
    Serial.print("a.Magnitude() ");
    Serial.println(mag);
    printSubTitle("square-root of 1*1 + 2*2 + 3*3 = 14 is 3.741...");
}

void vectorConstructorTestV1()
{
    printTitle("Vector Constructor Test V1");
    printSubTitle("Notice no parenthesis used in the default constructor.");

    nmr::Vector<float> a;
    printVector("Vector<float> a", a);

    nmr::Vector<float> b(1, 2);
    printVector("Vector<float> b(1, 2)", b);

    nmr::Vector<float> c(1, 2, 3);
    printVector("Vector<float> c(1, 2, 3)", c);

    nmr::Vector<float> d(1, 2, 3, 0);
    printVector("Vector<float> d(1, 2, 3, 0)", d);

    printSubTitle("float array[] = {1, 0, 0, 0};");
    float array[] = {1, 0, 0, 0};
    nmr::Vector<float> e(array);
    printVector("Vector<float> c(array)", e);
}

void DontKillTheRedundancy() {}

#endif
