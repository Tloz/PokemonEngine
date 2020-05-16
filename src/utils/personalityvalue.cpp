#include "../../inc/personalityvalue.h"
#include <iostream>

using namespace std;

PersonalityValue::PersonalityValue()
{
    m_value = PersonalityValue::generate();
}

PersonalityValue::PersonalityValue(unsigned int ipv)
{
    m_value = ipv;
}

unsigned int PersonalityValue::generate()
{
    // if (sizeof(int) < sizeof(long))
    //     return (static_cast<long>(rand()) << (sizeof(int) * 8)) | rand();
    // return rand();
    unsigned int retval = 0;
    int mult;
    int exp;
    int base = 2;
    for (int i = 0; i < 32; ++i)
    {
        mult = (int(randFloatInRange(100,1000)) % 2);
        exp = 32 - i - 1;
        retval += mult * pow(base, exp);
    }
    return retval;
}

unsigned int PersonalityValue::valueInt()
{
    return m_value;
    // unsigned int val = 0;
    // int mult, base, exp;
    // for (int i = 0; i < 32; ++i)
    // {
    //     mult = m_value[i];
    //     base = 2;
    //     exp = 32 - i - 1;
    //     val += mult * pow(base, exp);
    // }
    // return val;
}

array<bool, 32> PersonalityValue::valueBool()
{
    array<bool, 32> retval;  // assuming a 32 bit int
    int i;

    for (i = 0; i < 32; ++i) {
        retval[31 - i] = (m_value >> i) & 1;
    }
    return retval;
}

unsigned int PersonalityValue::valueForGender()
{

    // unsigned int val = 0;
    // int mult, base, exp;

    // for (int i = 0; i < 8; ++i)
    // {
    //     mult = m_value[i + 24];
    //     base = 2;
    //     exp = 8 - i - 1;
    //     val += mult * pow(base, exp);
    // }
    // return val;
    return (m_value % 256);
}

unsigned int PersonalityValue::valueForGenderInt()
{
    return valueForGender();
}

array<bool, 8> PersonalityValue::valueForGenderBool()
{
    array<bool, 8> retval;
    array<bool, 32> tempval = valueBool();
    for (int i = 0; i < 8; ++i)
    {
        retval[i] = tempval[i + 24];
    }
    return retval;
}



unsigned int PersonalityValue::valueForShiny1()
{
    // = résultat div par 2^16
    return m_value / pow(2, 16);

    // unsigned int val = 0;
    // int mult, base, exp;
    // for (int i = 0; i <= 16; ++i)
    // {
    //     mult = m_value[i];
    //     base = 2;
    //     exp = 16 - i - 1;
    //     val += mult * pow(base, exp);
    // }
    // return val;
}

unsigned int PersonalityValue::valueForShiny2()
{
    return m_value % int(pow(2, 16));
    
    // unsigned int val = 0;
    // int mult, base, exp;
    // for (int i = 17; i < 32; ++i)
    // {
    //     mult = m_value[i];
    //     base = 2;
    //     exp = 16 - i - 1;
    //     val += mult * pow(base, exp);
    // }
    // return val;
}


PersonalityValue::~PersonalityValue()
{

}