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

    // Let's assume the speed is always at 1 meter per second...
    float distance = (float)1; // 1 meter
    long milliSeconds = 738;
    float time = (float)milliSeconds * (float)0.001;
    float speed = distance / time;
    float displacement;

    // Timer Instantiation
    nmr::Timer testTimer = nmr::Timer();
    
    // Constants (clue: distence = speed * time)
    Serial.print("speed (m/s) = ");
    Serial.print(String(speed, 4));
    Serial.print(", time(s) = ");
    Serial.println(String(time, 4));
    
    // Test Delta Time
    int cnt = 0;
    do
    {
        // Timer set for obitrary interval
        if (testTimer.isTimer(milliSeconds))
        {
            // Displacement = speed * deltaTime = 1.000m test otherwise
            // Beware of longer loop-processing times which will change
            // the displacement result.
            // Note: DeltaTimeSeconds is NOT a constant...
            displacement = speed * testTimer.DeltaTimeSeconds();
            Serial.print("Displacement = speed * deltaTime = ");
            Serial.println(String(displacement, 4));

            // counter
            cnt++;
        }
    } while (cnt < 10);
}

#endif
