#ifndef PERSONALITYVALUE_H
#define PERSONALITYVALUE_H

#include "../inc/utils.h"
#include <array>
#include <cmath>

using namespace std;

class PersonalityValue
{

private:
    unsigned int m_value;
public:
    PersonalityValue();
    PersonalityValue(unsigned int ipv);
    ~PersonalityValue();
    static unsigned int generate();
    unsigned int valueInt();
    unsigned int valueForGender();
    unsigned int valueForGenderInt();
    array<bool, 8> valueForGenderBool();
    array<bool, 32> valueBool();
    unsigned int valueForShiny1();
    unsigned int valueForShiny2();
    
};



#endif