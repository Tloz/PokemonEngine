#ifndef PERSONALITYVALUE_H
#define PERSONALITYVALUE_H

#include "../inc/utils.h"
#include <array>
#include <cmath>

using namespace std;

class PersonalityValue
{

private:
    array<bool, 32> m_value;
public:
    PersonalityValue();
    ~PersonalityValue();
    unsigned int valueInt();
    unsigned int valueForGender();
    array<bool, 32> value();
    unsigned int valueForShiny1();
    unsigned int valueForShiny2();
    
};



#endif