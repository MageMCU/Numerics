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
// Created 20220927
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef POINT_H
#define POINT_H

#include "Arduino.h"
#include "Tuples.h"
#include "Vector.h"

namespace Numerics
{
    template <typename real>
    class Point : Vector<real>
    {
    private:
        // Members
        real _x;
        real _y;
        real _z;
        real _w;

    public:
        // Constructors
        Point();
        Point(real x, real y);
        Point(real x, real y, real z);

        // Destructor
        ~Point(){};

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
        bool IsPoint();

        // Point-Vector Operations
        Vector<real> operator-(Point<real> p);
        Point operator+(Vector<real> p);
    };

    // Constructors

    template <typename real>
    Point<real>::Point()
    {
        _x = 0;
        _y = 0;
        _z = 0;
        _w = 1;
    }

    template <typename real>
    Point<real>::Point(real x, real y)
    {
        _x = x;
        _y = y;
        _z = 0;
        _w = 1;
    }

    template <typename real>
    Point<real>::Point(real x, real y, real z)
    {
        _x = x;
        _y = y;
        _z = z;
        _w = 1;
    }

    // getters

    template <typename real>
    real Point<real>::x() { return _x; }
    template <typename real>
    real Point<real>::y() { return _y; }
    template <typename real>
    real Point<real>::z() { return _z; }
    template <typename real>
    real Point<real>::w() { return _w; }

    // setters

    template <typename real>
    void Point<real>::x(real x) { _x = x; }
    template <typename real>
    void Point<real>::y(real y) { _y = y; }
    template <typename real>
    void Point<real>::z(real z) { _z = z; }

    // Inquiry

    template <typename real>
    bool Point<real>::IsPoint()
    {
        return (_w == 1);
    }

    // Point-Vector Operations

    template <typename real>
    Vector<real> Point<real>::operator-(Point<real> p)
    {
        Vector<real> results = {};

        results.x(_x - p.x());
        results.y(_y - p.y());
        results.z(_z - p.z());

        return results;
    }

    template <typename real>
    Point<real> Point<real>::operator+(Vector<real> v)
    {
        Point<real> results = {};

        results.x(_x + v.x());
        results.y(_y + v.y());
        results.z(_z + v.z());

        return results;
    }
}

#endif