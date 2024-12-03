//
// Carpenter Software
// File: TestTypeConv.h
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

#ifndef Numerics_Test_TypeConv_h
#define Numerics_Test_TypeConv_h

#include "Arduino.h"
#include "../TESTS/Common.h"

void TypeConv_T2_DWordTo4Bytes()
{
    printTitle("TypeConv T2 DWordTo4Bytes");
    // Notice no parenthsis...
    TypeConv typeConv;

    Debug("INT32_MAX", INT32_MAX);
    uint32_t a = 715827882;
    typeConv.DWordTo4Bytes(a);
    int b3 = typeConv.GetByte3();
    int b2 = typeConv.GetByte2();
    int b1 = typeConv.GetByte1();
    int b0 = typeConv.GetByte0();
    Debug("DWordTo4Bytes(715827882): ", b3, b2, b1, b0);
    typeConv.BytesToDWord();
    int32_t dWd = typeConv.GetDWord();
    Debug("BytesToDWord(): ", dWd);

    dWd = typeConv.BytesToDWord(b3, b2, b1, b0);
    Debug("BytesToDWord(b3, b2, b1, b0): ", dWd);
}

void TypeConv_T1_WordTo2Bytes()
{
    printTitle("TypeConv T1 WordTo2Bytes");
    // Notice no parenthsis...
    TypeConv typeConv;

    Debug("INT16_MAX", INT16_MAX);
    int a = 16234;
    typeConv.WordTo2Bytes(a);
    int hi = typeConv.GetHiByte();
    int lo = typeConv.GetLoByte();
    Debug("WordTo2Bytes(16234)", hi, lo);

    typeConv.BytesToWord();
    int wd = typeConv.GetWord();
    Debug("BytesToWord: ", wd);

    typeConv.BytesToWord(hi, lo);
    wd = typeConv.GetWord();
    Debug("BytesToWord(hi, lo): ", wd);
}

#endif