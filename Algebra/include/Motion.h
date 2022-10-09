//
// Carpenter Software
// File: Class Motion.h
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
// Created 20221009
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Motion_h
#define Numerics_Motion_h

#include "Arduino.h"

namespace Numerics
{
    template <typename real>
    class Motion
    {
    private:
        // Private Members
        real m_dx;
        real m_v;
        real m_vo;
        real m_dt;

    public:
        // Constructor
        Motion() {}
        // Destructor
        ~Motion() {}

        // Public Methods
        real dt(real dt);
        real v(real dx);
        real a(real v);
        real map(real x, real x1, real x2, real y1, real y2);
    };

    template <typename real>
    real Motion<real>::dt(real dt)
    {
        // Time interval set to timer giving dt
        m_dt = dt;
        return dt;
    }

    template <typename real>
    real Motion<real>::v(real dx)
    {
        // Time interval set to timer giving dx
        m_dx = dx;
        return dx / m_dt;
    }

    template <typename real>
    real Motion<real>::a(real v)
    {
        // Last speed
        m_vo = m_v;
        // Current speed
        m_v = v;
        return (m_v - m_vo) / m_dt;
    }

    template <typename real>
    real Motion<real>::map(real x, real x1, real x2, real y1, real y2)
    {
        // Assume linear functions
        // m = (y2 - y1)/(x2 - x1)
        // (y - y1) = m(x - x1)
        return (y2 - y1) * (x - x1) / (x2 - x1) + y1;
    }
}
#endif
