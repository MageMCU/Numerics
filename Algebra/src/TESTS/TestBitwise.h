//
// Carpenter Software
// File: TestBitwise.h
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
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Test_Bitwise_h
#define Numerics_Test_Bitwise_h

#include "../TESTS/Common.h"

void Bitwise_T5_GetBitsValue()
{
    printTitle("Bitwise T5 GetBitsValue");

    nmr::Bitwise<int> bw;
    bw.SetBitsValue(99);
    // Timer Instantiation
    nmr::Timer testTimer = nmr::Timer();
    // Test
    int cnt = 99;
    do
    {
        if (testTimer.isTimer(500))
        {
            bw.SetBitsValue(cnt);
            printSpecial("Bits Value: ", bw.GetBitsValue(), bw.PrintBinaryBits());
            // counter
            cnt--;
        }
        // Iterates less than a minute
    } while (cnt >= 0);
}

void Bitwise_T4_SetBitsValue()
{
    printTitle("Bitwise T4 SetBitsValue");

    nmr::Bitwise<int> bw;
    // Timer Instantiation
    nmr::Timer testTimer = nmr::Timer();
    // Test
    int cnt = 0;
    do
    {
        if (testTimer.isTimer(500))
        {
            bw.SetBitsValue(cnt);
            printSpecial("Bits Value: ", cnt, bw.PrintBinaryBits());
            // counter
            cnt++;
        }
        // Iterates less than a minute
    } while (cnt < 100);
}

void Bitwise_T3_ClearBitNUmber()
{
    printTitle("Bitwise T3_ClearBitNUmber");

    nmr::Bitwise<int> bw;
    bw.SetBitNumber(0);
    Serial.println("bw.SetBitNumber(0) ");
    Serial.print("bw.GetBitsValue(): ");
    Serial.println(bw.GetBitsValue());
    Serial.print("bw.IsBitNumberSet(0): ");
    if (bw.IsBitNumberSet(0))
    {
        Serial.println("true");
    }
    else
    {
        Serial.println("false");
    }
    Serial.println(bw.PrintBinaryBits());

    bw.ClearBitNumber(0);
    Serial.println("bw.ClearBitNumber(0) ");
    Serial.print("bw.GetBitsValue(): ");
    Serial.println(bw.GetBitsValue());
    Serial.print("bw.IsBitNumberSet(0): ");
    if (bw.IsBitNumberSet(0))
    {
        Serial.println("true");
    }
    else
    {
        Serial.println("false");
    }
    Serial.println(bw.PrintBinaryBits());
}

void Bitwise_T2_SetBitNumber()
{
    printTitle("Bitwise T2_SetBitNumber");

    nmr::Bitwise<int> bw;
    bw.SetBitNumber(0);
    Serial.println("bw.SetBitNumber(0) ");
    bw.SetBitNumber(3);
    Serial.println("bw.SetBitNumber(3) ");
    //
    Serial.print("bw.GetBitsValue(): ");
    Serial.println(bw.GetBitsValue());
    Serial.print("bw.IsBitNumberSet(0): ");
    if (bw.IsBitNumberSet(0))
    {
        Serial.println("true");
    }
    else
    {
        Serial.println("false");
    }
    Serial.print("bw.IsBitNumberSet(3): ");
    if (bw.IsBitNumberSet(3))
    {
        Serial.println("true");
    }
    else
    {
        Serial.println("false");
    }
    Serial.println(bw.PrintBinaryBits());
}

void Bitwise_T1_Constructor()
{
    printTitle("Bitwise T1 Constructor");
    // Constructor
    nmr::Bitwise<int> bw;
    Serial.println("nmr::Bitwise<int> bw; ");
    //
    Serial.print("bw.GetBitsValue(): ");
    Serial.println(bw.GetBitsValue());
    Serial.print("bw.IsBitNumberSet(0): ");
    if (bw.IsBitNumberSet(0))
    {
        Serial.println("true");
    }
    else
    {
        Serial.println("false");
    }
    Serial.println(bw.PrintBinaryBits());
}
#endif
