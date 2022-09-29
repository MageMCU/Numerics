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
// Additions & Testing 20220928
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
#include"Vector.h"


namespace Numerics
{

  template <typename real>
  class Angle : Vector<real>
  {
  private:
    real _angleRadian(real a, real b);
    real _angle2Radian(real a, real b);
    Vector<real> _directionalVector(real angleRadian, int item);

  public:
    // Constructor
    Angle() {}

    // Implementation
    Vector<real> DirectionalVectorXY(real angleRadian);
    Vector<real> DirectionalVectorXZ(real angleRadian);
    Vector<real> DirectionalVectorYZ(real angleRadian);

    real AngleRadianXY(Vector<real> v);
    real AngleRadianXZ(Vector<real> v);
    real AngleRadianYZ(Vector<real> v);

    real Angle2RadianXY(Vector<real> v);
    real Angle2RadianXZ(Vector<real> v);
    real Angle2RadianYZ(Vector<real> v);
  };

  template <typename real>
  Vector<real> Angle<real>::DirectionalVectorXY(real angleRadian) 
  {
    return _directionalVector(angleRadian, 1);
  }

  template <typename real>
  Vector<real> Angle<real>::DirectionalVectorXZ(real angleRadian) 
  {
    return _directionalVector(angleRadian, 2);
  }

  template <typename real>
  Vector<real> Angle<real>::DirectionalVectorYZ(real angleRadian) 
  {
    return _directionalVector(angleRadian, 3);
  }

  template <typename real>
  real Angle<real>::AngleRadianXY(Vector<real> v)
  {
    return _angleRadian(v.x(), v.y());
  }

  template <typename real>
  real Angle<real>::AngleRadianXZ(Vector<real> v)
  {
    return _angleRadian(v.x(), v.z());
  }

  template <typename real>
  real Angle<real>::AngleRadianYZ(Vector<real> v)
  {
    return _angleRadian(v.y(), v.z());
  }

  template <typename real>
  real Angle<real>::Angle2RadianXY(Vector<real> v)
  {
    return _angle2Radian(v.x(), v.y());
  }

  template <typename real>
  real Angle<real>::Angle2RadianXZ(Vector<real> v)
  {
    return _angle2Radian(v.x(), v.z());
  }

  template <typename real>
  real Angle<real>::Angle2RadianYZ(Vector<real> v)
  {
    return _angle2Radian(v.y(), v.z());
  }

  template <typename real>
  real Angle<real>::_angleRadian(real a, real b)
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
  real Angle<real>::_angle2Radian(real a, real b)
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
  Vector<real> Angle<real>::_directionalVector(real angleRadian, int item)
  {
    Vector<real> vector = {};

    const int xy = 1;
    const int xz = 2;
    const int yz = 3;

    real a = cos(angleRadian);
    real b = sin(angleRadian);

    switch (item)
    {
    case xy:
      vector.x(a);
      vector.y(b);
      break;

    case xz:
      vector.x(a);
      vector.z(b);
      break;

    case yz:
      vector.y(a);
      vector.z(b);
      break;

    default:
      vector.x(a);
      vector.y(b);
      break;
    }

  return vector;
  }

}


#endif