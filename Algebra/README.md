## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h**   
- **LinearMap.h**   
- **Timer.h**     
- **Vector2.h**    
- **Vector3.h**    
- **RandomNumber.h**   

***Followng classes are in an hierachical relationship***
+ ***Matrix.h***       
    - (depended on *Point2.h* & *Point3.h*) 
+ ***MiscMath.h***     
    - (depended on *Vector3.h*)
+ ***Point2.h***       
    - (depended on *Vector2.h*)
+ ***Point3.h***       
    - (depended on *Vector3.h*)
+ ***Quaternion.h***   
    - (depended on *Matrix.h*)

***Presently under development***
- ***Matrix2x2.h*** (Updated 20230419 - Mostly completed...)    
    - (depended on *Matrix.h*) 
- ***Matrix3x3.h*** (In process 20230419)
    - (depended on *Matrix.h*) 
- ***Matrix4x4.h*** (pending)
    - (depended on *Matrix.h*) 
- ***Statistics.h*** (Updated 20230407) 

## ***src folder***

- MAIN folder
    - main.cpp
- TESTS folder
    - Common.h          
        - (Used for all TESTS files mainly for Arduino's Serial.print...)
    - TestBitwise.h
    - TestLinearMap.h 
    - TestMatrix.h
    - TestMatrix2x2.h (Completed)
    - TestMatrix3x3.h (In Process)
    - TestMatrix4x4.h (pending)
    - TestMiscMath.h
    - TestPoint2.h
    - TestPoint3.h
    - TestQuaternion.h
    - TestRandomNumber.h
    - TestStatistics.h (working)
    - TestTimer.h  
    - TestVector2.h
    - TestVector3.h

## ***root folder***

- platformio.ini        
    - (Please review this document for platform configuration while testing the code.)

## ***Notes***
- See comments in Matrix.h - not working correctly...

