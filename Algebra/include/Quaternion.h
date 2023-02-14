//
// Carpenter Software
// File: Class Quaternion.h
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
//
// Algebra OOP Library
// The math is underneath the namespace
// called Numerics as in numeric computation.
//
// By Jesse Carpenter (carpentersoftware.com)
//
// CHANGELOG
// Created 20221015
// Updated 20221217
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Quaternion_h
#define Numerics_Quaternion_h

#include "Arduino.h"
#include "Matrix.h"

namespace nmr
{
    template <typename real>
    class Quaternion: Matrix<real>
    {
    private:
        // PRIVATE MEMBERS
        int m_size;
        real q_tuples[4]; // w, x, y, z

    public:
        // CONSTRUCTORS
        Quaternion();
        Quaternion(real w, real x, real y, real z);
        Quaternion(real x, real y, real z);
        Quaternion(Vector3<real> vector);
        Quaternion(Vector3<real> axis, real angleRadian);

        // DESTRUCTOR
        ~Quaternion() {}

        // GETTERS & SETTERS
        real w();
        void w(real w);
        real x();
        void x(real x);
        real y();
        void y(real y);
        real z();
        void z(real z);
        real Element(int index);
        Quaternion<real> ToQuaternion();
        Vector3<real> ToVector();

        // PUBLIC Methods
        bool NormDeviation(real test);
        real NormSquared();
        real Norm();
        Quaternion<real> Scale(real scalar);
        Quaternion<real> UnitQuaternion();
        Quaternion<real> Conjugate();
        Quaternion<real> Inverse();
	
	// Experimental ///////////////
        real GetRadianAngle();
        real GetEulerAngle();
        Vector3<real> GetAxis();
	//////////////////////////////
	
        Quaternion<real> Multiply(Quaternion<real> c);


        // OPERATORS
        Quaternion<real> operator*(Quaternion<real> c);
    };

    template <typename real>
    Quaternion<real>::Quaternion()
    {
        m_size = 4;
        q_tuples[0] = (real)0; // w
        q_tuples[1] = (real)0; // x
        q_tuples[2] = (real)0; // y
        q_tuples[3] = (real)0; // z
    }

    template <typename real>
    Quaternion<real>::Quaternion(real w, real x, real y, real z)
    {
        m_size = 4;
        q_tuples[0] = w;
        q_tuples[1] = x;
        q_tuples[2] = y;
        q_tuples[3] = z;
    }

    template <typename real>
    Quaternion<real>::Quaternion(real x, real y, real z)
    {
        m_size = 4;
        // Pure Quaternion
        q_tuples[0] = (real)0;
        q_tuples[1] = x;
        q_tuples[2] = y;
        q_tuples[3] = z;
    }

    template <typename real>
    Quaternion<real>::Quaternion(Vector3<real> vector)
    {
        m_size = 4;
        // Pure Quaternion
        q_tuples[0] = (real)0;
        q_tuples[1] = vector.x();
        q_tuples[2] = vector.y();
        q_tuples[3] = vector.z();
    }

    template <typename real>
    Quaternion<real>::Quaternion(Vector3<real> axis, real angleRadian)
    {
        m_size = 4;
        Vector3<real> normalized = axis.Normalize();
        real s = (real)sin((double)angleRadian / (double)2);
        real w = (real)cos((double)angleRadian / (double)2);
        q_tuples[0] = w;
        q_tuples[1] = normalized.x() * s;
        q_tuples[2] = normalized.y() * s;
        q_tuples[3] = normalized.z() * s;
    }

    // GETTERS & SETTERS

    template <typename real>
    real Quaternion<real>::w() { return q_tuples[0]; }
    template <typename real>
    void Quaternion<real>::w(real w) { q_tuples[0] = w; }

    template <typename real>
    real Quaternion<real>::x() { return q_tuples[1]; };
    template <typename real>
    void Quaternion<real>::x(real x) { q_tuples[1] = x; }

