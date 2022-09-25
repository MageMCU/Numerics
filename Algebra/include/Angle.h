//
// Carpenter Software
// File: Class Angle.h
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
// Created 20220924
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//
//
// When the input of a 2D directional
// unit-vector loops 360 degrees per 
// 1 degree, the quadrants I, II, III 
// and IV were determined emperically 
// and not all libraries treat the math
// function atan() the same... Be warned.
// Tested on with Arduino.h on PlatformIO.

#ifndef Numerics_Angle_h
#define Numerics_Angle_h

#include "Arduino.h"
#include "Vector3f.h"

namespace Numerics {
  template<typename T>
  class Angle {
  private:

  public:

  // Constructor
    Angle() {}

  // Implementation
    T angle (T x, T y);
    T angle2 (T x, T y);
  };

    template<typename T>
    T Angle<T>::angle (T x, T y)
    {
        // Division by zero requires no check 
        // QuadI (refAngle)
        T refAngle = atan((double) y / (double) x);
        // QuadII
        if (x < (T) 0 && y >= (T) 0)
        {
            refAngle = (T) PI + refAngle;
        }
        // QuadIII
        if (x < (T) 0 && y < (T) 0)
        {
            refAngle = (T) PI + refAngle;
        }
        // QuadIV
        if (x >= (T) 0 && y < (T) 0)
        {
            refAngle = (T) 2.0 * (T) PI + refAngle;
        }

        return refAngle;
    }

    template<typename T>
    T Angle<T>::angle2 (T x, T y)
    {
      // Division by zero requires no check when using Mathf
        // Quad I & II (refAngle)
        T refAngle = atan2((double) y, (double) x);
        // Quad III & IV
        if (y < (T) 0)
        {
            refAngle = refAngle + (T) 2.0 * (T) PI;
        }

        return refAngle;
    }
}
#endif