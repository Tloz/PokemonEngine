#include "../inc/type.h"

bool isTypeNumberValid(int number)
{
    return (number >= 0)&& (number <= 18);
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


