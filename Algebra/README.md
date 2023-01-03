## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h**        - (20230102 - Recently updated...)
- **LinearMap.h**      - (New Class)
- **TimeNMR.h**        - (20221221 Name change from *DeltaTime.h* to *TimeNMR.h*.)
- **Timer.h**          - (The file is located at *Simplified-Joystick-Uno-L298N* Repository)
- **Vector2.h**        - (code tested ok)
- **Vector3.h**        - (code tested ok)

***Followng classes are in an hierachical relationship***
+ ***MiscMath.h***     - (depended on *Vector3.h* - code tested ok)
+ ***Point2.h***       - (depended on *Vector2.h* - code tested ok)
+ ***Point3.h***       - (depended on *Vector3.h* - code tested ok)
+ ***Matrix.h***       - (depended on *Point2.h* & *Point3.h* - code tested ok) 
+ ***Quaternion.h***   - (depended on *Matrix.h* - code tested ok)

## ***src folder***

- MainMan folder
    - main.cpp
- TESTS folder
    - Common.h          - (Used for all TESTS files mainly for Arduino's Serial.print...)
    - TestBitwise.h
    - TestLinearMap.h   - (not yet incorporated)
    - TestMatrix.h
    - TestMiscMath.h
    - TestPoint2.h
    - TestPoint3.h
    - TestQuaternion.h
    - TestTimeNMR.h
    - TestVector2.h
    - TestVector3.h

## ***root folder***

- platformio.ini        (Please review this document for platform configuration while testing the code.)

## ***Notes***

- The MainMan folder - *main.cpp* - has all the testing functions for each class. The exception is the *LinearMap.h*.
- As of 20230102, the *LinearMap.h* - as of yet, there is no testing except in the *Simplified-Joystick-Uno-L298N* Repository.

