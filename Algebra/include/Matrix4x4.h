//
// Carpenter Software
// File: Class Matrix4x4.h
// Github: MageMCU
// Repository: Numerics
// Folder: include
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

#ifndef Numerics_Matrix4x4_h
#define Numerics_Matrix4x4_h

#include "Arduino.h"
#include "Matrix3x3.h"

namespace csjc
{
    template <typename real>
    class Matrix4x4 : Matrix3x3<real>
    {
    private:
        // Properties
        // SIZE: 4x4 = 16
        real m_tuples[16];

        // Private Methods
        void m_identity();
        bool m_limits(int index);

    public:
        Matrix4x4();
        Matrix4x4(const real tuples[]);
        Matrix4x4(real minRandom, real maxRandom);
        Matrix4x4(Matrix2x2<real> m2);
        Matrix4x4(Matrix3x3<real> m3);
        ~Matrix4x4() = default;

        // GETTERS
        real GetElement(int index);
        real GetElement(real row, real col);
        int GetIndex(real row, real col);

        // Setter
        void SetElement(int index, real value);

        // Methods
        Matrix4x4<real> Translation(Vector3<real> v);
        Matrix4x4<real> Rotation(Vector3<real> axis, real angleRadian);

        // Operators
    };

    template <typename real>
    Matrix4x4<real>::Matrix4x4()
    {
        m_identity();
    }

    template <typename real>
    Matrix4x4<real>::Matrix4x4(const real tuples[])
    {
        for (int i = 0; i < 16; i++)
        {
            m_tuples[i] = tuples[i];
        }
    }

    template <typename real>
    Matrix4x4<real>::Matrix4x4(real minRandNum, real maxRandNum)
    {
        RandomNumber<real> rdm(minRandNum, maxRandNum);
        for (int i = 0; i < 16; i++)
        {
            m_tuples[i] = rdm.Random();
        }
    }
    template <typename real>
    Matrix4x4<real>::Matrix4x4(Matrix2x2<real> m2)
    {
        Matrix4x4<real> M;
        //  0  1  2  3
        //  4  5  6  7
        //  8  9 10 11
        // 12 13 14 15
        M.SetElement(0, m2.GetElement(0));
        M.SetElement(1, m2.GetElement(1));
        M.SetElement(4, m2.GetElement(2));
        M.SetElement(5, m2.GetElement(3));
    }

    template <typename real>
    Matrix4x4<real>::Matrix4x4(Matrix3x3<real> m3)
    {
        Matrix4x4<real> M;
        //  0  1  2  3
        //  4  5  6  7
        //  8  9 10 11
        // 12 13 14 15
        M.SetElement(0, m3.GetElement(0));
        M.SetElement(1, m3.GetElement(1));
        M.SetElement(2, m3.GetElement(2));
        M.SetElement(4, m3.GetElement(3));
        M.SetElement(5, m3.GetElement(4));
        M.SetElement(6, m3.GetElement(5));
        M.SetElement(8, m3.GetElement(6));
        M.SetElement(9, m3.GetElement(7));
        M.SetElement(10, m3.GetElement(8));
    }

    template <typename real>
    real Matrix4x4<real>::GetElement(int index)
    {
        if (m_limits(index))
        {
            return m_tuples[index];
        }
        return NAN;
    }

    template <typename real>
    real Matrix4x4<real>::GetElement(real row, real col)
    {
        int index = GetIndex(row, col);
        if (m_limits(index))
        {
            return m_tuples[index];
        }
        return NAN;
    }

    template <typename real>
    int Matrix4x4<real>::GetIndex(real row, real col)
    {
        return (row * 4) + col;
    }

    template <typename real>
    void Matrix4x4<real>::SetElement(int index, real value)
    {
        if (m_limits(index))
        {
            m_tuples[index] = value;
        }
    }

    // Methods

    template <typename real>
    Matrix4x4<real> Translation(Vector3<real> v)
    {
        // Identity
        Matrix4x4<real> T;
        //  0  1  2  3
        //  4  5  6  7
        //  8  9 10 11
        // 12 13 14 15
        T.SetElement(3, v.x());
        T.SetElement(7, v.y());
        T.SetElement(11, v.z());
        return T;
    }

    template <typename real>
    Matrix4x4<real> Rotation(Vector3<real> axis, real angleRadian)
    {
        real tuples[16];
        //  0  1  2  3
        //  4  5  6  7
        //  8  9 10 11
        // 12 13 14 15

        // quaternion components
        Quaternion<real> q(axis, angleRadian);
        real w = q.w();
        real x = q.x();
        real y = q.y();
        real z = q.z();

        // Row1
        real ww = w * w;
        real xx = x * x;
        real yy = y * y;
        real zz = z * z;
        tuples[0] = ww + xx - yy - zz;
        real xy = 2 * x * y;
        real wz = 2 * w * z;
        tuples[1] = xy - wz;
        real xz = 2 * x * z;
        real wy = 2 * w * y;
        tuples[2] = xz + wy;
        tuples[3] = (real)0;
        // Row2
        tuples[4] = xy + wz;
        tuples[5] = ww - xx + yy - zz;
        real yz = 2 * y * z;
        real wx = 2 * w * x;
        tuples[6] = yz - wx;
        tuples[7] = (real)0;
        // Row3
        tuples[8] = xz - wy;
        tuples[9] = yz + wx;
        tuples[10] = ww - xx - yy + zz;
        tuples[11] = (real)0;
        // Row4
        tuples[12] = (real)0;
        tuples[13] = (real)0;
        tuples[14] = (real)0;
        tuples[15] = (real)1;

        // Matrix
        Matrix4x4<real> m4(tuples);
        return m4;
    }

    // Private Methods

    template <typename real>
    void Matrix4x4<real>::m_identity()
    {
        int idx = 0;
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
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
    bool Matrix4x4<real>::m_limits(int index)
    {
        if (index >= 0 && index < 16)
            return true;
        return false;
    }
}
#endif