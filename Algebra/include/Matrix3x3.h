//
// Carpenter Software
// File: Class Matrix3x3.h
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

#ifndef Matrix3x3_h
#define Matrix3x3_h

#include "Arduino.h"
#include "Vector3.h"

namespace Numerics
{
    template <typename real>
    class Matrix3x3 : Vector3<real>
    {
    private:
        real m_tuples[9];
        // item & items
        int _it(int row, int col);
        real _its(int index);

    public:
        // Creates an Identity
        Matrix3x3();
        Matrix3x3(const real array[]);

        // GETTERS & SETTERS
        real Element(int row, int col);

        // METHODS
        Matrix3x3<real> Transpose();

        // OPERATORS
        Vector3<real> operator*(Vector3<real> v);
        Matrix3x3<real> operator*(Matrix3x3<real> M);
    };

    template <typename real>
    Matrix3x3<real>::Matrix3x3()
    {
        // Identity Matrix
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                if (r == c)
                    m_tuples[_it(r, c)] = (real)1;
                else
                    m_tuples[_it(r, c)] = (real)0;
            }
        }
    }

    template <typename real>
    Matrix3x3<real>::Matrix3x3(const real array[])
    {
        for (int i = 0; i < 9; i++)
            m_tuples[i] = array[i];
    }

    template <typename real>
    real Matrix3x3<real>::Element(int row, int col)
    {
        return m_tuples[_it(row, col)];
    }

    // METHODS

    template <typename real>
    Vector3<real> Matrix3x3<real>::operator*(Vector3<real> v)
    {
        float values[3];
        for (int row = 0; row < 3; row++)
        {
            values[row] = (real)0;
            for (int col = 0; col < 3; col++)
            {
                values[row] += m_tuples[_it(row, col)] * v.Element(col);
            }
        }
        Vector3<real> vector(values);
        return vector;
    }

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::Transpose()
    {
        float values[9];
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                values[_it(col, row)] = m_tuples[_it(row, col)];
            }
        }
        Matrix3x3<real> matrix(values);
        return matrix;
    }

    // OPERATORS

    template <typename real>
    Matrix3x3<real> Matrix3x3<real>::operator*(Matrix3x3<real> M)
    {
        float values[9];
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                values[_it(row, col)] = (real)0;
                for (int k = 0; k < 3; k++)
                {
                    values[_it(row, col)] += m_tuples[_it(row, k)] * M.Element(k, col);
                }
            }
        }
        Matrix3x3<real> matrix(values);
        return matrix;
    }

    // PRIVATE

    template <typename real>
    int Matrix3x3<real>::_it(int row, int col)
    {
        return row * 3 + col;
    }

    template <typename real>
    real Matrix3x3<real>::_its(int index)
    {
        return m_tuples[index];
    }
}
#endif