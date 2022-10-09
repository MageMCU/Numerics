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
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef POINT3_H
#define POINT3_H

#include "Arduino.h"
#include "Vector3.h"

namespace Numerics
{
    template <typename real>
    class Point3 : Vector3<real>
    {
    private:
        real p_tuples[3];

        // Members
        // real _x;
        // real _y;
        // real _z;
        // real _w;

    public:
        // Constructors
        Point3();
        Point3(real x, real y, real z);
        Point3(const real array[]);
        // Destructor
        ~Point3(){};

        // GETTERS & SETTERS
        real Element(int index);
        real x();
        real y();
        real z();

        // Inquiry
        bool IsPoint();

        // Point-Vector Operations
        Vector3<real> operator-(Point3<real> p);
        Point3 operator+(Vector3<real> p);
    };

    // Constructors

    template <typename real>
    Point3<real>::Point3()
    {
        p_tuples[0] = (real)0;
        p_tuples[1] = (real)0;
        p_tuples[2] = (real)0;
    }

    template <typename real>
    Point3<real>::Point3(real x, real y, real z)
    {
        p_tuples[0] = x;
        p_tuples[1] = y;
        p_tuples[2] = z;
    }

    template <typename real>
    Point3<real>::Point3(const real array[])
    {
        p_tuples[0] = array[0];
        p_tuples[1] = array[1];
        p_tuples[2] = array[2];
    }

    // GETTERS & SETTERS
    template <typename real>
    real Point3<real>::Element(int index)
    {
        return p_tuples[index];
    }

    template <typename real>
    real Point3<real>::x() { return p_tuples[0]; }
    template <typename real>
    real Point3<real>::y() { return p_tuples[1]; }
    template <typename real>
    real Point3<real>::z() { return p_tuples[2]; }

    // Point-Vector Operations

    template <typename real>
    Vector3<real> Point3<real>::operator-(Point3<real> p)
    {
        real x = p_tuples[0] - p.x();
        real y = p_tuples[1] - p.y();
        real z = p_tuples[2] - p.z();

        // Constructed
        Vector3<real> vector(x, y, z);
        return vector;
    }

    template <typename real>
    Point3<real> Point3<real>::operator+(Vector3<real> v)
    {
        real x = p_tuples[0] + v.x();
        real y = p_tuples[1] + v.y();
        real z = p_tuples[2] + v.z();

        Point3<real> point(x, y, z);
        return point;
    }
}

#endif