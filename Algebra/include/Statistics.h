//
// Carpenter Software
// File: Class Bitwise.h
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

#ifndef Numerics_Statistics_h
#define Numerics_Statistics_h

#include <Arduino.h>

namespace nmr
{
    template <typename real>
    class Statistics
    {
    private:
        real *m_ptrTuples;
        real *m_ptrSorted;
        real *m_ptrRotator;
        int m_tuplesSize;

        real m_mean;
        real m_variance;
        real m_standardDeviation;
        real m_median;

        // Private Methods
        void m_Mean();
        void m_Variance();
        void m_StandardDeviation();
        void m_BublleSort();
        void m_Swap(int index);
        void m_Copy();
        void m_Median();
        bool m_Odd(int value);
        bool m_Limits(int index);

        // Envelopes
        void m_minimum();
        void m_complete();

    public:
        // Constructor
        Statistics() = default;
        Statistics(real *tuples, int size);
        ~Statistics() { delete[] m_ptrSorted; }

        // Methods
        int GetTuplesSize();
        real GetElement(int index);

        real Average();
        real StandardDeviation();
        real Median();
        void Queue(real value, int index);
        void QueueReset();

        real GetSorted(int index);
    };

    template <typename real>
    Statistics<real>::Statistics(real *tuples, int size)
    {
        // Only viable contructor
        // Under development

        // Variables
        m_ptrTuples = tuples;
        m_tuplesSize = size;
        // Need a sorted array - must be deleted
        m_ptrSorted = new real[size];

        // Envelope All results
        m_complete();

        // Linear Regression
        // Pending
    }

    template <typename real>
    int Statistics<real>::GetTuplesSize()
    {
        return m_tuplesSize;
    }

    template <typename real>
    real Statistics<real>::GetElement(int index)
    {
        if (m_Limits(index))
            return m_ptrTuples[index];
        return NAN;
    }

    template <typename real>
    real Statistics<real>::Average()
    {
        return m_mean;
    }

    template <typename real>
    real Statistics<real>::StandardDeviation()
    {
        return m_standardDeviation;
    }

    template <typename real>
    real Statistics<real>::Median()
    {
        return m_median;
    }

    template <typename real>
    void Statistics<real>::Queue(real value, int index)
    {
        m_ptrTuples[index] = value;

        // Envelope
        m_minimum();
    }

    template <typename real>
    void Statistics<real>::QueueReset()
    {
        // Used to increase the standard 
        // deviation by inserting an offset 
        // at the last index of the set....
        //
        // Needed to unstablize older set for testing
        // a newly queued set..., otherwise the older
        // stable set would give a false test....
        real offset = m_mean + (real)10000;
        m_ptrTuples[m_tuplesSize - 1] = offset;

        // Envelope
        m_minimum();
    }

    template <typename real>
    real Statistics<real>::GetSorted(int index)
    {
        if (m_Limits(index))
            return m_ptrSorted[index];
        return NAN;
    }

    // PRIVATE METHODS

    template <typename real>
    void Statistics<real>::m_Mean()
    {
        real sum = (real)0;
        for (int i = 0; i < m_tuplesSize; i++)
        {
            sum += m_ptrTuples[i];
        }
        m_mean = sum / (real)m_tuplesSize;
    }

    template <typename real>
    void Statistics<real>::m_Variance()
    {
        real temp = (real)0;
        real sum = (real)0;
        for (int i = 0; i < m_tuplesSize; i++)
        {
            temp = m_ptrTuples[i] - m_mean;
            sum += temp * temp;
        }
        m_variance = sum / ((real)m_tuplesSize - (real)1);
    }

    template <typename real>
    void Statistics<real>::m_StandardDeviation()
    {
        m_standardDeviation = sqrt((real)m_variance);
    }

    // OK to use for small number of samples.... FIXME
    // Uses separate array... under development.
    // Code here working as expected...O(n*n)
    template <typename real>
    void Statistics<real>::m_BublleSort()
    {
        for (int i = 0; i < m_tuplesSize - 1; i++)
        {
            for (int j = 0; j < m_tuplesSize - i - 1; j++)
            {
                if (m_ptrSorted[j] > m_ptrSorted[j + 1])
                    m_Swap(j);
            }
        }
    }

    template <typename real>
    void Statistics<real>::m_Swap(int index)
    {
        real temp = m_ptrSorted[index];
        m_ptrSorted[index] = m_ptrSorted[index + 1];
        m_ptrSorted[index + 1] = temp;
    }

    template <typename real>
    void Statistics<real>::m_Copy()
    {
        for (int i = 0; i < m_tuplesSize; i++)
        {
            m_ptrSorted[i] = m_ptrTuples[i];
            // Debug
            // Serial.println(String(m_ptrSorted[i], 2));
        }
    }

    template <typename real>
    void Statistics<real>::m_Median()
    {
        real median;
        int index;
        if (m_Odd(m_tuplesSize))
        {
            // ODD: math includes the zero index
            index = ((m_tuplesSize + 1) / 2) - 1;
            median = m_ptrSorted[index];
        }
        else
        {
            // EVEN: math includes the zero index
            index = (m_tuplesSize / 2) - 1;
            median = (m_ptrSorted[index] + m_ptrSorted[index + 1]) * (real)0.5;
        }

        m_median = median;
    }

    template <typename real>
    bool Statistics<real>::m_Odd(int value)
    {
        if ((value % 2) != 0)
            return true;
        return false;
    }

    template <typename real>
    bool Statistics<real>::m_Limits(int index)
    {
        if (index >= 0 && index < m_tuplesSize)
            return true;
        return false;
    }

    template <typename real>
    void Statistics<real>::m_minimum()
    {
        // Minimum
        // Average
        m_Mean();
        // Variance
        m_Variance();
        // Standard Deviation
        m_StandardDeviation();
    }

    template <typename real>
    void Statistics<real>::m_complete()
    {
        // do minimum first
        m_minimum();

        // Separated to reduce loading
        // time...
        
        // complete
        m_Copy();
        // Used on small number of samples...
        m_BublleSort(); 
        // Pending sort method for larger sets.... 
        // requires testing size (>21)
        m_Median();

        // pending
    }

}

#endif
