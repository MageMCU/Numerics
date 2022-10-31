## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **DeltaTime.h**
- **Misc.h**           (Was Math.h)
- **Motion.h** 

***Followng classes are in an hierachical relationship***
+ ***Vector2.h***      (could be used as stand-alone - testing completed)
+ ***Vector3.h***      (could be used as stand-alone - testing)
+ ***Point2.h***       (depended on Vector2.h - tesing)
+ ***Point3.h***       (depended on Vector3.h - testing)
+ ***Matrix.h***       (depended on Point2.h & Point3.h - testing) 
+ ***Quaternion.h***   (Testing)

## ***src folder***

- MainMan
    - main.cpp -> TESTS
- MainDied
    - main.cpp -> Used to test Motion.h & DeltaTime.h
- TESTS 
    - Common.h
    - TestMatrix.h
    - TestPoint2.h
    - TestPoint3.h
    - TestVector2.h
    - TestVector3.h

## ***root folder***

- platformio.ini        (please review this document for platform configuration while testing the code.)
