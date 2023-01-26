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
    // BUGFIX - Earlier assumptions incorrect...
    printTitle("Timer T1 Inclusive Test");

    // Let's assume the speed is always at 1 meter per second...
    float distance = (float)1; // 1 meter
    long milliSeconds = 738;
    float seconds = (float)milliSeconds * (float)0.001;
    // Timer Instantiation
    nmr::Timer testTimer = nmr::Timer();
    // Test
    int cnt = 0;
    do
    {
        // Timer set for obitrary interval
        if (testTimer.isTimer(milliSeconds))
        {
            float speed = distance / seconds;
            // Better yet beware of longer processing times.
            printResult("Distance: ", speed * testTimer.DeltaTimeSeconds());

            // counter
            cnt++;
        }
    } while (cnt < 5);

}

#endif
