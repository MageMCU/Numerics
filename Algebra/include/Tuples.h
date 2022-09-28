//
// Carpenter Software
// File: Class Tuples.h
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


#ifndef TUPLES_H
#define TUPLES_H

#include "Arduino.h"

namespace Numerics
{
    template <typename real>
    class Tuples
    {
    private:
        // Members
        /*
        real _x;
        real _y;
        real _z;
        real _w;
        */

    public:
        // Constructors
        Tuples() {};
        // Tuples(real x, real y);
        // Tuples(real x, real y, real z);
        virtual ~Tuples() {};

        // getters
        virtual real x() = 0;
        virtual real y() = 0;
        virtual real z()= 0;
        virtual real w()= 0;

        // setters
        virtual void x(real x) = 0;
        virtual void y(real y) = 0;
        virtual void z(real z) = 0;
    };

    /*
    template <typename real>
    Tuples<real>::Tuples()
    {
        _x = 0;
        _y = 0;
        _z = 0;
        _w = 0;
    }

    template <typename real>
    Tuples<real>::Tuples(real x, real y)
    {
        _x = x;
        _y = y;
        _z = 0;
        _w = 0;
    }

    template <typename real>
    Tuples<real>::Tuples(real x, real y, real z)
    {
        _x = x;
        _y = y;
        _z = z;
        _w = 0;
    }

    template <typename real>
    real Tuples<real>::x() { return _x; }
    template <typename real>
    real Tuples<real>::y() { return _y; }
    template <typename real>
    real Tuples<real>::z() { return _z; }
    template <typename real>
    real Tuples<real>::w() { return _w; }

    template <typename real>
    void Tuples<real>::x(real x) { _x = x; }
    template <typename real>
    void Tuples<real>::y(real y) { _y = y; }
    template <typename real>
    void Tuples<real>::z(real z) { _z = z; }
    */
}

#endif