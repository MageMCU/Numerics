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

#include "Arduino.h"

#ifndef Numerics_Vector3f_h
#define Numerics_Vector3f_h

namespace Numerics
{
    template<typename T> class Vector3f
    {
        private:

        T _x;
        T _y;
        T _z;
        T _w;

       Vector3f _unitVector();
        
        public:

        Vector3f<T>();
        Vector3f<T>(T x, T y);
        Vector3f<T>(T x, T y, T z);

        T x();
        T y();
        T z();

        void x(T x);
        void y(T y);
        void z(T z);

        T Magnitude();
        Vector3f Normalize();
    };

    template<typename T>
    Vector3f<T>::Vector3f()
        {
            _x = 0;
            _y = 0;
            _z = 0;
            _w = 0;
        }

    template<typename T>
    Vector3f<T>::Vector3f(T x, T y)
        {
            _x = x;
            _y = y;
            _z = 0;
            _w = 0;
        }
    
  template<typename T>
    Vector3f<T>::Vector3f(T x, T y, T z)
        {
            _x = x;
            _y = y;
            _z = z;
            _w = 0;
        }

       template<typename T>
        T Vector3f<T>::x() { return _x; }
       template<typename T>
        T Vector3f<T>::y() { return _y; }
       template<typename T>
        T Vector3f<T>::z() { return _z; }

       template<typename T>
        void Vector3f<T>::x(T x) { _x = x; }
       template<typename T>
        void Vector3f<T>::y(T y) { _y = y; }
       template<typename T>
        void Vector3f<T>::z(T z) { _z = z; }

       template<typename T>
        T Vector3f<T>::Magnitude()
        {
            T sum = 0;
            
            sum += _x * _x;
            sum += _y * _y;
            sum += _z * _z;

            return sqrt(sum);
        }

        template<typename T>
        Vector3f<T> Vector3f<T>::Normalize()
        {
            return _unitVector();
        }

        // PRIVATE METHODS

       template<typename T>
        Vector3f<T> Vector3f<T>::_unitVector()
        {
            Vector3f<T> v = {};
            float magnitude = Magnitude();

            if (magnitude >  (T) __FLT_EPSILON__)
            {
                v.x(_x / magnitude); 
                v.y(_y / magnitude); 
                v.z(_z / magnitude); 
            }

            return v;
        }
}
#endif
