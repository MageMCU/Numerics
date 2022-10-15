//
// Carpenter Software
// File: Class Point.h
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
// Updated 20221015
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Point_h
#define Numerics_Point_h

#include "Arduino.h"
#include "Vector.h"

namespace nmr
{
    template <typename real>
    class Point : Vector<real>
    {
    private:
        // Private Members
        real p_tuples[4];

    public:
        // Constructors
        Point();
        Point(real x, real y);
        Point(real x, real y, real z);
        Point(real x, real y, real z, real w);
        Point(const real array[]);
        // Destructor
        ~Point(){};

        // GETTERS & SETTERS
        real x();
        void x(real x);

        real y();
        void y(real y);

        real z();
        void z(real z);

        real w();
        real Element(int index);

        // Inquiry - All Points 4th-element always not-zero
        bool IsPoint() { return p_tuples[3] != (real)0; }
        bool IsVector() { return !IsPoint(); }

        // METHODS
        Point GetPoint();
        Vector<real> operator-(Point<real> p);
        Point operator+(Vector<real> p);
    };

    // CONSTRUCTORS

    template <typename real>
    Point<real>::Point()
    {
        p_tuples[0] = (real)0;
        p_tuples[1] = (real)0;
        p_tuples[2] = (real)0;
        p_tuples[3] = (real)1;
    }

    template <typename real>
    Point<real>::Point(real x, real y)
    {
        p_tuples[0] = x;
        p_tuples[1] = y;
        p_tuples[2] = (real)0;
        p_tuples[3] = (real)1;
    }

    template <typename real>
    Point<real>::Point(real x, real y, real z)
    {
        p_tuples[0] = x;
        p_tuples[1] = y;
        p_tuples[2] = z;
        p_tuples[3] = (real)1;
    }

    template <typename real>
    Point<real>::Point(real x, real y, real z, real w)
    {
        p_tuples[0] = x;
        p_tuples[1] = y;
        p_tuples[2] = z;
        p_tuples[3] = w;
    }

    template <typename real>
    Point<real>::Point(const real array[])
    {
        p_tuples[0] = array[0];
        p_tuples[1] = array[1];
        p_tuples[2] = array[2];
        p_tuples[3] = (real)1;
    }

    // GETTERS & SETTERS

    template <typename real>
    real Point<real>::x() { return p_tuples[0]; }
    template <typename real>
    void Point<real>::x(real x) { p_tuples[0] = x; }

    template <typename real>
    real Point<real>::y() { return p_tuples[1]; }
    template <typename real>
    void Point<real>::y(real y) { p_tuples[1] = y; }

    template <typename real>
    real Point<real>::z() { return p_tuples[2]; }
    template <typename real>
    void Point<real>::z(real z) { p_tuples[2] = z; }

    template <typename real>
    real Point<real>::w() { return p_tuples[3]; }

    template <typename real>
    real Point<real>::Element(int index)
    {
        return p_tuples[index];
    }

    // PUBLIC METHODS

    template <typename real>
    Point<real> Point<real>::GetPoint()
    {
        Point<real> p(p_tuples[0], p_tuples[1], p_tuples[2], p_tuples[3]);
        return p;
    }

    template <typename real>
    Vector<real> Point<real>::operator-(Point<real> p)
    {
        real x = p_tuples[0] - p.x();
        real y = p_tuples[1] - p.y();
        real z = p_tuples[2] - p.z();
        //   0 =    1        - 1
        real w = p_tuples[3] - p.w();

        // Constructed
        Vector<real> vector(x, y, z, w);
        return vector;
    }

    template <typename real>
    Point<real> Point<real>::operator+(Vector<real> v)
    {
        real x = p_tuples[0] + v.x();
        real y = p_tuples[1] + v.y();
        real z = p_tuples[2] + v.z();
        //   1 =    1        + 0
        real w = p_tuples[3] + v.w();

        Point<real> point(x, y, z, w);
        return point;
    }
}

#endif