#ifndef TEST_CPP_H
#define TEST_CPP_H

#include "GeneralTypes.h"

class TestClass
{
    public:

        TestClass()
        : m_Val( 100 )
        {

        }

        ~TestClass()
        {

        }

        uint16_t GetVal() const
        {
            return m_Val;
        }

        void SetVal( uint16_t a_Val )
        {
            m_Val = a_Val;
        }

    private:

        uint16_t m_Val;

};

#endif
