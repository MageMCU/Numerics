//
// Carpenter Software
// File: Class Map.h
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

#ifndef Numerics_Map_h
#define Numerics_Map_h

#include "Arduino.h"

namespace Numerics
{
  template <typename real>
  class Map
  {
  private:
  public:
    // Constructor
    Map() {}
    // Destructor
    ~Map() {}
    // Implementation
    real map(real x, real x1, real x2, real y1, real y2);
  };

  template <typename real>
  real Map<real>::map(real x, real x1, real x2, real y1, real y2)
  {
    // Assume linear functions
    // m = (y2 - y1)/(x2 - x1)
    // (y - y1) = m(x - x1)
    return (y2 - y1) * (x - x1) / (x2 - x1) + y1;
  }
}
#endif
