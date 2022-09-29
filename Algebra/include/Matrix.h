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
// Created 20220927
// develpment 20220928
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef MATRIX_H // IN-PROCESS
#define MATRIX_H

#include "Arduino.h"
#include "Tuples.h"
#include "Vector.h"
#include "Point.h"

namespace Numerics
{
    template <typename real>
    class Matrix : Point<real>
    {
    private:
        // Members
        int _size;
        // real _indices[4][4];
        real _tuples[16];

        void _identity();

    public:
        // Constructors
        Matrix();

        // Destructor
        ~Matrix(){};

        // getters
        real GetValue(int rowIndex, int colIndex);

        // setters
        void SetValue(real value, int rowIndex, int colIndex);

        // Inquiry

        // Methods
    };

    // Constructors

    template <typename real>
    Matrix<real>::Matrix()
    {
        _identity();
    }

    // getters

    template <typename real>
    real Matrix<real>::GetValue(int rowIndex, int colIndex)
    {
        real tuple;
        int size4x4 = 4;
        // Allow fetch only at 3x3 Matrix
        if (rowIndex < size4x4 && colIndex < size4x4)
            tuple = _tuples[rowIndex * size4x4 + colIndex];
        return tuple;
    }

    // setters

    template <typename real>
    void Matrix<real>::SetValue(real value, int rowIndex, int colIndex)
    {
        int size4x4 = 4;
        // Allow fetch only at 3x3 Matrix
        if (rowIndex < size4x4 && colIndex < size4x4)
            _tuples[rowIndex * size4x4 + colIndex] = value;
    }

    // PRIVATE METHODS

    template <typename real>
    void Matrix<real>::_identity()
    {
        int size4x4 = 4;

        // Number of tuples
        _size = 16; // 4x4 affine identity

        // Identity Matrix
        for (int row = 0; row < size4x4; row++)
        {
            for (int col = 0; col < size4x4; col++)
            {
                // Column major
                // Serial.print(row);
                // Serial.print(" ");
                // Serial.print(col);
                // Serial.print(" ");
                // Serial.println(row * size4x4 + col);

                if (row == col)
                    _tuples[row * size4x4 + col] = 1;
                else
                    _tuples[row * size4x4 + col] = 0;
            }
        }
    }
}

#endif