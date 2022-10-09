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
// Created 20221008
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//
//

#ifndef Numerics_Angle_h
#define Numerics_Angle_h

#include "Arduino.h"
#include "Vector3.h"

namespace Numerics
{
  template <typename real>
  class Angle : Vector3<real>
  {
  private:
    real _angleRadian(real a, real b);
    real _angle2Radian(real a, real b);
    Vector3<real> _directionalVector(real angleRadian, int item);

  public:
    // Constructor
    Angle() {}

    // Implementation
    Vector3<real> DirectionalVectorXY(real angleRadian);
    Vector3<real> DirectionalVectorXZ(real angleRadian);
    Vector3<real> DirectionalVectorYZ(real angleRadian);

    real AngleRadianXY(Vector3<real> v);
    real AngleRadianXZ(Vector3<real> v);
    real AngleRadianYZ(Vector3<real> v);

    real Angle2RadianXY(Vector3<real> v);
    real Angle2RadianXZ(Vector3<real> v);
    real Angle2RadianYZ(Vector3<real> v);
  };

  template <typename real>
  Vector3<real> Angle<real>::DirectionalVectorXY(real angleRadian)
  {
    return _directionalVector(angleRadian, 1);
  }

  template <typename real>
  Vector3<real> Angle<real>::DirectionalVectorXZ(real angleRadian)
  {
    return _directionalVector(angleRadian, 2);
  }

  template <typename real>
  Vector3<real> Angle<real>::DirectionalVectorYZ(real angleRadian)
  {
    return _directionalVector(angleRadian, 3);
  }

  template <typename real>
  real Angle<real>::AngleRadianXY(Vector3<real> v)
  {
    return _angleRadian(v.x(), v.y());
  }

  template <typename real>
  real Angle<real>::AngleRadianXZ(Vector3<real> v)
  {
    return _angleRadian(v.x(), v.z());
  }

  template <typename real>
  real Angle<real>::AngleRadianYZ(Vector3<real> v)
  {
    return _angleRadian(v.y(), v.z());
  }

  template <typename real>
  real Angle<real>::Angle2RadianXY(Vector3<real> v)
  {
    return _angle2Radian(v.x(), v.y());
  }

  template <typename real>
  real Angle<real>::Angle2RadianXZ(Vector3<real> v)
  {
    return _angle2Radian(v.x(), v.z());
  }

  template <typename real>
  real Angle<real>::Angle2RadianYZ(Vector3<real> v)
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
  Vector3<real> Angle<real>::_directionalVector(real angleRadian, int item)
  {
    const int xy = 1;
    const int xz = 2;
    const int yz = 3;

    real a = cos(angleRadian);
    real b = sin(angleRadian);

    real x = 0;
    real y = 0;
    real z = 0;

    switch (item)
    {
    case xy:
      x = a;
      y = b;
      break;

    case xz:
      x = a;
      z = b;
      break;

    case yz:
      y = a;
      z = b;
      break;

    default:
      x = a;
      y = b;
      break;
    }

    // Constructed
    Vector3<real> vector(x, y, z);
    return vector;
  }

}

#endif