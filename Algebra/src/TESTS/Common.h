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

#include "Motion.h"
#include "Vector.h"
#include "Point.h"
#include "Matrix.h"
#include "Quaternion.h"
#include "Math.h"

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
void printAngle(String s, int deg, nmr::Vector<real> v, real result)
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
void printQuaternion(String s, nmr::Quaternion<real> q)
{
    Serial.println(s);
    for (int i = 0; i < 4; i++)
    {
        // Serial.print(q.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}

template <typename real>
void printVector(String s, nmr::Vector<real> v)
{
    Serial.println(s);
    for (int i = 0; i < 4; i++)
    {
        Serial.print(v.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}

template <typename real>
void printPoint(String s, nmr::Point<real> p)
{
    Serial.println(s);
    for (int i = 0; i < 4; i++)
    {
        Serial.print(p.Element(i));
        Serial.print(" ");
    }
    Serial.println("");
}

template <typename real>
void printMatrix(String s, nmr::Matrix<real> M)
{
    Serial.println(s);
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

#endif