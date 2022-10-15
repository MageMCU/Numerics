//
// Carpenter Software
// File: Class Quaternion.h
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

#ifndef Numerics_Quaternion_h
#define Numerics_Quaternion_h

#include "Arduino.h"
// #include "Vector.h"

namespace nmr
{
    template <typename real>
    class Quaternion
    {
    private:
        // PRIVATE MEMBERS
        real q_tuples[4];

    public:
        // CONSTRUCTORS
        Quaternion();
        Quaternion(real x, real y, real z, real w);

        // DESTRUCTOR
        ~Quaternion() {}
    };

    template <typename real>
    Quaternion<real>::Quaternion()
    {
        q_tuples[0] = (real)0;
        q_tuples[1] = (real)0;
        q_tuples[2] = (real)0;
        q_tuples[3] = (real)0;
    }

    template <typename real>
    Quaternion<real>::Quaternion(real x, real y, real z, real w)
    {
        q_tuples[0] = x;
        q_tuples[1] = y;
        q_tuples[2] = z;
        q_tuples[3] = w;
    }
}

#endif