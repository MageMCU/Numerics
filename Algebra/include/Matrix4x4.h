//
// Carpenter Software
// File: Class Matrix4x4.h
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

#ifndef Numerics_Matrix4x4_h
#define Numerics_Matrix4x4_h

#include "Arduino.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Point2.h"
#include "Point3.h"
#include "Matrix.h"

namespace nmr
{
    template <typename real>
    class Matrix4x4 : Matrix<real>
    {
    private:
        // Properties
        real m_tuples[16];

    public:
        Matrix4x4() = default;
        ~Matrix4x4() = default;
    };
}
#endif