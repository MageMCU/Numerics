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
        real m_tuples[4];
        int m_commonNum;

        // nmr::Matrix<real> m_2x2;
        Matrix<real> m_getMatrix();
        void m_identity();
        // Temp Place - will move to Matrix.h
        // Vector2<real> m_Ax(real A[], real x[], int NumRows, int NumCommon, int NumCols);
        // Matrix2x2<real> m_AB(real A[], real B[], int NumRows, int NumCommon, int NumCols);
        // void m_AB(real A[], real B[], real C[], int NumRows, int NumCommon, int NumCols);

    public:
        Matrix2x2();
        Matrix2x2(real e00, real e01, real e10, real e11);
        Matrix2x2(const real tuples[]);
        ~Matrix2x2() = default;

        // GETTERS
        real E00();
        real E01();
        real E10();
        real E11();
        real GetElement(int index);
        real GetElement(real row, real col);
        int GetIndex(real row, real col);

        // Setter
        void SetElement(int index, real value);

        // METHODS
        bool Invertible();
        real Determinant();
        Matrix2x2<real> Transpose();
        Matrix2x2<real> Adjoint();
        Matrix2x2<real> Inverse();
        Vector2<real> Solve(Vector2<real> b);
        Matrix2x2<real> Rotation(real angleRadian);

        // OPERATORS - pending - FIXME
        Matrix2x2<real> operator-();
        Matrix2x2<real> operator*(real s);
        Vector2<real> operator*(Vector2<real> v);
        Matrix2x2<real> operator*(Matrix2x2<real> M);
    };

    template <typename real>
    Matrix2x2<real>::Matrix2x2()
    {
        // Identity
        m_identity();
        m_commonNum = 2;
    }

    template <typename real>
    Matrix2x2<real>::Matrix2x2(real e11, real e12, real e21, real e22)
    {
        // tuples size 4
        m_tuples[0] = e11;
        m_tuples[1] = e12;
        m_tuples[2] = e21;
        m_tuples[3] = e22;
        m_commonNum = 2;
    }

    template <typename real>
    Matrix2x2<real>::Matrix2x2(const real tuples[])
    {
        // tuples size 4
        m_tuples[0] = tuples[0];
        m_tuples[1] = tuples[1];
        m_tuples[2] = tuples[2];
        m_tuples[3] = tuples[3];
        m_commonNum = 2;
    }

    template <typename real>
    real Matrix2x2<real>::E00()
    {
        return m_tuples[0];
    }

    template <typename real>
    real Matrix2x2<real>::E01()
    {
        return m_tuples[1];
    }

    template <typename real>
    real Matrix2x2<real>::E10()
    {
        return m_tuples[2];
    }

    template <typename real>
    real Matrix2x2<real>::E11()
    {
        return m_tuples[3];
    }

    template <typename real>
    real Matrix2x2<real>::GetElement(int index)
    {
        if (index >= 0 && index < 4)
        {
            return m_tuples[index];
        }
        return NAN;
    }

    template <typename real>
    real Matrix2x2<real>::GetElement(real row, real col)
    {
        int index = GetIndex(row, col);
        if (index >= 0 && index < 4)
        {
            return m_tuples[index];
        }
        return NAN;
    }

    template <typename real>
    int Matrix2x2<real>::GetIndex(real row, real col)
    {
        int index = row * 2 + col;
        return index;
    }

    template <typename real>
    void Matrix2x2<real>::SetElement(int index, real value)
    {
        if (index >= 0 && index < 4)
        {
            m_tuples[index] = value;
        }
    }

    // METHODS

    template <typename real>
    bool Matrix2x2<real>::Invertible()
    {
        // Homogeneous - trival solution - D=0
        // Nonhomegeneous = has one solution - D!=0
        real det = Determinant();
        if (abs(det) > (real)__FLT_EPSILON__)
            return true;
        return false;
    }

    template <typename real>
    real Matrix2x2<real>::Determinant()
    {
        return (E00() * E11()) - (E01() * E10());
    }

    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::Transpose()
    {
        Matrix2x2<real> matrix2x2(E00(), E10(), E01(), E11());
        return matrix2x2;
    }

    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::Adjoint()
    {
        real r00 = E11();
        real r01 = -E01();
        real r10 = -E10();
        real r11 = E00();
        Matrix2x2<real> a(r00, r01, r10, r11);
        return a;
    }

    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::Inverse()
    {
        if (Invertible())
        {
            real n = (real)1 / Determinant();
            Matrix2x2<real> M = Adjoint();
            Matrix2x2<real> inv = M * n;
            return inv;
        }
        Matrix2x2<real> v;
        return v;
    }

    template <typename real>
    Vector2<real> Matrix2x2<real>::Solve(Vector2<real> y)
    {
        Matrix2x2<real> inverse = Inverse();
        Vector2<real> x = inverse * y;
        return x;
    }

    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::Rotation(real angleRadian)
    {
        real cs = (real) cos(angleRadian);
        real sn = (real) sin(angleRadian);
        real r00 = cs;
        real r01 = -sn;
        real r10 = sn;
        real r11 = cs;
        Matrix2x2<real> rotation(r00, r01, r10, r11);
        return rotation;
    }

    // OPERATORS
    
    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::operator-()
    {
        real r00 = E00() * (real)-1;
        real r01 = E01() * (real)-1;
        real r10 = E10() * (real)-1;
        real r11 = E11() * (real)-1;
        Matrix2x2<real> matrix2x2(r00, r01, r10, r11);
        return matrix2x2;
    }

    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::operator*(real s)
    {
        real r00 = E00() * s;
        real r01 = E01() * s;
        real r10 = E10() * s;
        real r11 = E11() * s;
        Matrix2x2<real> matrix2x2(r00, r01, r10, r11);
        return matrix2x2;
    }
    
    template <typename real>
    Vector2<real> Matrix2x2<real>::operator*(Vector2<real> v)
    {
        // |a0  a1|  |b0| - |a0b0 + a1b1|
        // |a2  a3|  |b1| - |a2b0 + a3b1|
        real x = (m_tuples[0] * v.Element(0)) + (m_tuples[1] * v.Element(1));
        real y = (m_tuples[2] * v.Element(0)) + (m_tuples[3] * v.Element(1));
        Vector2<real> vector(x, y);
        return vector;
    }

    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::operator*(Matrix2x2<real> M)
    {
        // |a0  a1|  |b0  b1| - |a0b0 + a1b2, a0b1 + a1b3|
        // |a2  a3|  |b2  b3| - |a2b0 + a3b2, a2b1 + a3b3|
        real w = (m_tuples[0] * M.GetElement(0)) + (m_tuples[1] * M.GetElement(2));
        real x = (m_tuples[0] * M.GetElement(1)) + (m_tuples[1] * M.GetElement(3));
        real y = (m_tuples[2] * M.GetElement(0)) + (m_tuples[3] * M.GetElement(2));
        real z = (m_tuples[2] * M.GetElement(1)) + (m_tuples[3] * M.GetElement(3));
        Matrix2x2<real> matrix(w, x, y, z);
        return matrix;
    }

    // PRIVATE
    /* Experimental
    template <typename real>
    Vector2<real> Matrix2x2<real>::m_Ax(real A[], real x[], int NumRows, int NumCommon, int NumCols)
    {
        // Test the following conditions
        // (1) A(2x2)(rows)=2 * B(2x2)(cols)=2 where A(cols) & B(rows) = 2... DO NOT USE HERE
        // (2) A(2x2)(rows)=2 * v(2x1)(col)=1 where A(cols) & B(rows) = 2
        // Minimum Size (2, 2, 1)

        int arraySize = NumRows * NumCols;
        real vector[arraySize];
        int rIndex;
        int aIndex;
        int bIndex;

        for (int r = 0; r < NumRows; ++r)
        {
            for (int c = 0; c < NumCols; ++c)
            {
                rIndex = r * NumCommon + c;
                // Convert from col-vector to row-vector
                // We want the indices in numerical order...
                if (NumCols == 1)
                    rIndex = c * NumCommon + r;
                vector[rIndex] = (real)0;
                for (int i = 0; i < NumCommon; ++i)
                {
                    aIndex = r * NumCommon + i;
                    bIndex = i * NumCommon + c;
                    // Convert from col-vector to row-vector
                    // We want the indices in numerical order...
                    if (NumCols == 1)
                        bIndex = c * NumCommon + i;
                    vector[rIndex] += A[aIndex] * x[bIndex];
                }
            }
        }
        Vector2<real> b(vector);
        return b;
    }
    */

   /* Experimental
    template <typename real>
    Matrix2x2<real> Matrix2x2<real>::m_AB(real A[],
                                          real B[],
                                          int NumRows,
                                          int NumCommon,
                                          int NumCols)
    {
        // Test the following conditions
        // (1) A(2x2)(rows)=2 * B(2x2)(cols)=2 where A(cols) & B(rows) = 2
        // (2) A(2x2)(rows)=2 * v(2x1)(col)=1 where A(cols) & B(rows) = 2 ... DO NOT USE HERE
        // Minimum Size (2, 2, 2)

        int arraySize = NumRows * NumCols;
        real matrix[arraySize];
        int rIndex;
        int aIndex;
        int bIndex;

        for (int r = 0; r < NumRows; ++r)
        {
            for (int c = 0; c < NumCols; ++c)
            {
                rIndex = r * NumCommon + c;
                // Convert from col-vector to row-vector
                // We want the indices in numerical order...
                if (NumCols == 1)
                    rIndex = c * NumCommon + r;
                matrix[rIndex] = (real)0;
                for (int i = 0; i < NumCommon; ++i)
                {
                    aIndex = r * NumCommon + i;
                    bIndex = i * NumCommon + c;
                    // Convert from col-vector to row-vector
                    // We want the indices in numerical order...
                    if (NumCols == 1)
                        bIndex = c * NumCommon + i;
                    matrix[rIndex] += A[aIndex] * B[bIndex];
                }
            }
        }
        Matrix2x2<real> R(matrix);
        return R;

        // idea taken from GTE
        // Test the following conditions
        // (1) A(2x2)(rows)=2 * B(2x2)(cols)=2 where A(cols) & B(rows) = 2
        // (2) A(2x2)(rows)=2 * v(2x1)(col)=1 where A(cols) & B(rows) = 2
        // int NumRows = 2;
        // int NumCols = 2; // or 1 as indicated above...
        // int NumCommon = 2;
        // int rIndex;
        // int aIndex;
        // int bIndex;

        // for (int r = 0; r < NumRows; ++r)
        // {
        //     for (int c = 0; c < NumCols; ++c)
        //     {
        //         rIndex = r * NumCommon + c;
        //         // Convert from col-vector to row-vector
        //         // We want the indices in numerical order...
        //         if (NumCols == 1)
        //             rIndex = c * NumCommon + r;
        //         for (int i = 0; i < NumCommon; ++i)
        //         {
        //             aIndex = r * NumCommon + i;
        //             bIndex = i * NumCommon + c;
        //         // Convert from col-vector to row-vector
        //         // We want the indices in numerical order...
        //             if (NumCols == 1)
        //                 bIndex = c * NumCommon + i;
        //             // result(r, c) += A(r, i) * B(i, c); DO NOT USE

        //             // Debug
        //             cout << " R:(" << r << ", " << c << ")="
        //             << rIndex << " A:(" << r << ", " << i
        //             << ")=" << aIndex << " B:(" << i << ", "
        //             << c << ")=" << bIndex << endl;
        //         }
        //     }
        // }
    }
    */

    /* Experimental
    template <typename real>
    void Matrix2x2<real>::m_AB(real A[],
                               real B[],
                               real C[],
                               int NumRows,
                               int NumCommon,
                               int NumCols)
    {
        // Test the following conditions
        // (1) A(2x2)(rows)=2 * B(2x2)(cols)=2 where A(cols) & B(rows) = 2
        // (2) A(2x2)(rows)=2 * v(2x1)(col)=1 where A(cols) & B(rows) = 2 ... DO NOT USE HERE
        // Minimum Size (2, 2, 2)

        int rIndex;
        int aIndex;
        int bIndex;

        for (int r = 0; r < NumRows; ++r)
        {
            for (int c = 0; c < NumCols; ++c)
            {
                rIndex = r * NumCommon + c;
                // Convert from col-vector to row-vector
                // We want the indices in numerical order...
                if (NumCols == 1)
                    rIndex = c * NumCommon + r;
                C[rIndex] = (real)0;
                for (int i = 0; i < NumCommon; ++i)
                {
                    aIndex = r * NumCommon + i;
                    bIndex = i * NumCommon + c;
                    // Convert from col-vector to row-vector
                    // We want the indices in numerical order...
                    if (NumCols == 1)
                        bIndex = c * NumCommon + i;
                    C[rIndex] += A[aIndex] * B[bIndex];
                }
            }
        }
    }
    */

    template <typename real>
    Matrix<real> Matrix2x2<real>::m_getMatrix()
    {
        real e11 = m_tuples[0];
        real e12 = m_tuples[1];
        real e21 = m_tuples[2];
        real e22 = m_tuples[3];
        Matrix2x2<real> M(e11, e12, e21, e22);
        return M;
    }

    template <typename real>
    void Matrix2x2<real>::m_identity()
    {
        // tuples size 4
        m_tuples[0] = (real)1;
        m_tuples[1] = (real)0;
        m_tuples[2] = (real)0;
        m_tuples[3] = (real)1;
    }

}

#endif
