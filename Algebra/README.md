## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h** 
    - removed operations meant for BusI2C.h 20230425
- **LinearMap.h**   
- **Timer.h**     
- **Vector2.h**    
- **Vector3.h**    
- **RandomNumber.h**   
    - improved the seed() initialization... 20230501

***Followng classes are in an hierachical relationship***
+ ***Matrix.h***       
    - depended on *Point2.h* & *Point3.h*
    - Unstable - PLEASE DO NOT USE at this time... 20230428
+ ***MiscMath.h***     
    - depended on *Vector3.h*
+ ***Point2.h***       
    - depended on *Vector2.h*
+ ***Point3.h***       
    - depended on *Vector3.h*
+ ***Quaternion.h***   
    - depended on *Matrix.h*

***Presently under development***
- ***Matrix2x2.h***  
    - depended on *Matrix.h*
    - updated 20230419 - Mostly completed... 
- ***Matrix3x3.h***
    - depended on *Matrix.h*
    - depended on *RandomNumber.h*
    - working 20230429 - Mostly completed...
- ***Matrix4x4.h***
    - depended on *Matrix.h*
    - pending - 20230428
- ***Statistics.h*** 
    - updated 20230501 - Completed two sort methods: Bubblesort() and Quicksort() usage depending on the data size...

## ***src folder***

- MAIN folder
    - main.cpp
- TESTS folder
    - Common.h          
        - Used for all TESTS files mainly as Arduino's Serial.print... Use as examples.
    - TestBitwise.h
    - TestLinearMap.h 
    - TestMatrix.h
    - TestMatrix2x2.h
    - TestMatrix3x3.h
    - TestMatrix4x4.h
    - TestMiscMath.h
    - TestPoint2.h
    - TestPoint3.h
    - TestQuaternion.h
    - TestRandomNumber.h
    - TestStatistics.h
    - TestTimer.h  
    - TestVector2.h
    - TestVector3.h

## ***root folder***

- platformio.ini
    - Added additional notes... 20230501
    - (Please review this document for platform configuration while testing the code.)

## ***Notes***
- See comments in Matrix.h - not working correctly...

