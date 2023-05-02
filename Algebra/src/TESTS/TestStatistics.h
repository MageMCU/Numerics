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

#ifndef Numerics_Test_Statistics_h
#define Numerics_Test_Statistics_h

#include "../TESTS/Common.h"

void Statistics_T5_Queue()
{
    printTitle("Statistics T5 Queue");

    float tuples[]{3.2, 5.3, 7.0, 2.2, 9.8, 4.6, 0.5, 4.5, 7.4, 6.5};
    int size = 10;

    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);
    nmr::RandomNumber<float> randomNumber = nmr::RandomNumber<float>((float)0, (float)10);
    float randomNum;

    // randomNumber.Random()
    for (int i = 0; i < size; i++)
    {
        randomNum = randomNumber.Random();
        stats.Queue(randomNum, i);
        Serial.print(i);
        Serial.print(" ");
        Serial.println(String(stats.GetElement(i), 2));
    }

    Serial.print("Average: ");
    Serial.println(String(stats.Average(), 2));
    Serial.print("Standard Deviation: ");
    Serial.println(String(stats.StandardDeviation(), 2));

    //
    stats.QueueReset();
    Serial.println("Queue Reset");
    Serial.print("Standard Deviation: ");
    Serial.println(String(stats.StandardDeviation(), 2));
}

void Statistics_T4_Median()
{
    printTitle("Statistics T4 Median");

    float tuples[200];
    int size = 200;
    nmr::RandomNumber<float> rnd = nmr::RandomNumber<float>(-1.9, 2.3);

    for (int i = 0; i < size; i++)
    {
        // CAUTION: assigning random numbers...
        tuples[i] = rnd.Random();
        // DEBUG - Original ORDER
        Serial.print(String(i));
        Serial.print(" ");
        Serial.println(String(tuples[i], 2));
    }

    // ok
    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);

    printResult("Average: ", stats.Average());
    printResult("Standard Deviation: ", stats.StandardDeviation());
    printResult("Median: ", stats.Median());
    printResult("Min Value: ", stats.GetElement(0));
    printResult("Max Value: ", stats.GetElement(size - 1));

    // Debug- Sorted data taken from the class
    // Serial.println("--------------------");
    // Serial.println("--------------------");
    // for (int i = 0; i < size; i++)
    // {
    //     Serial.print(String(i));
    //     Serial.print(" ");
    //     Serial.println(String(stats.GetSorted(i), 2));
    // }
    // Serial.println("--------------------");
    // Serial.println("--------------------");

    // DEBUG - Sorted data taken from tuples[]-(as shown above)
    // for (int i = 0; i < size; i++)
    // {
    //     Serial.print(String(i));
    //     Serial.print(" ");
    //     Serial.println(String(tuples[i], 2));
    // }
}

void Statistics_T3_Standard_Deviation()
{
    printTitle("Statistics T3 Standard Deviation");

    float tuples[10];
    int size = 10;
    nmr::RandomNumber<float> rnd = nmr::RandomNumber<float>(-99999.9, 99999.9);

    for (int i = 0; i < size; i++)
    {
        // CAUTION: assigning random numbers...
        tuples[i] = rnd.Random();
        // DEBUG - Original ORDER
        Serial.print(String(i));
        Serial.print(" ");
        Serial.println(String(tuples[i], 2));
    }

    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);
    printResult("Standard Deviation: ", stats.StandardDeviation());
}

void Statistics_T2_Average()
{
    printTitle("Statistics T2 Average");

    float tuples[10];
    int size = 10;
    nmr::RandomNumber<float> rnd = nmr::RandomNumber<float>(-99999.9, 99999.9);

    for (int i = 0; i < size; i++)
    {
        // CAUTION: assigning random numbers...
        tuples[i] = rnd.Random();
        // DEBUG - Original ORDER
        Serial.print(String(i));
        Serial.print(" ");
        Serial.println(String(tuples[i], 2));
    }

    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);
    printResult("Average: ", stats.Average());
}

void Statistics_T1_Constructor()
{
    printTitle("Statistics T1 Constructor");

    float tuples[10];
    int size = 10;
    nmr::RandomNumber<float> rnd = nmr::RandomNumber<float>(-99999.9, 99999.9);

    for (int i = 0; i < size; i++)
    {
        // CAUTION: assigning random numbers...
        tuples[i] = rnd.Random();
        // DEBUG - Original ORDER
        // Serial.print(String(i));
        // Serial.print(" ");
        // Serial.println(String(tuples[i], 2));
    }

    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);

    float v;
    printResult("Array Size: ", stats.GetTuplesSize());
    for (int i = 0; i < size; i++)
    {
        v = stats.GetElement(i);
        Serial.println(String(v, 2));
    }
}

#endif
