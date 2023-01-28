//
// Carpenter Software
// File: Class Bitwise.h
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

#ifndef Numerics_Random_Number_h
#define Numerics_Random_Number_h

#include <Arduino.h>

namespace nmr
{
    template <typename real>
    class RandomNumber
    {
    public:
        // Constructor
        RandomNumber() = default;
        RandomNumber(real minValue, real maxValue);
        ~RandomNumber() = default;
        // Methods
        real Random();
    private:
        // Properties
        real m_Min;
        real m_Max;
        long m_lastRandom;

        // Methods
        long m_randomInteger();
        real m_randomReal();
        void m_seed();
    };

    template <typename real>
    RandomNumber<real>::RandomNumber(real minValue, real maxValue)
    {
        m_Min = minValue;
        m_Max = maxValue;
        m_lastRandom = (real)0;
    }


    template <typename real>
    real RandomNumber<real>::Random()
    {
        return m_randomReal();
    }

    // Private Methods

    template <typename real>
    long RandomNumber<real>::m_randomInteger()
    {
        // BUGFIX - OOPS want negative values
        // seed random with millis()
        m_seed();
        return random((long)m_Min, (long)m_Max);
    }

    template <typename real>
    real RandomNumber<real>::m_randomReal()
    {
        // seed random with millis()
        m_seed();
        // Safe Method..., under study...
        // The '7' Significant Digits Iteration 
        // is set for a float
        // The '??' Significant Digits Iteration 
        // is set for a DOUBLE?
        // Significant Digits are not decimal places 
        // but this may well be enough for doubles.
        long vMultiplier = 1; // Multiplication
        long vInteger = 0; // Addition - BUGFIX ----- Caught-Cha
        real vDecimal = (real)1; // Division
        // '7' Significant Digits Iteration
        int digits = 7;
        //
        for (int i = 0; i < digits; i++)
        {
            vInteger += random(0, 10) * vMultiplier;
            vMultiplier *= 10;
            vDecimal /= (real)10;
        }
        // 
        real vResult = (real)m_randomInteger() +
            ((real)vInteger * vDecimal);
        //
        return vResult;
    }

    template <typename real>
    void RandomNumber<real>::m_seed()
    {
        randomSeed(millis());
    }
}

#endif
