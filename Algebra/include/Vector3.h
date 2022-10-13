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
// Created 20221008
// Updated 20221012
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Vector3_h
#define Numerics_Vector3_h

#include "Arduino.h"

namespace Numerics
{
    template <typename real>
    class Vector3
    {
    private:
        // Private Members
        real v_tuples[3];

        // Private Methods
        Vector3<real> _unitVector();
        Vector3<real> _vector();

    public:
        // Constructors
        Vector3();
        Vector3(real x, real y, real z);
        Vector3(const real array[]);
        // Destructor
        ~Vector3() {}

        // GETTERS & SETTERS
        real x();
        real y();
        real z();
        real Element(int index);

        // Inquiery
        bool IsVector() { return true; }
        bool IsPoint() { return false; }

        // METHODS
        real Magnitude();
        Vector3<real> Normalize();
        real Dot(Vector3<real> v);
        real Dot(Vector3<real> u, Vector3<real> v);
        Vector3<real> Cross(Vector3<real> v);
        Vector3<real> PerpVectorXY();
        Vector3<real> ProjThisOntoV(Vector3<real> v);

        // OPERATORS
        // Negation
        Vector3<real> operator-();
        //  Scalar product
        Vector3<real> operator*(real s);
        // Addition
        Vector3<real> operator+(Vector3<real> v);
        // Subtraction
        Vector3<real> operator-(Vector3<real> v);
        // Dot Product
        real operator*(Vector3<real> v);
        // Cross Product
        Vector3<real> operator^(Vector3<real> v);
    };

    template <typename real>
    Vector3<real>::Vector3()
    {
        v_tuples[0] = (real)0;
        v_tuples[1] = (real)0;
        v_tuples[2] = (real)0;
    }

    template <typename real>
    Vector3<real>::Vector3(real x, real y, real z)
    {
        v_tuples[0] = x;
        v_tuples[1] = y;
        v_tuples[2] = z;
    }

    template <typename real>
    Vector3<real>::Vector3(const real array[])
    {
        v_tuples[0] = array[0];
        v_tuples[1] = array[1];
        v_tuples[2] = array[2];
    }

    // GETTERS & SETTERS
    template <typename real>
    real Vector3<real>::Element(int index)
    {
        return v_tuples[index];
    }

    template <typename real>
    real Vector3<real>::x() { return v_tuples[0]; }
    template <typename real>
    real Vector3<real>::y() { return v_tuples[1]; }
    template <typename real>
    real Vector3<real>::z() { return v_tuples[2]; }

    // METHODS

    template <typename real>
    real Vector3<real>::Magnitude()
    {
        real sum = 0;
        sum += v_tuples[0] * v_tuples[0];
        sum += v_tuples[1] * v_tuples[1];
        sum += v_tuples[2] * v_tuples[2];
        return sqrt(sum);
    }

    template <typename real>
    Vector3<real> Vector3<real>::Normalize()
    {
        return _unitVector();
    }

    template <typename real>
    real Vector3<real>::Dot(Vector3<real> v)
    {
        // DOT Product
        // yeilds a Scalar
        real sum = 0;
        sum += v_tuples[0] * v.x();
        sum += v_tuples[1] * v.y();
        sum += v_tuples[2] * v.z();
        return sum;
    }

    template <typename real>
    real Vector3<real>::Dot(Vector3<real> u, Vector3<real> v)
    {
        // DOT Product
        // yeilds a Scalar
        real sum = 0;
        sum += u.x() * v.x();
        sum += u.y() * v.y();
        sum += u.z() * v.z();
        return sum;
    }

    template <typename real>
    Vector3<real> Vector3<real>::Cross(Vector3<real> v)
    {
        // CROSS Product
        // non-commutative property
        // Note: (Cross products must be 3D vectors)

        // a2b3 - a3b2
        real x = (v_tuples[1] * v.z()) - (v_tuples[2] * v.y());
        // a3b1 -a1b3
        real y = (v_tuples[2] * v.x()) - (v_tuples[0] * v.z());
        // a1b2 - a2b1
        real z = (v_tuples[0] * v.y()) - (v_tuples[1] * v.x());

        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector3<real> Vector3<real>::PerpVectorXY()
    {
        // Perp (XY) Operation
        real x = (real)-1 * v_tuples[1]; // -y
        real y = v_tuples[0];            // x
        real z = (real)0;

        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector3<real> Vector3<real>::ProjThisOntoV(Vector3<real> v)
    {
        // Constructed
        Vector3<real> u = _vector();
        // real dotUV = Dot(u, v);
        // real dotVV = Dot(v, v);
        // real quot = dotUV / dotVV;
        real quot = Dot(u, v) / Dot(v, v);
        // ref:

        // Constructed
        Vector3<real> vector = v * quot;
        return vector;
    }

    // OPERATORS

    template <typename real>
    Vector3<real> Vector3<real>::operator-()
    {
        real x = v_tuples[0] * (real)-1.0;
        real y = v_tuples[1] * (real)-1.0;
        real z = v_tuples[2] * (real)-1.0;

        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector3<real> Vector3<real>::operator*(real s)
    {
        real x = v_tuples[0] * s;
        real y = v_tuples[1] * s;
        real z = v_tuples[2] * s;

        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector3<real> Vector3<real>::operator+(Vector3<real> v)
    {
        real x = v_tuples[0] + v.x();
        real y = v_tuples[1] + v.y();
        real z = v_tuples[2] + v.z();

        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector3<real> Vector3<real>::operator-(Vector3<real> v)
    {
        real x = v_tuples[0] - v.x();
        real y = v_tuples[1] - v.y();
        real z = v_tuples[2] - v.z();

        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    real Vector3<real>::operator*(Vector3<real> v)
    {
        // DOT Product
        // yeilds a Scalar
        real sum = 0;

        sum += v_tuples[0] * v.x();
        sum += v_tuples[1] * v.y();
        sum += v_tuples[2] * v.z();

        return sum;
    }

    template <typename real>
    Vector3<real> Vector3<real>::operator^(Vector3<real> v)
    {
        // a2b3 - a3b2
        real x = (v_tuples[1] * v.z()) - (v_tuples[2] * v.y());
        // a3b1 -a1b3
        real y = (v_tuples[2] * v.x()) - (v_tuples[0] * v.z());
        // a1b2 - a2b1
        real z = (v_tuples[0] * v.y()) - (v_tuples[1] * v.x());

        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    // PRIVATE METHODS

    template <typename real>
    Vector3<real> Vector3<real>::_unitVector()
    {
        real x = (real)0;
        real y = (real)0;
        real z = (real)0;
        real magnitude = Magnitude();

        if (magnitude > (real)__FLT_EPSILON__)
        {
            x = v_tuples[0] / magnitude;
            y = v_tuples[1] / magnitude;
            z = v_tuples[2] / magnitude;
        }
        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector3<real> Vector3<real>::_vector()
    {
        Vector3<real> u(v_tuples[0], v_tuples[1], v_tuples[2]);
        return u;
    }
}
#endif
