## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h**        
    - (checked)
- **LinearMap.h**      
    - (checked)
- **Timer.h**          
    - (checked)
- **Vector2.h**        
    - (checked)
- **Vector3.h**        
    - (checked)
- **RandomNumber.h**   
    - (checked)

***Followng classes are in an hierachical relationship***
+ ***Matrix.h***       
    - (depended on *Point2.h* & *Point3.h* - checked) 
+ ***MiscMath.h***     
    - (depended on *Vector3.h* - checked)
+ ***Point2.h***       
    - (depended on *Vector2.h* - checked)
+ ***Point3.h***       
    - (depended on *Vector3.h* - checked)
+ ***Quaternion.h***   
    - (depended on *Matrix.h* - checked)

## ***src folder***

- MainMan folder
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
    - Timer.h  
    - TestVector2.h
    - TestVector3.h

## ***root folder***

- platformio.ini        
    - (Please review this document for platform configuration while testing the code.)

## ***Notes***

- Updated *Bitwise.h* and *Timer.h* moved here. Removed *TimeNMR.h*.... 
- Replaced *TimeNMR.h* with *Timer.h* to reduce overhead...

