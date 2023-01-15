//
// Carpenter Software
// File: Common.h
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

#ifndef Numerics_Test_Common_h
#define Numerics_Test_Common_h

#include "Arduino.h"

#include "Bitwise.h"
#include "LinearMap.h"
#include "Matrix.h"
#include "MiscMath.h"
#include "Point2.h"
#include "Point3.h"
#include "Quaternion.h"
#include "Timer.h" 
#include "Vector2.h"
#include "Vector3.h"

template <typename real>
void printAngle(String s, int deg, real x, real y, real result)
{
    Serial.print(s);
    Serial.print(" deg: ");
    Serial.print(deg);
    Serial.print(" dv(");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(") ");
    Serial.print("result: ");
    Serial.println(result);
}

template <typename real>
void printAngle(String s, int deg, real x, real y, real z, real result)
{
    Serial.print(s);
    Serial.print(" deg: ");
    Serial.print(deg);
    Serial.print(" dv(");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(", ");
    Serial.print(z);
    Serial.print(") ");
    Serial.print("result: ");
    Serial.println(result);
}

template <typename real>
void printAngle(String s, int deg, nmr::Vector3<real> v, real result)
{
    Serial.print(s);
    Serial.print(" deg: ");
    Serial.print(deg);
    Serial.print(" dv(");
    Serial.print(v.x());
    Serial.print(", ");
    Serial.print(v.y());
    Serial.print(", ");
    Serial.print(v.z());
    Serial.print(") ");
    Serial.print("result: ");
    Serial.println(result);
}

template <typename real>
void printQuaternion(nmr::Quaternion<real> q)
{
    // Float to String takes time (SLOW)
    for (int i = 0; i < 4; i++)
    {
        // Source: Arduino's float data-types
        // The float data type has only 6-7 decimal digits of precision.
        // NOTE: Since the floats printed are mostly less-than the value of one (<1.0)
        //       than 7 decimal digits were used...
        // https://www.arduino.cc/reference/en/language/variables/data-types/float/
        //
        // Source: Arduino's String Object data-types (see note above...)
        // https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
        //
        // To 7 decimal places
        Serial.print(String(q.Element(i), 7));
        if (i < 3)
        {
            Serial.print(",");
        }
    }
    Serial.println("");
}

template <typename real>
void printQuaternion(String s, nmr::Quaternion<real> q, real angle) // -------------- Experimental
{
    // Float to String takes time (SLOW)
    Serial.print(s);
    for (int i = 0; i < 4; i++)
    {
        // Source: Arduino's float data-types
        // The float data type has only 6-7 decimal digits of precision.
        // NOTE: Since the floats printed are mostly less-than the value of one (<1.0)
        //       than 7 decimal digits were used...
        // https://www.arduino.cc/reference/en/language/variables/data-types/float/
        //
        // Source: Arduino's String Object data-types (see note above...)
        // https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
        //
        // To 7 decimal places
        Serial.print(String(q.Element(i), 3));
        if (i < 3)
        {
            Serial.print(",");
        }
    }
    Serial.print(" angle: ");
    Serial.println(String(angle, 3));
}

template <typename real>
void printQuaternion(String s, nmr::Quaternion<real> q)
{
    Serial.print(s);
    for (int i = 0; i < 4; i++)
    {
        // only prints 2 decimal places
        Serial.print(q.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}

template <typename real>
void printMatrix(String s, nmr::Matrix<real> M)
{
    Serial.print(s);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Serial.print(M.Element(i, j));
            Serial.print(" ");
        }
        Serial.println("");
    }
}

template <typename real>
void printVector3(String s, nmr::Vector3<real> v)
{
    Serial.print(s);
    Serial.print(" (");
    Serial.print(v.x());
    Serial.print(", ");
    Serial.print(v.y());
    Serial.print(", ");
    Serial.print(v.z());
    Serial.println(") ");
}

template <typename real>
void printVector2(String s, nmr::Vector2<real> v)
{
    Serial.print(s);
    Serial.print(" (");
    Serial.print(v.x());
    Serial.print(", ");
    Serial.print(v.y());
    Serial.println(") ");
}

template <typename real>
void printPoint3(String s, nmr::Point3<real> p)
{
    Serial.print(s);
    Serial.print(" (");
    Serial.print(p.x());
    Serial.print(", ");
    Serial.print(p.y());
    Serial.print(", ");
    Serial.print(p.z());
    Serial.println(") ");
}

template <typename real>
void printPoint2(String s, nmr::Point2<real> p)
{
    Serial.print(s);
    Serial.print(" (");
    Serial.print(p.x());
    Serial.print(", ");
    Serial.print(p.y());
    Serial.println(") ");
}

void printTitle(String s)
{
    Serial.print("---------------- + ");
    Serial.print(s);
    Serial.println(" +");
}

void printSubTitle(String s)
{
    Serial.print(" ** ");
    Serial.print(s);
    Serial.println(" **");
}

void printNewLine()
{
    Serial.println("");
}

#endif /* Numerics_Test_Common_h */
