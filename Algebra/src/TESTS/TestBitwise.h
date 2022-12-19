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
// CHANGELOG
// Created 20221219
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

void Bitwise_T1_Contructor()
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
