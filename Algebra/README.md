## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h**       (New - used in FSM)
- **DeltaTime.h**
- **Misc.h**           (Was Math.h - Naming Issues while using the name Math)
- **Motion.h** 

***Followng classes are in an hierachical relationship***
+ ***Vector2.h***      (could be used as stand-alone - code tested ok)
+ ***Vector3.h***      (could be used as stand-alone - code tested ok)
+ ***Point2.h***       (depended on Vector2.h - code tested ok)
+ ***Point3.h***       (depended on Vector3.h - code tested ok)
+ ***Matrix.h***       (depended on Point2.h & Point3.h - code tested ok) 
+ ***Quaternion.h***   (depended on Matrix.h - code tested ok)

## ***src folder***

- MainMan
    - main.cpp -> TESTS
- MainDied
    - main.cpp -> Used to test Motion.h & DeltaTime.h - dependency Timer.h.
- TESTS 
    - Common.h
    - TestMatrix.h
    - TestPoint2.h
    - TestPoint3.h
    - TestQuaternion.h
    - TestVector2.h
    - TestVector3.h

## ***root folder***

- platformio.ini        (please review this document for platform configuration while testing the code.)
