//
// Carpenter Software
// File: main.cpp - DO NOT USE
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
// Testing: DeltaTime.h & Motion.h
//
// Algebra OOP Library
// The math is underneath the namespace
// nmr for Numerics as in numeric computation.
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

#include <Arduino.h>
#include "Timer.h" // Use from Joystick_Uno_L298N
#include "DeltaTime.h"
#include "Motion.h"

// GLOBAL VARIABLES
uno::Timer timer;
nmr::DeltaTime<float> deltaTime;
nmr::Motion<float> motion;

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
    }

    timer = uno::Timer();
    deltaTime = nmr::DeltaTime<float>();
    motion = nmr::Motion<float>();
}

void loop()
{
    if (timer.isTimer(250))
    {
        // To Study Encoded Motors
        // Using Large delta time 250 ms
        // Addendum: Suggested to use gravity g = 9.8 m/s*s
        //           y - yo = vo(t) - 0.5g(t * t);
        //           dy = -0.5 * 9.8 * t * t;
        //   where   t = time - startTime;
        float deltaDistance = (float)random(20000, 30000);
        float dt = motion.dt(deltaTime.dt());
        float speed = motion.v(deltaDistance);
        float acceleration = motion.a(speed);

        Serial.print("dx: ");
        Serial.print(deltaDistance);
        Serial.print(" dt: ");
        Serial.print(dt);
        Serial.print(" v: ");
        Serial.print(speed);
        Serial.print(" a: ");
        Serial.println(acceleration);
    }
}
