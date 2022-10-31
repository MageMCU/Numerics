//
// Carpenter Software
// File: Class Mics.h was Math.h
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
// Created 20221013
// Update 20221030 - renamed class name platformio conflict
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Misc_h
#define Numerics_Misc_h

#include "Arduino.h"

namespace nmr
{
    enum Dimension
    {
        XY = 1,
        XZ,
        YZ
    };

    template <typename real>
    real Square(real value)
    {
        return value * value;
    }

    template <typename real>
    real AngleRadian(real a, real b)
    {
        // Division by zero requires no check
        // QuadI (refAngle)
        real refAngle = atan((double)b / (double)a);
        // QuadII
        if (a < (real)0 && b >= (real)0)
        {
            refAngle = (real)PI + refAngle;
        }
        // QuadIII
        if (a < (real)0 && b < (real)0)
        {
            refAngle = (real)PI + refAngle;
        }
        // QuadIV
        if (a >= (real)0 && b < (real)0)
        {
            refAngle = (real)2.0 * (real)PI + refAngle;
        }

        return refAngle;
    }

    template <typename real>
    real Angle2Radian(real a, real b)
    {
        // Division by zero requires no check when using Mathf
        // Quad I & II (refAngle)
        real refAngle = atan2((double)b, (double)a);
        // Quad III & IV
        if (b < (real)0)
        {
            refAngle = refAngle + (real)2.0 * (real)PI;
        }

        return refAngle;
    }

    template <typename real>
    void DirectionalVector(real angleRadian, real &x, real &y, real &z, Dimension item)
    {
        real a = cos(angleRadian);
        real b = sin(angleRadian);

        x = (real)0;
        y = (real)0;
        z = (real)0;

        switch (item)
        {
        case XY:
            x = a; // X
            y = b; // Y
            break;

        case XZ:
            x = a; // X
            z = b; // Z
            break;

        case YZ:
            y = a; // Y
            z = b; // Z
            break;

        default:
            x = a; // X
            y = b; // Y
            break;
        }
    }

    template <typename real>
    real map(real x, real x1, real x2, real y1, real y2)
    {
        // Assume linear functions
        // m = (y2 - y1)/(x2 - x1)
        // (y - y1) = m(x - x1)
        return (y2 - y1) * (x - x1) / (x2 - x1) + y1;
    }
}

#endif /* Numerics_Misc_h */