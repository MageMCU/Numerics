## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h**        (20221220 - Recently updated - used in FSM...)
- **TimeNMR.h**        (20221221 Name change from *DeltaTime.h* to *TimeNMR.h*.)
- **MiscMath.h**       (Was Math.h - Naming Issues while using the name Math...)
- **Motion.h**         (It's been awhile - **Deleted** - didn't make any sense...)
- **Timer.h**          (*Timer.h* was copied from the *Joystick_Uno_L298N* Depository. There was the private property in the class called *_lastMillisecond*. Since it was never used, it is now removed in this update. Also the namespace has changed from *uno* to *nmr* (Numerics) since it is part of *TimeNMR.h*... Therefore, there are two copies, one in each of the depositories: *Numerics* and *Joystick_Uno_L298N*...)

***Followng classes are in an hierachical relationship***
+ ***Vector2.h***      (could be used as stand-alone - code tested ok)
+ ***Vector3.h***      (could be used as stand-alone - code tested ok)
+ ***Point2.h***       (depended on Vector2.h - code tested ok)
+ ***Point3.h***       (depended on Vector3.h - code tested ok)
+ ***Matrix.h***       (depended on Point2.h & Point3.h - code tested ok) 
+ ***Quaternion.h***   (depended on Matrix.h - code tested ok)

## ***src folder***

- MainMan
    - main.cpp
- MainDied ------------------- DELETED 20221221
    - main.cpp --------------- DELETED 20221221
- TESTS 
    - Common.h          (Used for all TESTS files mainly for Serial.print...)
    - TestBitwise.h
    - TestMatrix.h
    - TestPoint2.h
    - TestPoint3.h
    - TestQuaternion.h
    - TestTimeNMR.h
    - TestVector2.h
    - TestVector3.h

## ***root folder***

- platformio.ini        (Updated 20221221: please review this document for platform configuration while testing the code.)

## ***Notes***

- The MainMan folder - *main.cpp* - has all the testing functions for each class. The exception is the *TestTimeNMR.h*. Please study *main.cpp*, *TestTimeNMR.h* and *TimeNMR.h*. This uses Arduino's *Loop()* function and it is presently active for testing. Just follow the *bread crums* and you'll be OK...
- As of 20221221, the *TestTimeNMR.h* - TESTS-completed...
- Testing on *MiscMath.h* - TESTS-pending... This will be the last file tested...

