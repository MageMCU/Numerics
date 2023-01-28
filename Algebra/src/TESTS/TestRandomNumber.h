//
// Carpenter Software
// File: TestRandomNumber.h
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


#ifndef Numerics_Test_Random_Number_h
#define Numerics_Test_Random_Number_h

#include "../TESTS/Common.h"

void RandomNumber_T1_Inclusive_Test()
{
    printTitle("RandomNumber T1 Inclusive");

    nmr::RandomNumber<float> randomNumber = nmr::RandomNumber<float>((float)0, (float)10);

    int cnt = 0;
    while (cnt < 100)
    {
        // Small range - buggy - OK
        Serial.println(String(randomNumber.Random()));
        cnt++;
    }

}
#endif
