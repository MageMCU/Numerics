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
// Created 20221008
// Updated 20221013
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Vector_h
#define Numerics_Vector_h

#include "Arduino.h"
#include "Math.h"

namespace Numerics
{
    template <typename real>
    class Vector
    {
    private:
        // PRIVATE MEMBERS
        real v_tuples[4];

    public:
        // CONSTRUCTORS
        Vector();
        Vector(real x, real y);
        Vector(real x, real y, real z);
        Vector(real x, real y, real z, real w);
        Vector(const real array[]);

        // DESTRUCTOR
        ~Vector() {}

        // GETTERS & SETTERS
        real x();
        void x(real x);

        real y();
        void y(real y);

        real z();
        void z(real z);

        real w();
        real Element(int index);

        // INQUIRY - All Vectors 4th-element always zero
        bool IsVector() { return v_tuples[3] == (real)0; }
        bool IsPoint() { return !IsVector(); }

        // PUBLIC METHODS
        Vector<real> GetVector();
        Vector<real> UnitVector();
        real Magnitude();
        Vector<real> Distance();
        Vector<real> Normalize();
        real Dot(Vector<real> v);
        real Dot(Vector<real> u, Vector<real> v);
        Vector<real> Cross(Vector<real> v);
        real Angle(Vector<real> v);
        Vector<real> PerpVectorXY();
        Vector<real> ProjV(Vector<real> v);

        // OPERATORS
        // Negation
        Vector<real>
        operator-();
        //  Scalar product
        Vector<real> operator*(real s);
        // Addition
        Vector<real> operator+(Vector<real> v);
        // Subtraction
        Vector<real> operator-(Vector<real> v);
        // Dot Product
        real operator*(Vector<real> v);
        // Cross Product
        Vector<real> operator^(Vector<real> v);
        // Copy
        Vector<real> operator=(Vector<real> v);
    };

    template <typename real>
    Vector<real>::Vector()
    {
        v_tuples[0] = (real)0;
        v_tuples[1] = (real)0;
        v_tuples[2] = (real)0;
        v_tuples[3] = (real)0;
    }

    template <typename real>
    Vector<real>::Vector(real x, real y)
    {
        v_tuples[0] = x;
        v_tuples[1] = y;
        v_tuples[2] = (real)0;
        v_tuples[3] = (real)0;
    }

    template <typename real>
    Vector<real>::Vector(real x, real y, real z)
    {
        v_tuples[0] = x;
        v_tuples[1] = y;
        v_tuples[2] = z;
        v_tuples[3] = (real)0;
    }

    template <typename real>
    Vector<real>::Vector(real x, real y, real z, real w)
    {
        v_tuples[0] = x;
        v_tuples[1] = y;
        v_tuples[2] = z;
        v_tuples[3] = w;
    }

    template <typename real>
    Vector<real>::Vector(const real array[])
    {
        // INPUT: 3 tuple array
        v_tuples[0] = array[0];
        v_tuples[1] = array[1];
        v_tuples[2] = array[2];
        // OUTPUT: 4 tuple array
        v_tuples[3] = (real)0;
    }

    // GETTERS & SETTERS

    template <typename real>
    real Vector<real>::x() { return v_tuples[0]; };
    template <typename real>
    void Vector<real>::x(real x) { v_tuples[0] = x; }

    template <typename real>
    real Vector<real>::y() { return v_tuples[1]; }
    template <typename real>
    void Vector<real>::y(real y) { v_tuples[1] = y; }

    template <typename real>
    real Vector<real>::z() { return v_tuples[2]; }
    template <typename real>
    void Vector<real>::z(real z) { v_tuples[2] = z; }

    template <typename real>
    real Vector<real>::w() { return v_tuples[3]; }

    template <typename real>
    real Vector<real>::Element(int index)
    {
        return v_tuples[index];
    }

    // METHODS

    template <typename real>
    Vector<real> Vector<real>::GetVector()
    {
        Vector<real> u(v_tuples[0], v_tuples[1], v_tuples[2]), v_tuples[3];
        return u;
    }

