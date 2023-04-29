//
// Carpenter Software
// File: Class Matrix.h
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

#ifndef Numerics_Matrix_h
#define Numerics_Matrix_h

#include "Arduino.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Point2.h"
#include "Point3.h"
#include "RandomNumber.h"

namespace nmr
{
    enum MatrixRowSize
    {
        a2x2 = 2,
        a3x3 = 3,
        a4x4 = 4
    };

    template <typename real>
    class Matrix : Point2<real> /* inherits Vector2 */, Point3<real> /* inherits Vector3 */, RandomNumber<real>
    {
    private:
        // Private Members
        int _rowSizeSquareMatrix;
        int _sizeSquareMatrix;
        real m_tuples[16];
        // Private Methods
        int _it(int row, int col);
        // Item: 4 columns
        int _it4(int row, int col);
        // Identity Initialization
        void _identity();
        // Determinate 2x2
        real _det(real a00, real a01, real a10, real a11);

        // Temp Place - will move to Matrix.h
        // Vector2<real> m_Ax(real A[], real x[], int NumRows, int NumCommon, int NumCols);
        // Matrix2x2<real> m_AB(real A[], real B[], int NumRows, int NumCommon, int NumCols);
        // void m_AB(real A[], real B[], real C[], int NumRows, int NumCommon, int NumCols);

    public:
        // Constructors
        // Creates an Identity
        Matrix();
        Matrix(Vector2<real> row1, Vector2<real> row2);
        Matrix(Vector3<real> row1, Vector3<real> row2, Vector3<real> row3);
        Matrix(const real array[], MatrixRowSize numRows);
        // ~Destructor
        ~Matrix() {}

        // GETTERS & SETTERS
        real Element(int row, int col);

        int GetRowSizeSquareMatrix();
        int GetSizeSquareMatrix();
        Matrix<real> GetMatrix();

        // METHODS
        real Determinant();
        bool IsInvertible();
        Matrix<real> Transpose();

        // OPERATORS
        Matrix<real> operator-();
        Matrix<real> operator*(real s);
        Vector2<real> operator*(Vector2<real> v);
        Vector3<real> operator*(Vector3<real> v);
        Matrix<real> operator*(Matrix<real> M);
    };

    template <typename real>
    Matrix<real>::Matrix()
    {
        // 3x3 Operations Only
        // Row Size of the Square Matrix
        _rowSizeSquareMatrix = 3;
        // Size of the Square Matrix
        _sizeSquareMatrix = 9;
        // Identity Matrix
        _identity();
    }

    template <typename real>
    Matrix<real>::Matrix(Vector2<real> row1, Vector2<real> row2)
    {
        // 2x2 Operations Only
        // Row Size of the Square Matrix
        _rowSizeSquareMatrix = 2;
        // Size of the Square Matrix
        _sizeSquareMatrix = 4;
        // Identity Matrix
        _identity();
        // 2x2 matrix
        // row1
        m_tuples[_it4(0, 0)] = row1.Element(0); // Vector Element
        m_tuples[_it4(0, 1)] = row1.Element(1); // Vector Element
        // row2
        m_tuples[_it4(1, 0)] = row2.Element(0); // Vector Element
        m_tuples[_it4(1, 1)] = row2.Element(1); // Vector Element
    }

    template <typename real>
    Matrix<real>::Matrix(Vector3<real> row1, Vector3<real> row2, Vector3<real> row3)
    {
        // 3x3 Operations Only
        // Row Size of the Square Matrix
        _rowSizeSquareMatrix = 3;
        // Size of the Square Matrix
        _sizeSquareMatrix = 9;
        // Identity Matrix
        _identity();
        // 3x3 matrix
        // row1
        m_tuples[_it4(0, 0)] = row1.Element(0); // Vector Element
        m_tuples[_it4(0, 1)] = row1.Element(1); // Vector Element
        m_tuples[_it4(0, 2)] = row1.Element(2); // Vector Element
        // row2
        m_tuples[_it4(1, 0)] = row2.Element(0); // Vector Element
        m_tuples[_it4(1, 1)] = row2.Element(1); // Vector Element
        m_tuples[_it4(1, 2)] = row2.Element(2); // Vector Element
        // row3
        m_tuples[_it4(2, 0)] = row3.Element(0); // Vector Element
        m_tuples[_it4(2, 1)] = row3.Element(1); // Vector Element
        m_tuples[_it4(2, 2)] = row3.Element(2); // Vector Element
    }

