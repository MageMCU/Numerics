//
// Carpenter Software
// File: TestButton.h
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

#ifndef Numerics_Test_Button_h
#define Numerics_Test_Button_h

#include "../TESTS/Common.h"

// Button(int buttonPin, int ledPin)
Button testButton;
int buttonPin = 2;
int ledPin = 12;

void Button_Setup()
{
    // Button(int buttonPin, int ledPin)
    testButton = Button(buttonPin, ledPin);
}

void Button_Loop()
{
    testButton.updateButton();
    if (testButton.isButtonOn())
    {
        Debug("Button ON");
    }
    else
    {
        Debug("Button OFF");
    }
}
#endif