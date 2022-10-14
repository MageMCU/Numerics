# Numerics

</hr>

### Classes

**Following classes are stand-alone**
- **DeltaTime.h**
- **Math.h**           (Angle Class moved here temporarily)
- **Motion.h**         (map-function moved here)

***Followng classes are in an hierachical relationship***
+ ***Vector.h***      (could be used as stand-alone)
+ ***Point.h***       (depended on Vector3.h)
+ ***Matrix.h***      (depended on Vector3.h) The plan is to incorporate the dependency on both Point.h & Vector.h...
+ *Quaternion.h*        (working process)

### Testing

- Tests.h            (Lots of testing...)

</hr>

### Main

- main.cpp
- main.cpp.1.txt      (Used to test Motion.h & DeltaTime.h) There is a required dependency 'Timer.h' class located under the repository Joystick_Uno_L298N.
