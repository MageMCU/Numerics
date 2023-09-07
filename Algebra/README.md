## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h** 
    - reviewed 20230807
- **LinearMap.h**   
    - reviewed 20230807
- **Timer.h**    
    - reviewed 20230807 
- **Vector2.h** 
    - Reviewed 20230820
- **Vector3.h**    
    - Reviewed 20230827
- **RandomNumber.h**  
    - reviewed 20230807
- **Statistics.h** 
    - reviewed 20230807
- **MiscMath.h**
    - reviewed 20230807

***Herachical relationships have changed to include quaternion.h into matrices***
+ **Point2.h**
    - Reviewed 20230904
+ **Point3.h**  
    - Reviewed 20230904
+ **Quaternion.h** 
+ **Matrix.h**   
+ **Matrix2x2.h**  .. 
+ **Matrix3x3.h**.
+ **Matrix4x4.h**

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
- See ***Map Numerics.pdf*** in how header files are associated...

