#include "../inc/type.h"

bool isTypeNumberValid(int number)
{
    return (number >= 0) && (number <= 18);
}

Type::Type(Type_t value)
{
    if(isTypeNumberValid(value))
        m_value = value;
    else
        m_value = Type_t::None; // If given type is invalid, default to None
}

Type::Type(int value)
{
    if(isTypeNumberValid(Type_t(value)))
        m_value = Type_t(value);
    else
        m_value = Type_t::None; // If given type is invalid, default to None
}

Type::~Type()
{
    
}

Type_t Type::value()
{
    return m_value;
}

bool Type::isTouchingFloor()
{
    return m_value != Type_t::Fly;
}

bool Type::canBePoisoned()
{
    return m_value != Type_t::Poison;
}

bool Type::canBeParalysed()
{
    return m_value != Type_t::Electric;
}

bool Type::canBeBurned()
{
    return m_value != Type_t::Fire;
}

bool Type::canBeFrozen()
{
    return m_value != Type_t::Ice;
}

bool Type::canBeLeeched()
{
    return m_value != Type_t::Grass;
}

float Type::multWhenHitBy(Type_t what)
{
    return efficiencyTab[int(m_value)][int(what)];
}


// float efficiency(int attackType, int defenseType)
// {
//     return m_efficiency_values[defenseType][attackType];
// }

// string efficiency_text_debug(int attackType, int defenseType)
// {
//     float frac = efficiency(attackType, defenseType);
//     if (frac == 0.0)
//         return string("C'est sans effet");
//     else if ((frac == 0.25) || (frac == 0.5))
//         return string("Ce n'est pas très efficace");
//     else if ((frac == 2.0) || (frac == 4.0))
//         return string("C'est super efficace");
//     else
//         return string ("Efficace");
// }