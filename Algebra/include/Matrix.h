//
// Carpenter Software
// File: Class Matrix.h
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
// Created 20221008
// Updated 20221015
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
#include "Vector.h"

namespace nmr
{
    enum MatrixRowSize
    {
        a2x2 = 2,
        a3x3 = 3,
        a4x4 = 4
    };

    template <typename real>
    class Matrix : Vector<real>
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

    public:
        // Constructors
        // Creates an Identity
        Matrix();
        Matrix(Vector<real> row1, Vector<real> row2);
        Matrix(Vector<real> row1, Vector<real> row2, Vector<real> row3);
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
        Vector<real> operator*(Vector<real> v);
        Matrix<real> operator*(Matrix<real> M);
        // Matrix<real> operator=(Matrix<real> M);
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
    Matrix<real>::Matrix(Vector<real> row1, Vector<real> row2)
    {
        Serial.println("Entered Matrix(Vector<real> row1, Vector<real> row2)");

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
    Matrix<real>::Matrix(Vector<real> row1, Vector<real> row2, Vector<real> row3)
    {
        Serial.println("Entered Matrix()");

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
                // Only interested in size _rowSizeSquareMatrix
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
                // Only interested in size _rowSizeSquareMatrix
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

    template <typename real>
    real Matrix<real>::Determinant()
    {
        // 00 01 02
        // 10 11 12
        // 20 21 22
        real det = (real)0;
        // Sizes belong to THIS - size constriant
        if (_sizeSquareMatrix == 9)
        {
            real m0 = m_tuples[_it4(1, 1)] * m_tuples[_it4(2, 2)] - m_tuples[_it4(2, 1)] * m_tuples[_it4(1, 2)];
            real m1 = m_tuples[_it4(1, 0)] * m_tuples[_it4(2, 2)] - m_tuples[_it4(2, 0)] * m_tuples[_it4(1, 2)];
            real m2 = m_tuples[_it4(1, 0)] * m_tuples[_it4(2, 1)] - m_tuples[_it4(2, 0)] * m_tuples[_it4(1, 1)];
            det = m_tuples[_it4(0, 0)] * m0 - m_tuples[_it4(0, 1)] * m1 + m_tuples[_it4(0, 2)] * m2;
        }
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
                // Only interested in size _rowSizeSquareMatrix
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
                // Only interested in size _rowSizeSquareMatrix
                tuples[_it(r, c)] = m_tuples[_it4(r, c)] * s;
            }
        }
        // Constructed
        Matrix<real> matrix(tuples, (MatrixRowSize)_rowSizeSquareMatrix);
        return matrix;
    }

    template <typename real>
    Vector<real> Matrix<real>::operator*(Vector<real> v)
    {
        // Sizes belong to THIS
        real tuples[_sizeSquareMatrix];
        for (int r = 0; r < _rowSizeSquareMatrix; r++)
        {
            tuples[r] = (real)0;
            for (int c = 0; c < _rowSizeSquareMatrix; c++)
            {
                // Only interested in size _rowSizeSquareMatrix
                tuples[r] += m_tuples[_it4(r, c)] * v.Element(c); // Vector Element
            }
        }
        // Constructed
        Vector<real> vector(tuples);
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
                    // Only interested in size _rowSizeSquareMatrix
                    tuples[_it(r, c)] += m_tuples[_it4(r, k)] * M.Element(k, c);
                }
            }
        }
        // Constructed
        Matrix<real> matrix(tuples, (MatrixRowSize)_rowSizeSquareMatrix);
        return matrix;
    }

    /* NOTE: IT SEEMS THAT build_flags = -std=gnu++11 WORKS
             BETTER THAN -std=c++11... THE ONLY build_flags
             USED WAS STATED ABOVE...THEREFORE THE COPY MIGHT
             NOT BE NEEDED... FURTHER TEST REQUIRED...
    template <typename real>
    Matrix<real> Matrix<real>::operator=(Matrix<real> M)
    {
        // Sizes belong to M
        _sizeSquareMatrix = M.GetSizeSquareMatrix();
        _rowSizeSquareMatrix = M.GetRowSizeSquareMatrix();
        //
        real tuples[_sizeSquareMatrix];

        // Identity Matrix
        for (int r = 0; r < _rowSizeSquareMatrix; r++)
        {
            for (int c = 0; c < _rowSizeSquareMatrix; c++)
            {
                // Only interested in size _rowSizeSquareMatrix
                tuples[_it(r, c)] = M.Element(r, c);
            }
        }
        // Constructed
        Matrix<real> matrix(tuples, (MatrixRowSize)_rowSizeSquareMatrix);
        return matrix;
    }
    */

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
        return row * 4 + col;
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
}
#endif