    template <typename real>
    real Quaternion<real>::y() { return q_tuples[2]; }
    template <typename real>
    void Quaternion<real>::y(real y) { q_tuples[2] = y; }

    template <typename real>
    real Quaternion<real>::z() { return q_tuples[3]; }
    template <typename real>
    void Quaternion<real>::z(real z) { q_tuples[3] = z; }

    template <typename real>
    real Quaternion<real>::Element(int index)
    {
        return q_tuples[index];
    }

    template <typename real>
    Quaternion<real> Quaternion<real>::ToQuaternion()
    {
        Quaternion<real> quat(q_tuples[0], q_tuples[1], q_tuples[2], q_tuples[3]);
        return quat;
    }

    template <typename real>
    Vector3<real> Quaternion<real>::ToVector()
    {
        Vector3<real> vector(q_tuples[1], q_tuples[2], q_tuples[3]);
        return vector;
    }

    template <typename real>
    bool Quaternion<real>::NormDeviation(real testUnitLength)
    {
        // The unit length should be 1.0 (+/-) float-epsilon
        // Ensure positive value by taking absolute value...
        // WAS: real testEpsilon = abs(testUnitLength - (real)1.0);
        // BUGFIX
        real testEpsilon = abs(testUnitLength) - (real)1.0;
        // Return true if norm deviates
        if (testEpsilon > (real)__FLT_EPSILON__)
            return true;
        // otherwise return false
        return false;
    }

    template <typename real>
    real Quaternion<real>::NormSquared()
    {
        // Positive Value
        real SqMag = q_tuples[0] * q_tuples[0];
        SqMag += q_tuples[1] * q_tuples[1];
        SqMag += q_tuples[2] * q_tuples[2];
        SqMag += q_tuples[3] * q_tuples[3];
        return SqMag;
    }

    template <typename real>
    real Quaternion<real>::Norm()
    {
        // Positive Value
        return (real)sqrt((double)NormSquared());
    }

    template <typename real>
    Quaternion<real> Quaternion<real>::Scale(real scalar)
    {
        real wS = q_tuples[0] * scalar;
        real xS = q_tuples[1] * scalar;
        real yS = q_tuples[2] * scalar;
        real zS = q_tuples[3] * scalar;
        Quaternion<real> quat(wS, xS, yS, zS);
        // scaled quaternion may not be a unit-quaternion...
        return quat;
    }

    template <typename real>
    Quaternion<real> Quaternion<real>::UnitQuaternion()
    {
        // Assume norm is approx 1.0
        // This not change the sign-values
        // of the original quaternion...
        return Scale((real)1.0 / Norm());
    }

    template <typename real>
    Quaternion<real> Quaternion<real>::Conjugate()
    {
        real x = q_tuples[1] * (real)-1;
        real y = q_tuples[2] * (real)-1;
        real z = q_tuples[3] * (real)-1;
        Quaternion<real> quat(q_tuples[0], x, y, z);
        return quat;
    }

    template <typename real>
    Quaternion<real> Quaternion<real>::Inverse()
    {
        return Conjugate().Scale((real)1.0 / NormSquared());
    }

    template <typename real>
    real Quaternion<real>::GetRadianAngle()
    {
        // y = acos(x) if cos(y) = x, where (−1 ≤ x ≤ 1) & (0 ≤ y ≤ π)
        real radianAngle = (real)(2.0 * acos(q_tuples[0]));

        return radianAngle;
    }

    template <typename real>
    real Quaternion<real>::GetEulerAngle()
    {
        real angle = GetRadianAngle() * (real)RAD_TO_DEG;

        return angle;
    }

