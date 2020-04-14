#include "utils.h"

enum class Gender
{
    None,
    Male,
    Female
};

Gender determineGender(float balance)
{
    if(balance < 0)
        return Gender::None;
    else if(balance == 0)
        return Gender::Male;
    else if(balance == 100.0)
        return Gender::Female;
    else
    {
        if(randFloatInRange(0.00, 100.00) <= balance)
            return Gender::Female;
        else
            return Gender::Male;
    }
}