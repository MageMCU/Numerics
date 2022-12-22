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

#ifndef Numerics_Test_TimeNMR_h
#define Numerics_Test_TimeNMR_h

#include "../TESTS/Common.h"

// Keep Global Objects Active
nmr::Timer oneSecTimer = nmr::Timer();
nmr::Timer loadTimer = nmr::Timer();
nmr::Timer speedTimer = nmr::Timer();

// Global Declaration
nmr::TimeNMR<float> deltaT;
float speed = 0.0;
void DeltaTime_T3_HowToUse(String s)
{
    Serial.print(s);
    Serial.println(String(speed, 7));
}

void DeltaTime_T2_DeltaTime()
{
    // Time Test
    Serial.print("DeltaTime: ");
    // Rounding Errors
    // Serial.println(deltaT.DeltaTime());
    // To 7 decimal places
    Serial.println(String(deltaT.DeltaTime(), 7));
}

void DeltaTime_T1_Constructor()
{
    // Constructor - See Global
    // above for declaration...
    deltaT = nmr::TimeNMR<float>();
    // Nothing printed here...
}

// This test is a little complicated..., enjoy.
bool ONCE = true;
void DeltaTimeLoop()
{
    // Suggestion - Do not comment-out anything here...
    if (ONCE)
    {
        ONCE = false;
        // Initiate Delta Time ONCE...
        // Test 1 - always required...
        DeltaTime_T1_Constructor();
    }
    else
    {
        // One-Second Timer
        // Has no affect on Time.DeltaTime
        // Tests 2 and 3
        if (oneSecTimer.isTimer(1000))
        {
            printTitle("One-Second Timer");
            DeltaTime_T2_DeltaTime();
            DeltaTime_T3_HowToUse("Per 1-Sec: ");
            // Reset speed after each second
            speed = 0.0;
            // (1) Change the load above..., should
            // get the same results...
            //
        }

        // Give the ProcessDT a little dalay
        // to simulate a heavier load process time...
        // True - no dalay
        // False - 100 ms delay
        // In both cases, notice inconsistent time intervals...
        if (true)
        {
            // No Delay
            // Process at every tick...
            deltaT.ProcessDT();
            // This should always be placed in Arduino's Loop()

            // How to Use - DeltaTime_T3_HowToUse();
            // speed = 2.4; // units (m/s) once every sec
            speed += 2.4 * deltaT.DeltaTime();
        }
        else
        {
            // Simiulation Higher Load Process Time

            if (loadTimer.isTimer(100))
            {
                // Delay
                // 100 ms load test
                deltaT.ProcessDT();

                // How to Use - DeltaTime_T3_HowToUse();
                // speed = 2.4; // units (m/s) once every sec
                speed += 2.4 * deltaT.DeltaTime();
                // This should always be placed in Arduino's Loop()
            }
        }
    }
}

#endif
