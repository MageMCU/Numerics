//
// Carpenter Software
// File: Class Vector3.h
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
// Corrections & Additions 20220925
// Relabeled class Vector3f to Vector3 20220926
// Corrections & Additions 20220927
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#include "Arduino.h"

#ifndef Numerics_Vector3_h
#define Numerics_Vector3_h

namespace Numerics
{
    template <typename T>
    class Vector3
    {
    private:
        // Private Properties
        T _x;
        T _y;
        T _z;
        T _w;

        // Private Methods
        Vector3 _unitVector();

    public:
        // Constructors
        Vector3<T>();
        Vector3<T>(T x, T y);
        Vector3<T>(T x, T y, T z);

        // getters
        T x();
        T y();
        T z();
        T w();

        // setters
        void x(T x);
        void y(T y);
        void z(T z);
        void w(T z);

        // Inquiry
        bool IsVector();

        // Methods
        T Magnitude();
        Vector3 Normalize();
        T Dot(Vector3<T> v);
        Vector3<T> Cross(Vector3<T> v);
        T PerpDot(Vector3<T> v);

        // Overloaded Operators
        T operator*(Vector3<T> v);       // Dot Product
        Vector3 operator^(Vector3<T> v); // Cross product
        Vector3 operator+(Vector3<T> v); // Vector Addition
        Vector3 operator-(Vector3<T> v); // Vector Subtraction
        Vector3 operator*(T s);          // Scalar Multiplication
        Vector3 operator/(T s);          // Scalar Division
    };

    // Constructors

    template <typename T>
    Vector3<T>::Vector3()
    {
        _x = 0;
        _y = 0;
        _z = 0;
        _w = 0;
    }

    template <typename T>
    Vector3<T>::Vector3(T x, T y)
    {
        _x = x;
        _y = y;
        _z = 0;
        _w = 0;
    }

    template <typename T>
    Vector3<T>::Vector3(T x, T y, T z)
    {
        _x = x;
        _y = y;
        _z = z;
        _w = 0;
    }

    // getters

    template <typename T>
    T Vector3<T>::x() { return _x; }
    template <typename T>
    T Vector3<T>::y() { return _y; }
    template <typename T>
    T Vector3<T>::z() { return _z; }
    template <typename T>
    T Vector3<T>::w() { return _w; }

    // setters

    template <typename T>
    void Vector3<T>::x(T x) { _x = x; }
    template <typename T>
    void Vector3<T>::y(T y) { _y = y; }
    template <typename T>
    void Vector3<T>::z(T z) { _z = z; }

    // Inquiry

    template <typename T>
    bool Vector3<T>::IsVector()
    {
        return (_w == 0);
    }

    // METHODS

    template <typename T>
    T Vector3<T>::Magnitude()
    {
        T sum = 0;

        sum += _x * _x;
        sum += _y * _y;
        sum += _z * _z;

        return sqrt(sum);
    }

    template <typename T>
    Vector3<T> Vector3<T>::Normalize()
    {
        return _unitVector();
    }

    template <typename T>
    T Vector3<T>::Dot(Vector3<T> v)
    {
        // DOT Product
        // Scalar
        T sum = 0;

        sum += _x * v.x();
        sum += _y * v.y();
        sum += _z * v.z();

        return sum;
    }

    template <typename T>
    Vector3<T> Vector3<T>::Cross(Vector3<T> v)
    {
        // CROSS Product
        // non-commutative property
        // Note: (Cross products must be 3D vectors)
        // For 2D vectors, z-component must be zero.
        Vector3<T> vector = {};
        // REF: LA&A by Leon 8th. ed. p.102
        // a(y)b(z) - b(y)a(z)
        // b(x)a(z) - a(x)b(z)
        // a(x)b(y) - b(x)a(y)
        vector.x(_y * v.z() - v.y() * _z);
        vector.y(v.x() * _z - _x * v.z());
        vector.z(_x * v.y() - v.x() * _y);
        return vector;
    }

    template <typename T>
    T Vector3<T>::PerpDot(Vector3<T> v)
    {
        // Ref: GTfCG by Schneider & Eberly p.121
        // Analogy: Similar to the z-component of a
        //          cross product of 2D vectors whose
        //          z-components are set to zero.
        // Example: Could be used to determine how
        //          to turn a robot either to the
        //          left or to the right. Really!
        //
        // Perp (XY) Operation
        float x = -_y;
        float y = _x;
        // Dot Product
        float dot = (x * v.x() + y * v.y());
        return dot;
    }

    // OVERLOADED OPERATORS

    template <typename T>
    T Vector3<T>::operator*(Vector3<T> v)
    {
        return Dot(v);
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator^(Vector3<T> v)
    {
        return Cross(v);
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator+(Vector3<T> v)
    {
        Vector3<T> results = {};

        results.x(_x + v.x());
        results.y(_y + v.y());
        results.z(_z + v.z());

        return results;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator-(Vector3<T> v)
    {
        Vector3<T> results = {};

        results.x(_x - v.x());
        results.y(_y - v.y());
        results.z(_z - v.z());

        return results;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator*(T s)
    {
        Vector3<T> results = {};

        results.x(_x * s);
        results.y(_y * s);
        results.z(_z * s);

        return results;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator/(T s)
    {
        Vector3<T> results = {_x, _y, _z};

        // Is (s) zero?
        if (abs(s) < (T)__FLT_EPSILON__)
            return results;

        results.x(_x / s);
        results.y(_y / s);
        results.z(_z / s);

        return results;
    }

    // PRIVATE METHODS

    template <typename T>
    Vector3<T> Vector3<T>::_unitVector()
    {
        Vector3<T> results = {};
        float magnitude = Magnitude();

        if (magnitude > (T)__FLT_EPSILON__)
        {
            results.x(_x / magnitude);
            results.y(_y / magnitude);
            results.z(_z / magnitude);
        }

        return results;
    }
}
#endif
