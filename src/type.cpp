#include "../inc/type.h"

float efficiency(Type attackType, Type defenseType)
{
    return efficiency_values[int(defenseType)][int(attackType)];
}

string efficiency_text_debug(Type attackType, Type defenseType)
{
    float frac = efficiency(attackType, defenseType);
    if (frac == 0.0)
        return string("C'est sans effet");
    else if ((frac == 0.25) || (frac == 0.5))
        return string("Ce n'est pas très efficace");
    else if ((frac == 2.0) || (frac == 4.0))
        return string("C'est super efficace");
    else
        return string ("Efficace");
}