#include "../inc/type.h"

// checks that given number is between 0 and 18 (included)
bool isTypeNumberValid(int number)
{
    return (number >= 0) && (number <= 18);
}

Type::Type()
{
    m_value = Type_t::None;
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
    {
        m_value = Type_t(value);
    }
    else
        m_value = Type_t::None; // If given type is invalid, default to None
}

Type::~Type()
{

}

string Type::name()
{
    switch(m_value)
    {
        case Dark:
            return "Dark";
            break;

        case Dragon:
            return "Dragon";
            break;

        case Electric:
        return "Electric";
            break;

        case Fairy:
        return "Fairy";
            break;

        case Fight:
        return "Fight";
            break;

        case Fire:
        return "Fire";
            break;

        case Floor:
        return "Floor";
            break;

        case Fly:
        return "Fly";
            break;

        case Ghost:
        return "Ghost";
            break;

        case Grass:
        return "Grass";
            break;

        case Ice:
        return "Ice";
            break;

        case Insect:
        return "Insect";
            break;

        case Normal:
        return "Normal";
            break;

        case Poison:
        return "Poison";
            break;

        case Psy:
        return "Psy";
            break;

        case Rock:
        return "Rock";
            break;

        case Steel:
        return "Steel";
            break;

        case Water:
        return "Water";
            break;

        case None:
        default:
        return "None";
            break;
    }

}

Type_t Type::value()
{
    return m_value;
}

Type* Type::getType(Type_t value)
{
    Type *t = new Type(value);
    return t;
}

Type* Type::getType(int value)
{
    Type *t = new Type(value);
    return t;
}

float Type::multWhenHitBy(Type_t what)
{
    return efficiencyTab[int(m_value)][int(what)];
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

bool Type::immuneToPowder()
{
    return m_value != Type_t::Grass;
}

bool Type::canBeLeeched()
{
    return m_value != Type_t::Grass;
}


