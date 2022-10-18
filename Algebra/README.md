## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **DeltaTime.h**
- **Math.h**           (Angle Class moved here temporarily)
- **Motion.h**         (map-function moved here)

***Followng classes are in an hierachical relationship***
+ ***Vector.h***      (could be used as stand-alone)
+ ***Point.h***       (depended on Vector3.h)
+ ***Matrix.h***      (depended on Vector3.h) Plan: dependency on both Point.h & Vector.h...
+ *Quaternion.h*        (work in process)

## ***src folder***

- MainMan
    - main.cpp -> TESTS
- MainDied
    - main.cpp -> Used to test Motion.h & DeltaTime.h
- TESTS
    - Common.h
    - TestMatrices.h
    - TestMisc.h
    - TestPoints.h
    - TestQuaternions.h
    - TestVectors.h

## ***root folder***

- platformio.ini        (please review this document for platform configuration while testing the code.)
