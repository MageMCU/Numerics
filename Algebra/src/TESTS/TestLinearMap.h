//
// Carpenter Software
// File: TestLinearMap.h
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


#ifndef Numerics_Test_Linear_Map_h
#define Numerics_Test_Linear_Map_h

#include "../TESTS/Common.h"

void LinearMap_T1_Inclusive_Test()
{
    printTitle("LinearMap T1 Inclusive Test");

    // Constructor 
    nmr::LinearMap<float> mapCelcius =
        nmr::LinearMap<float>(32, 212, 0, 100);
    // Random Float
    // The constructor inputs an integer (int) type 
    // while RandomReal() outpuits a real (float)...
    nmr::RandomNumber<int, float> random =
        nmr::RandomNumber<int, float>(32, 212);
    // Test
    float celcius;
    float fahrenheit;
    for (int i = 0; i < 10; i++)
    {
        fahrenheit = random.RandomReal();
        celcius = mapCelcius.Map(fahrenheit);
        printResults("fahrenheit: ", fahrenheit, " - Celsius: ", celcius);
    }
}

#endif
