//
// Carpenter Software
// File: Class Matrix3x3.h
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

#ifndef Numerics_Matrix3x3_h
#define Numerics_Matrix3x3_h

#include "Arduino.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Point2.h"
#include "Point3.h"
#include "Matrix.h"

namespace nmr
{
    template <typename real>
    class Matrix3x3 : Matrix<real>
    {
    private:
        // SIZE: 3x3 = 9
        real m_tuples[9];
        // The matrix sizes use literals...

        // Private Methods
        void m_identity();
        real m_det(real aa, real ab, real ba, real bb);
        bool m_limits(int index);
        void m_swapElement(int idx1, int idx2);
        void m_swapRows(int row1, int row2);
        real m_abs(real value);
        Matrix3x3<real> m_col(Vector3<real> v, int colNum);

    public:
        Matrix3x3();
        Matrix3x3(const real tuples[]);
        // Matrix3x3(Vector3<real> col_1, Vector3<real> col_2, Vector3<real> col_3);
        Matrix3x3(real minRandom, real maxRandom);
        ~Matrix3x3() = default;

        // GETTERS
        real GetElement(int index);
        real GetElement(real row, real col);
        int GetIndex(real row, real col);

        // Setter
        void SetElement(int index, real value);

        // Methods
        real Determinant();
        bool Invertible();
        Matrix3x3<real> Transpose();
        Matrix3x3<real> Adjoint();
        Matrix3x3<real> Inverse();
        Vector3<real> Cramer(Vector3<real> b);
        Vector3<real> Solve(Vector3<real> b);
        Matrix3x3<real> Rotation(real xAngleRadian, real yAngleRadian, real zAngleRadian);

        // OPERATORS
        Matrix3x3<real> operator-();
        Matrix3x3<real> operator*(real s);
        Vector3<real> operator*(Vector3<real> v);
        Matrix3x3<real> operator*(Matrix3x3<real> M);
    };

    template <typename real>
    Matrix3x3<real>::Matrix3x3()
    {
        m_identity();
    }

    template <typename real>
    Matrix3x3<real>::Matrix3x3(const real tuples[])
    {
        for (int i = 0; i < 9; i++)
        {
            m_tuples[i] = tuples[i];
        }
    }

    template <typename real>
    Matrix3x3<real>::Matrix3x3(real minRandNum, real maxRandNum)
    {
        nmr::RandomNumber<real> rdm(minRandNum, maxRandNum);
        for (int i = 0; i < 9; i++)
        {
            m_tuples[i] = rdm.Random();
        }
    }

    template <typename real>
    real Matrix3x3<real>::GetElement(int index)
    {
        if (m_limits(index))
        {
            return m_tuples[index];
        }
        return NAN;
    }

    template <typename real>
    real Matrix3x3<real>::GetElement(real row, real col)
    {
        int index = GetIndex(row, col);
        if (m_limits(index))
        {
            return m_tuples[index];
        }
        return NAN;
    }

    template <typename real>
    int Matrix3x3<real>::GetIndex(real row, real col)
    {
        return (row * 3) + col;
    }

    template <typename real>
    void Matrix3x3<real>::SetElement(int index, real value)
    {
        if (m_limits(index))
        {
            m_tuples[index] = value;
        }
    }

    // Methods

    template <typename real>
    real Matrix3x3<real>::Determinant()
    {
        // SOURCE: LAwA 8thed. 87...
        // 0 1 2
        // 3 4 5
        // 6 7 8
        // The Row-Major Order (See Method m_det())
        real i0 = m_det(m_tuples[4], m_tuples[5], m_tuples[7], m_tuples[8]);
        real i1 = m_det(m_tuples[3], m_tuples[5], m_tuples[6], m_tuples[8]);
        real i2 = m_det(m_tuples[3], m_tuples[4], m_tuples[6], m_tuples[7]);
        real det = m_tuples[0] * i0 - m_tuples[1] * i1 + m_tuples[2] * i2;
        return det;
    }

