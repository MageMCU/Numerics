//
// Carpenter Software
// File: TestTimeNMR.h
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

#ifndef Numerics_Test_Timer_h
#define Numerics_Test_Timer_h

#include "../TESTS/Common.h"

void Timer_T1_Inclusive_Test()
{
    printTitle("Timer T1 Inclusive Test");
    // Timer Instantiation
    nmr::Timer testTimer = nmr::Timer();
    // Test
    int cnt = 0;
    do
    {
        // Timer set for 1s intervals
        if (testTimer.isTimer(1000))
        {
            // Delta Time in Seconds
            printResult("DeltaTime 1s: ", testTimer.DeltaTimeSeconds());
            // counter
            cnt++;
        }
    } while (cnt < 5);

}

#endif
