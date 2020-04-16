#ifndef GENDER_H
#define GENDER_H

#include "utils.h"
#include <string>

enum class Gender
{
    None,
    Male,
    Female
};

Gender determineGender(float balance, float vfg);
std::string genderToString(Gender g);

#endif