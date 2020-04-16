#include "../inc/personalityvalue.h"
#include <iostream>

using namespace std;

PersonalityValue::PersonalityValue()
{
    int tmp = 0;
    for (int i = 0; i < 32; ++i)
    {
        tmp = randFloatInRange(100,1000);
        m_value[i] = tmp % 2;
    }
}

unsigned int PersonalityValue::valueInt()
{
    unsigned int val = 0;
    int mult, base, exp;
    for (int i = 0; i < 32; ++i)
    {
        mult = m_value[i];
        base = 2;
        exp = 32 - i - 1;
        val += mult * pow(base, exp);
    }
    return val;
}

unsigned int PersonalityValue::valueForGender()
{
    unsigned int val = 0;
    int mult, base, exp;
    for (int i = 0; i < 8; ++i)
    {
        mult = m_value[i + 24];
        base = 2;
        exp = 8 - i - 1;
        val += mult * pow(base, exp);
    }
    return val;
}

array<bool, 32> PersonalityValue::value()
{
    return m_value;
}

unsigned int PersonalityValue::valueForShiny1()
{
    unsigned int val = 0;
    int mult, base, exp;
    for (int i = 0; i <= 16; ++i)
    {
        mult = m_value[i];
        base = 2;
        exp = 16 - i - 1;
        val += mult * pow(base, exp);
    }
    return val;
}

unsigned int PersonalityValue::valueForShiny2()
{
    unsigned int val = 0;
    int mult, base, exp;
    for (int i = 17; i < 32; ++i)
    {
        mult = m_value[i];
        base = 2;
        exp = 16 - i - 1;
        val += mult * pow(base, exp);
    }
    return val;
}


PersonalityValue::~PersonalityValue()
{

}