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

    printTitle("Statistics T4 Median");

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
        Serial.println(String(stats.GetElement(i),2));
    }
    
    Serial.print("Average: ");
    Serial.println(String(stats.Average(),2));
    Serial.print("Standard Deviation: ");
    Serial.println(String(stats.StandardDeviation(),2));

    // 
    stats.QueueReset();
    Serial.println("Queue Reset");
    Serial.print("Standard Deviation: ");
    Serial.println(String(stats.StandardDeviation(),2));
}

void Statistics_T4_Median()
{
    printTitle("Statistics T4 Median");

    float tuples[]{3.2, 5.3, 7.0, 2.2, 9.8, 4.6, 0.5, 4.5, 7.4, 6.5};
    int size = 10;

    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);

    String str = "Median: " + String(stats.Median(), 2);
    Serial.println(str);
    Serial.println("--------------------");
    for (int i = 0; i < size; i++)
    {
        str = String(i) + " " + String(stats.GetSorted(i), 2);
        Serial.println(str);
    }
}

void Statistics_T3_Standard_Deviation()
{
    printTitle("Statistics T3 Standard Deviation");

    float tuples[]{3.2, 5.3, 7.0, 2.2, 9.8, 4.6, 0.5, 4.5, 7.4, 6.5};
    int size = 10;

    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);
    Serial.println(String(stats.StandardDeviation()));
}

void Statistics_T2_Average()
{
    printTitle("Statistics T2 Average");

    float tuples[]{3.2, 5.3, 7.0, 2.2, 9.8, 4.6, 0.5, 4.5, 7.4, 6.5};
    int size = 10;

    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);
    Serial.println(String(stats.Average()));
}

void Statistics_T1_Constructor()
{
    printTitle("Statistics T1 Constructor");

    float tuples[]{3.2, 5.3, 7.0, 2.2, 9.8, 4.6, 0.5, 4.5, 7.4, 6.5};
    int size = 10;

    nmr::Statistics<float> stats = nmr::Statistics<float>(tuples, size);

    float v;
    Serial.println(stats.GetTuplesSize());

    for (int i = 0; i < size; i++)
    {
        v = stats.GetElement(i);
        Serial.println(String(v, 1));
    }
}

#endif