    template <typename real>
    Matrix<real>::Matrix(const real array[], MatrixRowSize numRows)
    {
        // 3x3 Operations Only
        // Row Size of the Square Matrix
        _rowSizeSquareMatrix = numRows;
        // Size of the Square Matrix
        _sizeSquareMatrix = numRows * numRows;
        // Identity Matrix
        _identity();
        // 3x3 matrix
        for (int r = 0; r < _rowSizeSquareMatrix; r++)
        {
            for (int c = 0; c < _rowSizeSquareMatrix; c++)
            {
                m_tuples[_it4(r, c)] = array[_it(r, c)];
            }
        }
    }

    template <typename real>
    real Matrix<real>::Element(int row, int col)
    {
        // Used for m_tuples[] ONLY
        return m_tuples[_it4(row, col)];
    }

    template <typename real>
    int Matrix<real>::GetRowSizeSquareMatrix()
    {
        return _rowSizeSquareMatrix;
    }

    template <typename real>
    int Matrix<real>::GetSizeSquareMatrix()
    {
        return _sizeSquareMatrix;
    }

    template <typename real>
    Matrix<real> Matrix<real>::GetMatrix()
    {
        // Sizes belong to THIS
        real tuples[_sizeSquareMatrix];
        for (int r = 0; r < _rowSizeSquareMatrix; r++)
        {
            for (int c = 0; c < _rowSizeSquareMatrix; c++)
            {
                tuples[_it(r, c)] = m_tuples[_it4(r, c)];
            }
        }
        // Constructed
        Matrix<real> matrix(tuples, (MatrixRowSize)_rowSizeSquareMatrix);
        return matrix;
    }

    // METHODS
    template <typename real>
    bool Matrix<real>::IsInvertible()
    {
        return Determinant() != (real)0;
    }

    // ----------------------------------------------------------- FIXME
    // Getting bad monitor data............... CRASH ..............DO NOT USE
    template <typename real>
    real Matrix<real>::Determinant()
    {
        // 00 01 02
        // 10 11 12
        // 20 21 22
        // 20221031 ToT :)
        real det = (real)0;

        if (_sizeSquareMatrix == 4)
        {
            det = _det(m_tuples[_it4(0, 0)], m_tuples[_it4(0, 1)], m_tuples[_it4(1, 0)], m_tuples[_it4(1, 1)]);
        }
        else if (_sizeSquareMatrix == 9)
        {
            // Column
            real d00 = _det(m_tuples[_it4(1, 1)], m_tuples[_it4(1, 2)], m_tuples[_it4(2, 1)], m_tuples[_it4(2, 2)]);
            real d10 = _det(m_tuples[_it4(0, 1)], m_tuples[_it4(0, 2)], m_tuples[_it4(2, 1)], m_tuples[_it4(2, 2)]);
            real d20 = _det(m_tuples[_it4(0, 1)], m_tuples[_it4(0, 2)], m_tuples[_it4(1, 1)], m_tuples[_it4(1, 2)]);

            det = m_tuples[_it4(0, 0)] * d00 - m_tuples[_it4(1, 0)] * d10 + m_tuples[_it4(2, 0)] * d20;
        }
        // pending size 16
        return det;
    }

    template <typename real>
    Matrix<real> Matrix<real>::Transpose()
    {
        // Sizes belong to THIS
        real tuples[_sizeSquareMatrix];
        for (int r = 0; r < _rowSizeSquareMatrix; r++)
        {
            for (int c = 0; c < _rowSizeSquareMatrix; c++)
            {
                tuples[_it(r, c)] = m_tuples[_it4(c, r)];
            }
        }
        // Constructed
        Matrix<real> matrix(tuples, (MatrixRowSize)_rowSizeSquareMatrix);
        return matrix;
    }

