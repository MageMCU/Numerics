//
// Carpenter Software
// File: TestTimer.h
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

#ifndef Numerics_Test_Timer_h
#define Numerics_Test_Timer_h

#include "../TESTS/Common.h"

void Timer_T1_Inclusive_Test()
{
    printTitle("Timer T1 Inclusive Test");

    // TPS - Ticks per Second
    float TPS = (float)0;
    // At 60 TPS, the Period is between 16 and 17 milliseconds
    // approximately 16.6666667 ms.
    long timeInterval = 16;

    // Timer Instantiation
    Timer testTimer = Timer();
    
    // Test Delta Time
    int cnt = 0;
    do
    {
        // Timer set for obitrary interval
        if (testTimer.isTimer(timeInterval))
        {
            TPS = 1.0 / testTimer.DeltaTimeSeconds();
            Debug("TPS: ", TPS);

            // counter
            cnt++;
        }
    } while (cnt < 25);
}

#endif
