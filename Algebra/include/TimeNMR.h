//
// Carpenter Software
// File: Class TimeNMR.h
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

#ifndef Numerics_TimeNMR_h
#define Numerics_TimeNMR_h

#include "Arduino.h"

namespace nmr
{
    template <typename real>
    class TimeNMR
    {
    private:
        // Private Members
        real m_seconds;
        unsigned long m_lastTime;
        unsigned long m_currentTime;

        // Private Method
        void _deltaTime();

    public:
        // Constructors
        TimeNMR();
        // Destructor
        ~TimeNMR() {}

        // Public Methods
        real DeltaTime();
        void ProcessDT();
    };

    template <typename real>
    TimeNMR<real>::TimeNMR()
    {
        m_currentTime = (unsigned long)0;
    }

    template <typename real>
    real TimeNMR<real>::DeltaTime()
    {
        return m_seconds;
    }

    template <typename real>
    void TimeNMR<real>::ProcessDT()
    {
        _deltaTime();
    }

    // Arduino Uno Documentation
    // Source: https://docs.arduino.cc/hardware/uno-rev3
    // Clock Speed - Main Processor - Atmega328P - 16 MHz
    // Should get a reading around 16 us per tick...
    template <typename real>
    void TimeNMR<real>::_deltaTime()
    {
        // Delta Time microseconds (us)
        m_currentTime = micros();
        // seconds (s)
        // note that arduino uno float is 7-decimal digits as shown...
        m_seconds = (real)(m_currentTime - m_lastTime) * (real)0.0000010;
        // save for next delta-time difference
        m_lastTime = m_currentTime;
    }
}
#endif
