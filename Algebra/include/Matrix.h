//
// Carpenter Software
// File: Class Matrix.h
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
// Created 20220927
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef MATRIX_H // IN-PROCESS 
#define MATRIX_H

#include "Arduino.h"
#include "Tuples.h"
#include "Vector.h"
#include "Point.h"

namespace Numerics
{
    template <typename real>
    class Matrix : Point<real>
    {
    private:
        // Members

    public:
        // Constructors
        Matrix();

        // Destructor
        ~Matrix(){};

        // getters

        // setters

        // Inquiry
    };

    // Constructors

    template <typename real>
    Matrix<real>::Matrix()
    {
    }
}

#endif