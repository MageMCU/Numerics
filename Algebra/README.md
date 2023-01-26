## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h**   
- **LinearMap.h**      
    - (updated)
- **Timer.h**          
    - (updated)
- **Vector2.h**    
- **Vector3.h**    
- **RandomNumber.h**   
    - (updated)

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

## ***src folder***

- MAIN folder
    - main.cpp
- TESTS folder
    - Common.h          
        - (Used for all TESTS files mainly for Arduino's Serial.print...)
    - TestBitwise.h
    - TestLinearMap.h 
    - TestMatrix.h
    - TestMiscMath.h
    - TestPoint2.h
    - TestPoint3.h
    - TestQuaternion.h
    - TestRandomNumber.h
    - TestTimer.h  
    - TestVector2.h
    - TestVector3.h

## ***root folder***

- platformio.ini        
    - (Please review this document for platform configuration while testing the code.)

## ***Notes***

- 20230125 Updated LinearMap.h Class, RandomNumer.h Class and Timer.h Class for PID...