    template <typename real>
    bool Matrix3x3<real>::Invertible()
    {
        // Homogeneous - trival solution - D=0
        // Nonhomegeneous = has one solution - D!=0
        real det = Determinant();
        if (abs(det) > (real)__FLT_EPSILON__)
            return true;
        return false;
    }

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::Transpose()
    {
        real tuples[9];
        int idx1 = 0;
        int idx2 = 0;
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                idx1 = GetIndex(r, c);
                idx2 = GetIndex(c, r);
                tuples[idx1] = m_tuples[idx2];
            }
        }
        // Construct
        Matrix3x3<real> matrix(tuples);
        return matrix;
    }

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::Adjoint()
    {
        // SOURCE: LAwA 8thed. 98...
        // tuples            m-tuples
        // ------            ------
        // 0 1 2             0 3 6
        // 3 4 5  Transpose  1 4 7
        // 6 7 8             2 5 8
        real tuples[9];
        // The Row-Major Order (See Method m_det())
        tuples[0] = m_det(m_tuples[4], m_tuples[7], m_tuples[5], m_tuples[8]);
        tuples[1] = m_det(m_tuples[1], m_tuples[7], m_tuples[2], m_tuples[8]);
        tuples[1] *= (real)-1;
        tuples[2] = m_det(m_tuples[1], m_tuples[4], m_tuples[2], m_tuples[5]);
        tuples[3] = m_det(m_tuples[3], m_tuples[6], m_tuples[5], m_tuples[8]);
        tuples[3] *= (real)-1;
        tuples[4] = m_det(m_tuples[0], m_tuples[6], m_tuples[2], m_tuples[8]);
        tuples[5] = m_det(m_tuples[0], m_tuples[3], m_tuples[2], m_tuples[5]);
        tuples[5] *= (real)-1;
        tuples[6] = m_det(m_tuples[3], m_tuples[6], m_tuples[4], m_tuples[7]);
        tuples[7] = m_det(m_tuples[0], m_tuples[6], m_tuples[1], m_tuples[7]);
        tuples[7] *= (real)-1;
        tuples[8] = m_det(m_tuples[0], m_tuples[3], m_tuples[1], m_tuples[4]);

        // Construct
        Matrix3x3<real> matrix(tuples);
        return matrix;
    }

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::Inverse()
    {
        if (Invertible())
        {
            real n = (real)1 / Determinant();
            Matrix3x3<real> M = Adjoint();
            Matrix3x3<real> inv = M * n;
            return inv;
        }
        Matrix3x3<real> identity;
        return identity;
    }

    template <typename real>
    Vector3<real> Matrix3x3<real>::Cramer(Vector3<real> b)
    {
        real dDet = Determinant();
        // indices start at zero....
        real xDet = m_col(b, 0).Determinant();
        real yDet = m_col(b, 1).Determinant();
        real zDet = m_col(b, 2).Determinant();
        //
        real x = xDet / dDet;
        real y = yDet / dDet;
        real z = zDet / dDet;
        // Construct
        Vector3<real> vertex(x, y, z);
        return vertex;
    }

    template <typename real>
    Vector3<real> Matrix3x3<real>::Solve(Vector3<real> b)
    {
        real tuples[3];
        int idx = 0;
        for (int r = 0; r < 3; r++)
        {
            tuples[r] = (real)0;
            for (int c = 0; c < 3; c++)
            {
                idx = GetIndex(r, c);
                tuples[r] += m_tuples[idx] * b.Element(c);
            }
        }
        // Construct
        Vector3<real> vertex(tuples);
        return vertex;
    }

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::Rotation(real xAngleRadian,
                                              real yAngleRadian,
                                              real zAngleRadian)
    {
        // XYZ Order
        // HAS NOT BEEN TESTED ---------------------------- FIXME
        // INCLUDE BOOLEAN OPTIONS for CW CCW

        // X
        Matrix3x3<real> xM; // Identity
        // 0 1 2     1   0   0
        // 3 4 5  =  0  cs -sn
        // 6 7 8     0  sn  cs
        real cs = (real)cos(xAngleRadian);
        real sn = (real)sin(xAngleRadian);
        xM.SetElement(4, cs);
        xM.SetElement(5, -sn);
        xM.SetElement(7, sn);
        xM.SetElement(8, cs);

        // Y
        Matrix3x3<real> yM; // Identity
        // 0 1 2     cs   0   sn
        // 3 4 5  =   0   1  -sn
        // 6 7 8    -sn   0   cs
        cs = (real)cos(yAngleRadian);
        sn = (real)sin(yAngleRadian);
        yM.SetElement(0, cs);
        yM.SetElement(2, sn);
        yM.SetElement(6, -sn);
        yM.SetElement(8, cs);

        // Z
        Matrix3x3<real> zM; // Identity
        // 0 1 2     cs -sn   0
        // 3 4 5  =  sn  cs   0
        // 6 7 8     0    0   1
        cs = (real)cos(zAngleRadian);
        sn = (real)sin(zAngleRadian);
        zM.SetElement(0, cs);
        zM.SetElement(1, -sn);
        zM.SetElement(3, sn);
        zM.SetElement(4, cs);

        // Multiply all matrices... XYZ order ??? ---- FIXME
        // Review and Test matrices order []
        Matrix3x3<real> R = zM * yM;
        R = R * xM;

        // Note: When comparing this with the quaternion.h class, 
        // one might see that rotation() is more math intensive...

        return R;
    }
    // OPERATORS

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::operator-()
    {
        real tuples[9];
        for (int i = 0; i < 9; i++)
        {
            tuples[i] = m_tuples[i] * (real)-1;
        }
        // Construct
        Matrix3x3<real> matrix(tuples);
        return matrix;
    }

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::operator*(real s)
    {
        real tuples[9];
        for (int i = 0; i < 9; i++)
        {
            tuples[i] = m_tuples[i] * s;
        }
        // Construct
        Matrix3x3<real> matrix(tuples);
        return matrix;
    }

    template <typename real>
    Vector3<real> Matrix3x3<real>::operator*(Vector3<real> v)
    {
        real tuples[3];
        int idx = 0;
        for (int r = 0; r < 3; r++)
        {
            tuples[r] = (real)0;
            for (int c = 0; c < 3; c++)
            {
                idx = GetIndex(r, c);
                tuples[r] += m_tuples[idx] * v.Element(c);
            }
        }
        // Construct
        Vector3<real> vertex(tuples);
        return vertex;
    }

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::operator*(Matrix3x3<real> M)
    {
        real tuples[9];
        int tIdx = 0;
        int mIdx = 0;
        int eIdx = 0;
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                tIdx = GetIndex(r, c);
                tuples[tIdx] = (real)0;
                for (int k = 0; k < 3; k++)
                {
                    mIdx = GetIndex(r, k);
                    eIdx = GetIndex(k, c);
                    tuples[tIdx] += m_tuples[mIdx] * M.GetElement(eIdx);
                }
            }
        }
        // Construct
        Matrix3x3<real> matrix(tuples);
        return matrix;
    }

    // PRIVATE METHODS

    template <typename real>
    void Matrix3x3<real>::m_identity()
    {
        int idx = 0;
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                idx = GetIndex(r, c);
                if (r == c)
                    m_tuples[idx] = (real)1;
                else
                    m_tuples[idx] = (real)0;
            }
        }
    }

    template <typename real>
    real Matrix3x3<real>::m_det(real a11, real a12, real a21, real a22)
    {
        // SOURCE: LAwA 8thed. 85...
        real a = a11 * a22;
        real b = a12 * a21;
        real det = a - b;
        return det;
    }

    template <typename real>
    bool Matrix3x3<real>::m_limits(int index)
    {
        if (index >= 0 && index < 9)
            return true;
        return false;
    }

    template <typename real>
    void Matrix3x3<real>::m_swapElement(int idx1, int idx2)
    {
        real temp = m_tuples[idx1];
        m_tuples[idx1] = m_tuples[idx2];
        m_tuples[idx2] = temp;
    }

    template <typename real>
    void Matrix3x3<real>::m_swapRows(int row1, int row2)
    {
        real temp[3];
        for (int col = 0; col < 3; col++)
        {
            temp[col] = m_tuples[row1, col];
            m_tuples[row1, col] = m_tuples[row2, col];
            m_tuples[row2, col] = temp[col];
        }
    }

    template <typename real>
    real Matrix3x3<real>::m_abs(real value)
    {
        if (value < (real)0)
            return value * (real)-1;
        return value;
    }

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::m_col(Vector3<real> v, int colNum)
    {
        real tuples[9];
        int idx = 0;
        // Clarification: column numbers are from 0 to 2(3)
        if (colNum >= 0 && colNum < 3)
        {
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    idx = GetIndex(r, c);
                    if (c == colNum)
                        tuples[idx] = v.Element(r);
                    else
                        tuples[idx] = m_tuples[idx];
                }
            }
        }
        Matrix3x3<real> m(tuples);
        return m;
    }
}

#endif