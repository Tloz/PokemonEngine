#include "../inc/gender.h"

Gender determineGender(float balance, float vfg)
{
    if(balance < 0.0)
        return Gender::None;
    else if(balance == 0.0)
        return Gender::Male;
    else if(balance == 100.0)
        return Gender::Female;
    else
    {
        balance = balance * 2.56 - 1;
        if(vfg <= balance)
            return Gender::Female;
        else
            return Gender::Male;
    }
}

std::string genderToString(Gender g)
{
    switch(g)
    {
        case Gender::Male:
            return "Male";
        case Gender::Female:
            return "Femelle";
        case Gender::None:
        default:
            return "Assexué";
    }
}