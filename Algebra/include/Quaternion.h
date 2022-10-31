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
// Updated 20221030
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
    class Quaternion : Matrix<real>
    {
    private:
        // PRIVATE MEMBERS
        int m_size;
        real q_tuples[4]; // w, x, y, z

    public:
        // CONSTRUCTORS
        Quaternion();
        Quaternion(real w, real x, real y, real z);
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
        Quaternion<real> GetQuaternion();
        Vector3<real> GetVector();
        real GetAngle();
        Vector3<real> GetAxis();
        Quaternion<real> GetConjugate();

        // PUBLIC Methods

        // Matrix<real> Rotate(Vector<real> position, Vector<real> axis, real angleRadian);

        // OPERATORS
        Quaternion<real> operator*(const Quaternion<real> &q);
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
    Quaternion<real> Quaternion<real>::GetQuaternion()
    {
        Quaternion<real> quat(q_tuples[0], q_tuples[1], q_tuples[2], q_tuples[3]);
    }

    template <typename real>
    Vector3<real> Quaternion<real>::GetVector()
    {
        Vector3<real> vector(q_tuples[1], q_tuples[2], q_tuples[3]);
        return vector;
    }

    template <typename real>
    real Quaternion<real>::GetAngle()
    {
        real magnitude = GetVector().Magnitude();
        real angle = 2 * (real)atan2(magnitude, q_tuples[0]);
        return angle;
    }

    template <typename real>
    Vector3<real> Quaternion<real>::GetAxis()
    {
        Vector3<real> normalized = GetVector().Normalize();
        return normalized;
    }

    template <typename real>
    Quaternion<real> Quaternion<real>::GetConjugate()
    {
        real x = q_tuples[1] * (real)-1;
        real y = q_tuples[2] * (real)-1;
        real z = q_tuples[3] * (real)-1;
        Quaternion<real> quat(q_tuples[0], x, y, z);
        return quat;
    }

    // PUBLIC Methods

    /* ----------------------------------------------------------------- NOT USED - messy
    template <typename real>
    Vector<real> Quaternion<real>::Rotate(Vector<real> position, Vector<real> axis, real angleRadian)
    {
        Vector<real> aNorm = axis.Normalize();

        real s = (real)sin((double)angleRadian / (double)2);
        real w = (real)cos((double)angleRadian / (double)2);

        real qx = aNorm.x() * s;
        real qy = aNorm.y() * s;
        real qz = aNorm.z() * s;
        real qw = w;

        // ref [Mf3DG&CG] 2nd Ed. by Lengyel, 2004. p92.
        // 1 -2yy - 2zz,  2xy- 2wz,      2xz + 2wy
        // 2xy + 2wz,     1 -2xx - 2zz,  2yz- 2wx
        // 2xz - 2wy,     2yz + 2wx,     1 - 2xx - 2yy
        real array = {
            1 - 2 * qy * qy - 2 * qz * qz, 2 * qx * qy - 2 * qw * qz, 2 * qx * qz + 2 * qw * qy, 0,
            2 * qx * qy + 2 * qw * qz, 1 - 2 * qx * qx - 2 * qz * qz, 2 * qy * qz - 2 * qw * qx, 0,
            2 * qx * qz - 2 * qw * qy, 2 * qy * qz + 2 * qw * qx, 1 - 2 * qx * qx - 2 * qy * qy, 0,
            0, 0, 0, 1};

        Matrix<real> Q(array, 4); // --------------------------------- No such beast - FIXME
        // WAS:Matrix<real> M = Q * position;
        Vector<real> v = Q * position; // Not Necessay for LOCAL coordinates

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Serial.print(Q.Element(i, j));
                Serial.print(" ");
            }
            Serial.println("");
        }
    }
    */

    // OPERATORS

    template <typename real>
    Quaternion<real> Quaternion<real>::operator*(const Quaternion<real> &q)
    {
        Quaternion<real> p(q_tuples[0], q_tuples[1], q_tuples[2], q_tuples[3]);
        real wP = p.w();
        real wQ = q.w();
        Vector3<real> vP = p.GetVector();
        Vector3<real> vQ = q.GetVector();
        // Quaternion Product
        real w = wP * wQ; // Simple Multiplication
        w -= vP * vQ;     // Dot Product
        // VectorScalar + VectorScalar + VectorVecotCross Multiplications
        Vector3<real> v = (vQ * wP) + (vP * wQ) + (vP ^ vQ);
        // Quaternion
        Quaternion<real> quat(w, v.x(), v.y(), v.z());
        return quat;
    }
}

#endif