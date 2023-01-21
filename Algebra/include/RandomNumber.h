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
    template <typename integer, typename real>
    class RandomNumber
    {
    public:
        // Constructor
        RandomNumber() = default;
        RandomNumber(integer minValue, integer maxValue);
        ~RandomNumber() = default;
        // Methods
        integer RandomInteger();
        real RandomReal();
    private:
        // Properties
        integer m_minValue;
        integer m_maxValue;
        // Methods
        void m_seed();
    };

    template <typename integer, typename real>
    RandomNumber<integer, real>::RandomNumber(integer minValue, integer maxValue)
    {
        m_minValue = minValue;
        m_maxValue = maxValue;
    }

    template <typename integer, typename real>
    integer RandomNumber<integer, real>::RandomInteger()
    {
        // seed random with millis()l
        m_seed();
        // integer random number
        return (integer)random((long)m_minValue, (long)m_maxValue);
    }

    template <typename integer, typename real>
    real RandomNumber<integer, real>::RandomReal()
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
        long vMultiplier = 1;
        long vInteger = 1;
        real vDecimal = (real)1;
        for (int i = 0; i < 7; i++)
        {
            // '7' Significant Digits Iteration
            vInteger += random(0, 9) * vMultiplier;
            vMultiplier *= 10;
            vDecimal /= (real)10;
        }
        real vResult = (real)RandomInteger() +
            ((real)vInteger * vDecimal);
        while (vResult > (real)m_maxValue)
        {
            vResult -= (real)1;
        };
        return vResult;
    }

    template <typename integer, typename real>
    void RandomNumber<integer, real>::m_seed()
    {
        randomSeed(millis());
    }
}

#endif