    template <typename real>
    Vector<real> Vector<real>::UnitVector()
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
        Vector<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    real Vector<real>::Magnitude()
    {
        real sum = 0;
        sum += v_tuples[0] * v_tuples[0];
        sum += v_tuples[1] * v_tuples[1];
        sum += v_tuples[2] * v_tuples[2];
        return sqrt(sum);
    }

    template <typename real>
    Vector<real> Vector<real>::Distance()
    {
        return Magnitude();
    }

    template <typename real>
    Vector<real> Vector<real>::Normalize()
    {
        return UnitVector();
    }

    template <typename real>
    real Vector<real>::Dot(Vector<real> v)
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
    real Vector<real>::Dot(Vector<real> u, Vector<real> v)
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
    Vector<real> Vector<real>::Cross(Vector<real> v)
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
        Vector<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    real Vector<real>::Angle(Vector<real> v)
    {
        // Angle between 3D vecotrs
        Vector<real> u = GetVector();
        // ref: [ELA] by Shields, 1980. p.213.
        return acos((real)(u.Normalize() * v.Normalize()));
    }

    template <typename real>
    Vector<real> Vector<real>::PerpVectorXY()
    {
        // Perp (XY) Operation
        real x = (real)-1 * v_tuples[1]; // -y
        real y = v_tuples[0];            // x
        real z = (real)0;

        // Constructed
        Vector<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector<real> Vector<real>::ProjV(Vector<real> v)
    {
        // Project this.vector u onto v...
        // Constructed
        Vector<real> u = GetVector();
        // real magnitude = v.Magnitude();

        // real dotUV = u * v;
        // real dotVV = v * v;
        // real quot = dotUV / dotVV;
        // where dotVV is equivalent to Square(v.Magnitude())...
        // ref: (1) [ELA] by Shields, 1980. p.237.
        //      (2) [Mf3DG&CG] 2nd Ed. by Lengyel, 2004. p19.
        real quot = (u * v) / (v * v);

        // Constructed
        Vector<real> vector = v * quot;
        return vector;
    }

    // OPERATORS

    template <typename real>
    Vector<real> Vector<real>::operator-()
    {
        real x = v_tuples[0] * (real)-1.0;
        real y = v_tuples[1] * (real)-1.0;
        real z = v_tuples[2] * (real)-1.0;

        // Constructed
        Vector<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector<real> Vector<real>::operator*(real s)
    {
        real x = v_tuples[0] * s;
        real y = v_tuples[1] * s;
        real z = v_tuples[2] * s;

        // Constructed
        Vector<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector<real> Vector<real>::operator+(Vector<real> v)
    {
        real x = v_tuples[0] + v.x();
        real y = v_tuples[1] + v.y();
        real z = v_tuples[2] + v.z();

        // Constructed
        Vector<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector<real> Vector<real>::operator-(Vector<real> v)
    {
        real x = v_tuples[0] - v.x();
        real y = v_tuples[1] - v.y();
        real z = v_tuples[2] - v.z();

        // Constructed
        Vector<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    real Vector<real>::operator*(Vector<real> v)
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
    Vector<real> Vector<real>::operator^(Vector<real> v)
    {
        // a2b3 - a3b2
        real x = (v_tuples[1] * v.z()) - (v_tuples[2] * v.y());
        // a3b1 -a1b3
        real y = (v_tuples[2] * v.x()) - (v_tuples[0] * v.z());
        // a1b2 - a2b1
        real z = (v_tuples[0] * v.y()) - (v_tuples[1] * v.x());

        // Constructed
        Vector<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Vector<real> Vector<real>::operator=(Vector<real> v)
    {
        v_tuples[0] = v.x();
        v_tuples[1] = v.y();
        v_tuples[2] = v.z();

        // Constructed
        Vector<real> vector = GetVector();
        return vector;
    }
}
#endif
