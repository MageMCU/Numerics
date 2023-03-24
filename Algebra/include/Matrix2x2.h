//
// Carpenter Software
// File: Class Matrix2x2.h
// Folder: Algebra
//
// Purpose: Github Depository (MageMCU)
//
// Algebra OOP Library
// The math is underneath the namespace
// nmr for Numerics as in numeric computation.
//
// By Jesse Carpenter (carpentersoftware.com)
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Numerics_Matrix2x2_h
#define Numerics_Matrix2x2_h

#include "Arduino.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Point2.h"
#include "Point3.h"
#include "Matrix.h"

namespace nmr
{
    template <typename real>
    class Matrix2x2 : Matrix<real>
    {
    private:
        nmr::Matrix<real> m_2x2;

    public:
        Matrix2x2();
        Matrix2x2(real e00, real e01, real e10, real e11);
        ~Matrix2x2() = default;

        // GETTERS
        real E11();
        real E12();
        real E21();
        real E22();

        // METHODS
        bool IsInvertible();
        real Determinant();
        Matrix2x2<real> Transpose();
        Matrix2x2<real> Inverse();
        Vector2<real> Solve(Vector2<real> b);

        // OPERATORS - pending - FIXME
        Matrix2x2<real> operator-();
        Matrix2x2<real> operator*(real s);
        Vector2<real> operator*(Vector2<real> v);
        Matrix2x2<real> operator*(Matrix2x2<real> M);
    };

    template <typename real>
    Matrix2x2<real>::Matrix2x2()
    {
        m_2x2 = nmr::Matrix<real>();
    }

    template <typename real>
    Matrix2x2<real>::Matrix2x2(real e11, real e12, real e21, real e22)
    {
        real array[4];
        array[0] = e11;
        array[1] = e12;
        array[2] = e21;
        array[3] = e22;
        m_2x2 = nmr::Matrix<real>(array, a2x2);
    }

    template <typename real>
    real Matrix2x2<real>::E11()
    {
        return m_2x2.Element(0, 0);
    }

    template <typename real>
    real Matrix2x2<real>::E12()
    {
        return m_2x2.Element(0, 1);
    }

    template <typename real>
    real Matrix2x2<real>::E21()
    {
        return m_2x2.Element(1, 0);
    }

    template <typename real>
    real Matrix2x2<real>::E22()
    {
        return m_2x2.Element(1, 1);
    }

    // METHODS

    template <typename real>
    bool Matrix2x2<real>::IsInvertible()
    {
        // Homogeneous - trival solution - D=0
        // Nonhomegeneous = has one solution - D!=0
        return Determinant() != (real)0;
    }

    template <typename real>
    real Matrix2x2<real>::Determinant()
    {
        return E11() * E22() - E21() * E12();
    }

    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::Transpose()
    {
        real r11 = E11();
        real r12 = E21();
        real r21 = E12();
        real r22 = E22();
        Matrix2x2<real> transpose(r11, r12, r21, r22);
        return transpose;
    }

    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::Inverse()
    {
        if (IsInvertible())
        {
            real d = Determinant();
            real r11 = E22() / d;
            real r12 = -E12() / d;
            real r21 = -E21() / d;
            real r22 = E11() / d;
            Matrix2x2<real> inverse(r11, r12, r21, r22);
            return inverse;
        }
        Matrix2x2<real> identity;
        return identity;
    }

    template <typename real>
    Vector2<real> Matrix2x2<real>::Solve(Vector2<real> y)
    {
        Matrix2x2<real> inverse = Inverse();
        real tuples[4];
        tuples[0] = inverse.E11();
        tuples[1] = inverse.E12();
        tuples[2] = inverse.E21();
        tuples[3] = inverse.E22();
        // Use base???
        Matrix<real> matrix(tuples, a2x2);
        Vector2<real> x = matrix * y;
        return x;
    }

    // OPERATORS
}

#endif