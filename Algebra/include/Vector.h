//
// Carpenter Software
// File: Class Vector.h
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
// Created 20220927
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef VECTOR_H
#define VECTOR_H

#include "Arduino.h"
#include "Tuples.h"
// #include "Point.h"

namespace Numerics
{
    template <typename real>
    class Vector : Tuples<real>
    {
    private:
        // Members
        real _x;
        real _y;
        real _z;
        real _w;

        // Private Methods
        Vector _unitVector();

    public:
        // Constructors
        Vector();
        Vector(real x, real y);
        Vector(real x, real y, real z);

        // Destructor
        ~Vector(){};

        // getters
        real x();
        real y();
        real z();
        real w();

        // setters
        void x(real x);
        void y(real y);
        void z(real z);

        // Inquiry
        bool IsVector();

        // Methods
        real Magnitude();
        Vector Normalize();
        real Dot(Vector<real> v);
        Vector<real> Cross(Vector<real> v);
        real PerpDot(Vector<real> v);

        // Overloaded Operators
        real operator*(Vector<real> v);   // Dot Product
        Vector operator^(Vector<real> v); // Cross product
        Vector operator+(Vector<real> v); // Vector Addition
        Vector operator-(Vector<real> v); // Vector Subtraction
        Vector operator*(real s);         // Scalar Multiplication
        Vector operator/(real s);         // Scalar Division
    };

    template <typename real>
    Vector<real>::Vector()
    {
        _x = 0;
        _y = 0;
        _z = 0;
        _w = 0;
    }

    template <typename real>
    Vector<real>::Vector(real x, real y)
    {
        _x = x;
        _y = y;
        _z = 0;
        _w = 0;
    }

    template <typename real>
    Vector<real>::Vector(real x, real y, real z)
    {
        _x = x;
        _y = y;
        _z = z;
        _w = 0;
    }

    template <typename real>
    real Vector<real>::x() { return _x; }
    template <typename real>
    real Vector<real>::y() { return _y; }
    template <typename real>
    real Vector<real>::z() { return _z; }
    template <typename real>
    real Vector<real>::w() { return _w; }

    template <typename real>
    void Vector<real>::x(real x) { _x = x; }
    template <typename real>
    void Vector<real>::y(real y) { _y = y; }
    template <typename real>
    void Vector<real>::z(real z) { _z = z; }

    // Inquiry

    template <typename real>
    bool Vector<real>::IsVector()
    {
        return (_w == 0);
    }

    // METHODS

    template <typename real>
    real Vector<real>::Magnitude()
    {
        real sum = 0;

        sum += _x * _x;
        sum += _y * _y;
        sum += _z * _z;

        return sqrt(sum);
    }

    template <typename real>
    Vector<real> Vector<real>::Normalize()
    {
        return _unitVector();
    }

    template <typename real>
    real Vector<real>::Dot(Vector<real> v)
    {
        // DOT Product
        // Scalar
        real sum = 0;

        sum += _x * v.x();
        sum += _y * v.y();
        sum += _z * v.z();

        return sum;
    }

    template <typename real>
    Vector<real> Vector<real>::Cross(Vector<real> v)
    {
        // CROSS Product
        // non-commutative property
        // Note: (Cross products must be 3D vectors)
        // For 2D vectors, z-component must be zero.
        Vector<real> vector = {};
        // REF: LA&A by Leon 8th. ed. p.102
        // a(y)b(z) - b(y)a(z)
        // b(x)a(z) - a(x)b(z)
        // a(x)b(y) - b(x)a(y)
        vector.x(_y * v.z() - v.y() * _z);
        vector.y(v.x() * _z - _x * v.z());
        vector.z(_x * v.y() - v.x() * _y);
        return vector;
    }

    template <typename real>
    real Vector<real>::PerpDot(Vector<real> v)
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

    template <typename real>
    real Vector<real>::operator*(Vector<real> v)
    {
        return Dot(v);
    }

    template <typename real>
    Vector<real> Vector<real>::operator^(Vector<real> v)
    {
        return Cross(v);
    }

    template <typename real>
    Vector<real> Vector<real>::operator+(Vector<real> v)
    {
        Vector<real> results = {};

        results.x(_x + v.x());
        results.y(_y + v.y());
        results.z(_z + v.z());

        return results;
    }

    template <typename real>
    Vector<real> Vector<real>::operator-(Vector<real> v)
    {
        Vector<real> results = {};

        results.x(_x - v.x());
        results.y(_y - v.y());
        results.z(_z - v.z());

        return results;
    }

    template <typename real>
    Vector<real> Vector<real>::operator*(real s)
    {
        Vector<real> results = {};

        results.x(_x * s);
        results.y(_y * s);
        results.z(_z * s);

        return results;
    }

    template <typename real>
    Vector<real> Vector<real>::operator/(real s)
    {
        Vector<real> results = {_x, _y, _z};

        // Is (s) zero?
        if (abs(s) < (real)__FLT_EPSILON__)
            return results;

        results.x(_x / s);
        results.y(_y / s);
        results.z(_z / s);

        return results;
    }

    // PRIVATE METHODS

    template <typename real>
    Vector<real> Vector<real>::_unitVector()
    {
        Vector<real> results = {};
        float magnitude = Magnitude();

        if (magnitude > (real)__FLT_EPSILON__)
        {
            results.x(_x / magnitude);
            results.y(_y / magnitude);
            results.z(_z / magnitude);
        }

        return results;
    }
}

#endif