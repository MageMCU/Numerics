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

namespace Numerics
{
    template <typename real>
    class Matrix : Vector<real>
    {
    private:
        // Private Members
        real m_tuples[16];

        // Private Methods
        // item & items
        int _it(int row, int col);
        int _it(int row, int col, int size);
        real _its(int index);
        void _identity();

    public:
        // Constructors
        // Creates an Identity
        Matrix();
        Matrix(const real array[]);
        // ~Destructor
        ~Matrix() {}

        // GETTERS & SETTERS
        int Index(int row, int col);
        real Element(int row, int col);

        // METHODS
        real Determinant();
        bool IsInvertible();
        Matrix<real> Transpose();

        // OPERATORS
        Vector<real> operator*(Vector<real> v);
        Matrix<real> operator*(Matrix<real> M);
    };

    template <typename real>
    Matrix<real>::Matrix()
    {
        // Identity Matrix
        _identity();
    }

    template <typename real>
    Matrix<real>::Matrix(const real array[])
    {
        // Identity Matrix
        _identity();
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                m_tuples[_it(r, c)] = array[_it(r, c, 3)];
            }
        }
    }

    template <typename real>
    int Matrix<real>::Index(int row, int col)
    {
        return _it(row, col);
    }

    template <typename real>
    real Matrix<real>::Element(int row, int col)
    {
        return m_tuples[_it(row, col)];
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
        real det;

        real m0 = m_tuples[_it(1, 1)] * m_tuples[_it(2, 2)] - m_tuples[_it(2, 1)] * m_tuples[_it(1, 2)];
        real m1 = m_tuples[_it(1, 0)] * m_tuples[_it(2, 2)] - m_tuples[_it(2, 0)] * m_tuples[_it(1, 2)];
        real m2 = m_tuples[_it(1, 0)] * m_tuples[_it(2, 1)] - m_tuples[_it(2, 0)] * m_tuples[_it(1, 1)];

        det = m_tuples[_it(0, 0)] * m0 - m_tuples[_it(0, 1)] * m1 + m_tuples[_it(0, 2)] * m2;

        return det;
    }

    template <typename real>
    Matrix<real> Matrix<real>::Transpose()
    {
        real values[9];
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                values[_it(r, c, 3)] = m_tuples[_it(c, r)];
            }
        }
        Matrix<real> matrix(values);
        return matrix;
    }

    // OPERATORS

    template <typename real>
    Vector<real> Matrix<real>::operator*(Vector<real> v)
    {
        real values[3];
        for (int r = 0; r < 3; r++)
        {
            values[r] = (real)0;
            for (int c = 0; c < 3; c++)
            {
                values[r] += m_tuples[_it(r, c)] * v.Element(c);
            }
        }

        Vector<real> vector(values);
        return vector;
    }

    template <typename real>
    Matrix<real> Matrix<real>::operator*(Matrix<real> M)
    {
        real values[9];
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                values[_it(r, c, 3)] = (real)0;
                for (int k = 0; k < 3; k++)
                {
                    values[_it(r, c, 3)] += m_tuples[_it(r, k)] * M.Element(k, c);
                }
            }
        }
        Matrix<real> matrix(values);
        return matrix;
    }

    // PRIVATE

    template <typename real>
    int Matrix<real>::_it(int row, int col, int size)
    {
        return row * size + col;
    }

    template <typename real>
    int Matrix<real>::_it(int row, int col)
    {
        return row * 4 + col;
    }

    template <typename real>
    real Matrix<real>::_its(int index)
    {
        return m_tuples[index];
    }

    template <typename real>
    void Matrix<real>::_identity()
    {
        // Identity Matrix
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                if (r == c)
                    m_tuples[_it(r, c)] = (real)1;
                else
                    m_tuples[_it(r, c)] = (real)0;
            }
        }
    }
}
#endif