    template <typename real>
    Vector3<real> Quaternion<real>::GetAxis()
    {
        Vector3<real> vector; // Zero Vector
        if (abs(q_tuples[0]) < (real)1)
        {
            real den = sqrt((real)1 - (q_tuples[0] * q_tuples[0]));
            vector.x() = q_tuples[1] / den;
            vector.y() = q_tuples[2] / den;
            vector.z() = q_tuples[3] / den;
        }
        return vector.Normalize();
    }

    /*
    // Although different, the result is the same...
    template <typename real>
    Quaternion<real> Quaternion<real>::Multiply(Quaternion<real> c)
    {
        // Quaternion Multiplication (qc) - Unit Quaternions
        Quaternion<real> q = ToQuaternion();
        real w = q.w() * c.w() - q.x() * c.x() - q.y() * c.y() - q.z() * c.z();
        real x = q.w() * c.x() + q.x() * c.w() + q.y() * c.z() - q.z() * c.y();
        real y = q.w() * c.y() - q.x() * c.z() + q.y() * c.w() + q.z() * c.x();
        real z = q.w() * c.z() + q.x() * c.y() - q.y() * c.x() + q.z() * c.w();
        // Quaternion
        Quaternion<real> quat(w, x, y, z);
        // Is there a norm-squared  deviation
        if (NormDeviation(quat.NormSquared()))
        {
            // Unit Quaternion
            // Must normalize quaterion afterwards otherwise the components
            // 'might' converge to zero due to the floating point rounding
            // errors that diviates a unit-quaternion from its norm.
            Quaternion<real> uQuat = quat.UnitQuaternion();
            return uQuat;
        }
        //
        return quat;
    }
    */

    // Although different, the result is the same...
    template <typename real>
    Quaternion<real> Quaternion<real>::Multiply(Quaternion<real> c)
    {
        // Quaternion Multiplication (qc) - Unit Quaternions
        Quaternion<real> q = ToQuaternion();
        real w = q.w() * c.w() - q.x() * c.x() - q.y() * c.y() - q.z() * c.z();
        real x = q.x() * c.w() + q.w() * c.x() - q.z() * c.y() + q.y() * c.z();
        real y = q.y() * c.w() + q.z() * c.x() + q.w() * c.y() - q.x() * c.z();
        real z = q.z() * c.w() - q.y() * c.x() + q.x() * c.y() + q.w() * c.z();
        // Quaternion
        Quaternion<real> quat(w, x, y, z);
        // Is there a norm-squared  deviation
        if (NormDeviation(quat.NormSquared()))
        {
            // Unit Quaternion
            // Must normalize quaterion afterwards otherwise the components
            // 'might' converge to zero due to the floating point rounding
            // errors that diviates a unit-quaternion from its norm.
            Quaternion<real> uQuat = quat.UnitQuaternion();
            return uQuat;
        }
        //
        return quat;
    }

    // OPERATORS

    template <typename real>
    Quaternion<real> Quaternion<real>::operator*(Quaternion<real> c)
    {
        // Quaternion Multiplication - Unit Quaternions
        Quaternion<real> q = ToQuaternion();
        Vector3<real> qV = q.ToVector();
        Vector3<real> cV = c.ToVector();
        // Quaternion Product
        real wS = q.w() * c.w(); // Scalar Multiplication
        wS -= qV * cV;           // Vector Dot Product
        // Vector-Scalar Products & Vector-Cross Product (^)
        // includes vector additions...
        Vector3<real> v = (qV * c.w()) + (cV * q.w()) + (qV ^ cV);
        // Quaternion
        Quaternion<real> quat(wS, v.x(), v.y(), v.z());
        // Is there a norm-squared  deviation
        if (NormDeviation(quat.NormSquared()))
        {
            // Unit Quaternion
            // Must normalize quaterion afterwards otherwise the components
            // 'might' converge to zero due to the floating point rounding
            // errors that diviates a unit-quaternion from its norm.
            Quaternion<real> uQuat = quat.UnitQuaternion();
            return uQuat;
        }
        //
        return quat;
    }
}

#endif
