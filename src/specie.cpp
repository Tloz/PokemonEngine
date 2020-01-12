#include "../inc/specie.h"

Specie::Specie()
{

}

Specie::Specie(int id, int variant = 0)
{

}

Specie::~Specie()
{
    
}

int Specie::specieID()
{
    return m_specieID;
}

int* Specie::baseStats()
{
    for (int i = 0; i <= 5; ++i)
    {
        if(m_baseStats[i] < 1)
            m_baseStats[i] = 1;
        else if(m_baseStats[i] > 255)
            m_baseStats[i] = 255;
    }
    return m_baseStats;
}

int Specie::baseStat(int index)
{
    if((index < 0) || (index > 5))
        throw exception();
    if(m_baseStats[index] < 1)
            m_baseStats[index] = 1;
    else if(m_baseStats[index] > 255)
        m_baseStats[index] = 255;
    return m_baseStats[index];
}

void Specie::baseStat(int index, int ammount)
{
    if((index < 0) || (index > 5))
        throw exception();
    if(ammount < 1)
        ammount = 1;
    else if(ammount > 255)
        ammount = 255;
    m_baseStats[index] = ammount;
}

int Specie::baseLP()
{
    return baseStat(0);
}

void Specie::baseLP(int ammount)
{
    baseStat(0, ammount);
}

int Specie::baseAtk()
{
    return baseStat(1);
}

void Specie::baseAtk(int ammount)
{
    baseStat(1, ammount);
}

int Specie::baseDef()
{
    return baseStat(2);
}

void Specie::baseDef(int ammount)
{
    baseStat(2, ammount);
}

int Specie::baseSpeAtk()
{
    return baseStat(3);
}

void Specie::baseSpeAtk(int ammount)
{
    baseStat(3, ammount);
}

int Specie::baseSpeDef()
{
    return baseStat(4);
}

void Specie::baseSpeDef(int ammount)
{
    baseStat(4, ammount);
}

int Specie::baseSpeed()
{
    return baseStat(5);
}

void Specie::baseSpeed(int ammount)
{
    baseStat(5, ammount);
}

int Specie::type(int index)
{
    if(!isTypeNumberValid(m_type[index]))
        throw exception();
    return m_type[index];
}

int Specie::firstType()
{
    return type(0);
}

int Specie::secondType()
{
    return type(1);
}

// TODO: make sure this is clean
// int* Specie::types()
// {
//     for (int i = 0; i < 2; ++i)
//     {
//         /* code */
//     }
//     return m_types;
// }

void Specie::type(int index, int p_type)
{
    if((index < 0) || (index > 1))
        throw exception();
    if(!isTypeNumberValid(p_type))
        throw exception();
    m_type[index] = p_type;
}

void Specie::firstType(int p_type)
{
    type(0, p_type);
}

void Specie::secondType(int p_type)
{
    type(1, p_type);
}

void Specie::types(array<int, 2> tab)
{
    if(!isTypeTabValid(tab))
        throw exception();
    m_type.swap(tab);
    
}
