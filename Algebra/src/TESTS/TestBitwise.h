//
// Carpenter Software
// File: TestBitwise.h
// Github: MageMCU
// Repository: Numerics
// Folder: TESTS
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

void Bitwise_T6_ReverseBits()
{
    printTitle("Bitwise T6 Reverse Bits");

    Bitwise<int> bw;
    int a = 0b1011001000000000;
    bw.SetBitsValue(a);
    Serial.println(bw.PrintBinaryBits());
    int b = bw.ReverseBits(a);
    bw.SetBitsValue(b);
    Serial.println(bw.PrintBinaryBits());
}

void Bitwise_T5_GetBitsValue()
{
    printTitle("Bitwise T5 GetBitsValue");

    Bitwise<int> bw;
    bw.SetBitsValue(99);
    // Timer Instantiation
    Timer testTimer = Timer();
    // Test
    int cnt = 10;
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

    Bitwise<int> bw;
    // Timer Instantiation
    Timer testTimer = Timer();
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
    } while (cnt < 10);
}

void Bitwise_T3_ClearBitNUmber()
{
    printTitle("Bitwise T3_ClearBitNUmber");

    Bitwise<int> bw;
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

    Bitwise<int> bw;
    bw.SetBitNumber(0);
    Debug("bw.SetBitNumber(0)");

    Serial.print("bw.IsBitNumberSet(0): ");
    if (bw.IsBitNumberSet(0))
        Serial.println("true");
    else
        Serial.println("false");

    bw.SetBitNumber(3);
    Debug("bw.SetBitNumber(3)");

    Serial.print("bw.IsBitNumberSet(3): ");
    if (bw.IsBitNumberSet(3))
        Serial.println("true");
    else
        Serial.println("false");
    //
    Debug("bw.GetBitsValue(): ", bw.GetBitsValue());
    Serial.println(bw.PrintBinaryBits());
}

void Bitwise_T1_Constructor()
{
    printTitle("Bitwise T1 Constructor");
    // Constructor
    Bitwise<int> bw;
    Serial.println("Bitwise<int> bw; ");
    //
    Serial.print("bw.GetBitsValue(): ");
    Serial.println(bw.GetBitsValue());

    Serial.print("bw.IsBitNumberSet(0): ");
    if (bw.IsBitNumberSet(0))
        Serial.println("true");
    else
        Serial.println("false");
    Serial.println(bw.PrintBinaryBits());
}
#endif
