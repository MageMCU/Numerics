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
// Created 20220924
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

namespace Numerics {
  template<typename T>
  class Map {
  private:
  
  public:
  // Constructor
    Map() {}
  // Implementation
    T map (T x, T x1, T x2, T y1, T y2);
  };

    template<typename T>
    T Map<T>::map (T x, T x1, T x2, T y1, T y2)
    {
      // Assume linear functions
      // m = (y2 - y1)/(x2 - x1)
      // (y - y1) = m(x - x1)
      return (y2 - y1) * (x - x1) / (x2 - x1) + y1;
    }
}
#endif
