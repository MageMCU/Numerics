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

#ifndef Numerics_Delta_Time_h
#define Numerics_Delta_Time_h

#include "Arduino.h"

namespace Numerics
{
    template <typename real>
    class DeltaTime
    {
    private:
        // Private Members
        real m_dt;
        unsigned long m_lastTime;
        unsigned long m_currentTime;

        // Private Methods
        void _dt();

    public:
        // Constructors
        DeltaTime();
        // Destructor
        ~DeltaTime() {}

        // Public Methods
        real dt();
    };

    template <typename real>
    DeltaTime<real>::DeltaTime()
    {
        m_currentTime = (unsigned long)0;
    }

    template <typename real>
    real DeltaTime<real>::dt()
    {
        _dt();
        return m_dt;
    }

    template <typename real>
    void DeltaTime<real>::_dt()
    {
        // Use Timer.h (Github MageMCU)
        // Place dt() within loop() within
        // conditional:
        // if (isTimer) { float dt = dt(); }
        // Used for Under development...
        m_lastTime = m_currentTime;
        m_currentTime = millis();
        m_dt = (real)(m_currentTime - m_lastTime);
    }
}
#endif
