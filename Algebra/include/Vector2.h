//
// Carpenter Software
// File: Class Vector2.h
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

#ifndef Numerics_Vector2_h
#define Numerics_Vector2_h

#include "Arduino.h"

namespace csjc
{
    template <typename real>
    class Vector2
    {
    private:
        // MEMBERS
        // int m_size; NOT USED
        real m_x;
        real m_y;

    public:
        // CONSTRUCTORS
        Vector2();
        Vector2(real x, real y);
        Vector2(const real array[]);

        // DESTRUCTOR
        ~Vector2() {}

        // GETTERS & SETTERS
        void x(real x);
        real x();
        void y(real y);
        real y();
        // int Size();  NOT USED
        real Element(int index);

        // METHODS
        Vector2<real> GetVector();
        real Magnitude();
        Vector2<real> UnitVector();
        real Distance();
        Vector2<real> Normalize();
        real Dot(Vector2<real> v);
        real Angle(Vector2<real> v);
        Vector2<real> Perp();
        Vector2<real> UnitPerp();
        real DotPerp(Vector2<real> v);
        real ZComp(Vector2<real> v);
        Vector2<real> ProjV(Vector2<real> v);

        // OPERATORS
        Vector2<real> operator-();
        Vector2<real> operator*(real s);
        Vector2<real> operator+(Vector2<real> v);
        Vector2<real> operator-(Vector2<real> v);
        real operator*(Vector2<real> v);
    };

    template <typename real>
    Vector2<real>::Vector2()
    {
        // m_size = 2;  NOT USED
        m_x = (real)0;
        m_y = (real)0;
    }

    template <typename real>
    Vector2<real>::Vector2(real x, real y)
    {
        // m_size = 2;  NOT USED
        m_x = x;
        m_y = y;
    }

    template <typename real>
    Vector2<real>::Vector2(const real array[])
    {
        // m_size = 2;  NOT USED
        m_x = array[0];
        m_y = array[1];
    }

    // GETTERS & SETTERS
    template <typename real>
    void Vector2<real>::x(real x) { m_x = x; }
    template <typename real>
    real Vector2<real>::x() { return m_x; }

    template <typename real>
    void Vector2<real>::y(real y) { m_y = y; }
    template <typename real>
    real Vector2<real>::y() { return m_y; }

    // template <typename real>  NOT USED
    // int Vector2<real>::Size() { return m_size; }

    template <typename real>
    real Vector2<real>::Element(int index)
    {
        real value = m_x;
        if (index == 1)
            value = m_y;
        return value;
    }

    // METHODS

    template <typename real>
    Vector2<real> Vector2<real>::GetVector()
    {
        Vector2<real> vector(m_x, m_y);
        return vector;
    }

    template <typename real>
    real Vector2<real>::Magnitude()
    {
        real sum = 0;
        sum += m_x * m_x;
        sum += m_y * m_y;
        return (real)sqrt(sum);
    }

    template <typename real>
    Vector2<real> Vector2<real>::UnitVector()
    {
        real x = (real)0;
        real y = (real)0;
        real magnitude = Magnitude();
        if (magnitude > (real)__FLT_EPSILON__)
        {
            x = m_x / magnitude;
            y = m_y / magnitude;
        }
        Vector2<real> vector(x, y);
        return vector;
    }

    template <typename real>
    real Vector2<real>::Distance()
    {
        return Magnitude();
    }

    template <typename real>
    Vector2<real> Vector2<real>::Normalize()
    {
        return UnitVector();
    }

    template <typename real>
    real Vector2<real>::Dot(Vector2<real> v)
    {
        // DOT Product
        // yeilds a Scalar
        real sum = (real)0;
        sum += m_x * v.x();
        sum += m_y * v.y();
        return sum;
    }

    template <typename real>
    real Vector2<real>::Angle(Vector2<real> v)
    {
        // Angle between 3D vectors
        Vector2<real> u = GetVector();
        // ref: [ELA] by Shields, 1980. p.213.
        return (real)acos((real)(u.Normalize() * v.Normalize()));
    }

    template <typename real>
    Vector2<real> Vector2<real>::Perp()
    {
        // BUGFIX
        // Notes - This can be a little tricky.
        // (1) 90 degrees CW (x, y) = Perp(y, -x) LHR
        // (x, y) * | 0  -1| = (y, -x)
        //          | 1   0|
        // (2) 90 degrees CCW (x, y) = Perp(-y, x) RHR*
        // (x, y) * |  0  1| = (-y, x)
        //          | -1  0|
        // * Right-handed rule
        // Rule: The z-component of the Cross-product
        //       SHOULD equal the DotPerp-product...
        //       Change 2-component to 3-component
        //       vectors by adding zeros.
        // (x1, y1, 0) Cross (x2, y2, 0) = z(X1Y2 - Y1X2)
        // This could be used as the DotPerp...

        // Constructed
        // WAS: Vector2<real> vector(m_y, -m_x);
        Vector2<real> vector(-m_y, m_x);
        return vector;
    }

