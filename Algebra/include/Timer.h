//
// Carpenter Software
// File: Class Timer.h
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
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
// Note: Timer.h was copied from the Joystick_Uno_L298N
//       Depository...
//       There was the private property in the class called
//       _lastMillisecond. Since it was never used, it is now
//       removed in this update. Also the namespace is changed
//       from uno to nmr (numaerics) since it is part of Time.h...
//

#ifndef Numerics_Timer_h
#define Numerics_Timer_h

#include <Arduino.h>

namespace nmr
{
  class Timer
  {
  private:
    long _elapsedTime;

  public:
    Timer();
    void resetTimer();
    boolean isTimer(int incrementedTime);
  };

  Timer::Timer()
  {
    _elapsedTime = -1;
  }

  void Timer::resetTimer()
  {
    _elapsedTime = -1;
  }

  boolean Timer::isTimer(int incrementedTime)
  {
    long currentTime = millis();
    if (_elapsedTime == -1)
    {
      _elapsedTime = currentTime + (long)incrementedTime;
    }
    else if (currentTime > _elapsedTime)
    {
      _elapsedTime = currentTime + (long)incrementedTime;
      return true;
    }
    return false;
  }
}
#endif
