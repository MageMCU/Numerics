//
// Carpenter Software
// File: TestRandomNumber.h
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

#ifndef Numerics_Test_Random_Number_h
#define Numerics_Test_Random_Number_h

#include "../TESTS/Common.h"

void RandomNumber_T1_RandomNumber_Test()
{
    printTitle("RandomNumber T1 Random Number");

    RandomNumber<float> randomNumber = RandomNumber<float>((float)0, (float)10);

    int cnt = 0;
    while (cnt < 100)
    {
        // Small range - buggy - OK
        Serial.println(String(randomNumber.Random()));
        cnt++;
    }
}
#endif