    template <typename real>
    Vector2<real> Vector2<real>::UnitPerp()
    {
        // Constructed
        Vector2<real> vector = Perp();
        return vector.Normalize();
    }

    template <typename real>
    real Vector2<real>::DotPerp(Vector2<real> v)
    {
        // BUGFIX
        // Notes - This can be a little tricky.
        // (1) 90 degrees CW (x, y) = Perp(y, -x) LHR
        // (x, y) * | 0  -1| = (y, -x)
        //          | 1   0|
        // (2) 90 degrees CCW (x, y) = Perp(-y, x) RHR*
        // (x, y) * |  0  1| = (-y, x)
        //          | -1  0|
        // * Right-handed rule
        // Rule: The z-component of the Cross-product
        //       SHOULD equal the DotPerp-product...
        //       Change 2-component to 3-component
        //       vectors by adding zeros.
        // (x1, y1, 0) Cross (x2, y2, 0) = x0, y0, z(X1Y2 - Y1X2)
        // This could be used as the DotPerp...

        // Perpendicular Vector
        Vector2<real> u = Perp();
        // Dot Product
        float value = u * v;

        return value;
    }

    template <typename real>
    real Vector2<real>::ZComp(Vector2<real> v)
    {
        // BUGFIX
        // Notes - This can be a little tricky.
        // (1) 90 degrees CW (x, y) = Perp(y, -x) LHR
        // (x, y) * | 0  -1| = (y, -x)
        //          | 1   0|
        // (2) 90 degrees CCW (x, y) = Perp(-y, x) RHR*
        // (x, y) * |  0  1| = (-y, x)
        //          | -1  0|
        // * Right-handed rule
        // Rule: The z-component of the Cross-product
        //       SHOULD equal the DotPerp-product...
        //       Change 2-component to 3-component
        //       vectors by adding zeros.
        // (x1, y1, 0) Cross (x2, y2, 0) = x0, y0, z(X1Y2 - Y1X2)
        // This could be used as the DotPerp...

        // z-component
        return (m_x * v.y()) - (m_y * v.x());
    }

    template <typename real>
    Vector2<real> Vector2<real>::ProjV(Vector2<real> v)
    {
        // Project this.vector u onto v...
        // Constructed
        Vector2<real> u = GetVector();
        // real magnitude = v.Magnitude();

        // real dotUV = u * v;
        // real dotVV = v * v;
        // real quot = dotUV / dotVV;
        // where dotVV is equivalent to Square(v.Magnitude())...
        // ref: (1) [ELA] by Shields, 1980. p.237.
        //      (2) [Mf3DG&CG] 2nd Ed. by Lengyel, 2004. p19.
        real quot = (u * v) / (v * v);

        // Constructed
        Vector2<real> vector = v * quot;
        return vector;
    }

    // OPERATORS
    template <typename real>
    Vector2<real> Vector2<real>::operator-()
    {
        real x = m_x * (real)-1.0;
        real y = m_y * (real)-1.0;

        // Constructed
        Vector2<real> vector(x, y);
        return vector;
    }

    template <typename real>
    Vector2<real> Vector2<real>::operator*(real s)
    {
        real x = m_x * s;
        real y = m_y * s;

        // Constructed
        Vector2<real> vector(x, y);
        return vector;
    }

    template <typename real>
    Vector2<real> Vector2<real>::operator+(Vector2<real> v)
    {
        real x = m_x + v.x();
        real y = m_y + v.y();

        // Constructed
        Vector2<real> vector(x, y);
        return vector;
    }

    template <typename real>
    Vector2<real> Vector2<real>::operator-(Vector2<real> v)
    {
        real x = m_x - v.x();
        real y = m_y - v.y();

        // Constructed
        Vector2<real> vector(x, y);
        return vector;
    }

    template <typename real>
    real Vector2<real>::operator*(Vector2<real> v)
    {
        // DOT Product
        // yeilds a Scalar
        real sum = 0;

        sum += m_x * v.x();
        sum += m_y * v.y();

        return sum;
    }
}

#endif /* Numerics_Vector2_h */