    // OPERATORS

    template <typename real>
    Matrix<real> Matrix<real>::operator-()
    {
        // Constructed
        Matrix<real> matrix = GetMatrix() * (real)-1;
        // Matrix<real> matrix(tuples, (MatrixRowSize)_rowSizeSquareMatrix);
        return matrix;
    }

    template <typename real>
    Matrix<real> Matrix<real>::operator*(real s)
    {
        // Sizes belong to THIS
        real tuples[_sizeSquareMatrix];
        for (int r = 0; r < _rowSizeSquareMatrix; r++)
        {
            for (int c = 0; c < _rowSizeSquareMatrix; c++)
            {
                tuples[_it(r, c)] = m_tuples[_it4(r, c)] * s;
            }
        }
        // Constructed
        Matrix<real> matrix(tuples, (MatrixRowSize)_rowSizeSquareMatrix);
        return matrix;
    }

    template <typename real>
    Vector2<real> Matrix<real>::operator*(Vector2<real> v)
    {
        real tuples[4];
        for (int r = 0; r < 2; r++)
        {
            tuples[r] = (real)0;
            for (int c = 0; c < 2; c++)
            {
                tuples[r] += m_tuples[_it4(r, c)] * v.Element(c); // Vector Element
            }
        }
        // Constructed
        Vector2<real> vector(tuples);
        return vector;
    }

    template <typename real>
    Vector3<real> Matrix<real>::operator*(Vector3<real> v)
    {
        real tuples[9];
        for (int r = 0; r < 3; r++)
        {
            tuples[r] = (real)0;
            for (int c = 0; c < 3; c++)
            {
                tuples[r] += m_tuples[_it4(r, c)] * v.Element(c); // Vector Element
            }
        }
        // Constructed
        Vector3<real> vector(tuples);
        return vector;
    }

    template <typename real>
    Matrix<real> Matrix<real>::operator*(Matrix<real> M)
    {
        // Sizes belong to THIS should match M
        real tuples[_sizeSquareMatrix];
        for (int r = 0; r < _rowSizeSquareMatrix; r++)
        {
            for (int c = 0; c < _rowSizeSquareMatrix; c++)
            {
                tuples[_it(r, c)] = (real)0;
                for (int k = 0; k < _rowSizeSquareMatrix; k++)
                {
                    tuples[_it(r, c)] += m_tuples[_it4(r, k)] * M.Element(k, c);
                }
            }
        }
        // Constructed
        Matrix<real> matrix(tuples, (MatrixRowSize)_rowSizeSquareMatrix);
        return matrix;
    }

    // PRIVATE

    template <typename real>
    int Matrix<real>::_it(int row, int col)
    {
        // Used only for vectors, variable arrays
        // Do not use on m_tuples[]
        return row * _rowSizeSquareMatrix + col;
    }

    template <typename real>
    int Matrix<real>::_it4(int row, int col)
    {
        int index = row * 4 + col;
        return index;
    }

    template <typename real>
    void Matrix<real>::_identity()
    {
        // Identity Matrix
        // Do not touch the sizes...ty
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                if (r == c)
                    m_tuples[_it4(r, c)] = (real)1;
                else
                    m_tuples[_it4(r, c)] = (real)0;
            }
        }
    }

    // Determinate 2x2

    template <typename real>
    real Matrix<real>::_det(real aa, real ab, real ba, real bb)
    {
        // -------------------------------------- NEED TO VERIFY
        // SOURCE:
        // row-major order
        real a = aa * bb;
        // debug
        // Serial.print("a ");
        // Serial.println(a);
        //
        real b = ab * ba;
        // debug
        // Serial.print("b ");
        // Serial.println(b);

        // Det
        real det = a - b;
        // debug
        // Serial.print("det ");
        // Serial.println(det);

        return det;
    }




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
}

#endif /* Numerics_Matrix_h */