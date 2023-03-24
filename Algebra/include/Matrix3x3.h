//
// Carpenter Software
// File: Class Matrix3x3.h
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

#ifndef Numerics_Matrix3x3_h
#define Numerics_Matrix3x3_h

#include "Arduino.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Point2.h"
#include "Point3.h"
#include "Matrix.h"

namespace nmr
{
    template <typename real>
    class Matrix3x3 : Matrix<real>
    {
    private:

    public:
        Matrix3x3() = default;
        ~Matrix3x3() = default;
    };
}

#endif