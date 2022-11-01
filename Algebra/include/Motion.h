//
// Carpenter Software
// File: Class Motion.h
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
//
// Algebra OOP Library
// The math is underneath the namespace
// nmr for Numerics as in numeric computation.
//
// By Jesse Carpenter (carpentersoftware.com)
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

namespace nmr
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
}
#endif
