## Numerics

- namespace ***nmr***

## ***include folder***

**Following classes are stand-alone**
- **Bitwise.h** 
- **LinearMap.h**   
- **Timer.h**     
- **Vector2.h** 
    - Reviewed 20230820 - bugfix: Perp()
- **Vector3.h**    
    - Reviewed 20230827 - fixes...
- **RandomNumber.h**  
- **Statistics.h** 
- **MiscMath.h**

***Herachical relationships have changed to include quaternion.h into matrices***
+ **Point2.h**
+ **Point3.h**  
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
        - 20230820 - bugfix, Additional tests...
    - TestVector3.h
        - 20230827 - fixes...

## ***root folder***

- platformio.ini
    - Added additional notes... 20230501
    - (Please review this document for platform configuration while testing the code.)

## ***Notes***
- See ***Map Numerics.pdf*** in how header files are associated...

