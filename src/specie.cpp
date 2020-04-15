#include "../data/values.h"
#include "../inc/specie.h"
#include <iostream>

Specie::Specie(int id, int variant = 0)
{
    m_specieID = id;
    m_variant = variant;
}

Specie::~Specie()
{
    delete m_type;
    delete m_baseStats;
}

float Specie::genderBalance()
{
    return m_genderBalance;
}

void Specie::genderBalance(float val)
{
    m_genderBalance = val;
}

int Specie::specieID()
{
    return m_specieID;
}

void Specie::specieID(int id)
{
    if(id >= 0)
        m_specieID = id;
    else
        throw exception();
}

string Specie::specieName()
{
    if(m_specieName.size() == 0)
        throw exception();
    return m_specieName;
}

void Specie::specieName(string newName)
{
    if(newName.size() == 0)
        throw exception();
    m_specieName = newName;
}

int Specie::variant()
{
    return m_variant;
}
void Specie::variant(int id)
{
    if(id >= 0)
        m_variant = id;
    else
        throw exception();
}

string Specie::variantName()
{
    return m_variantName;
}

void Specie::variantName(string name)
{
    m_variantName = name;
}

array<int, 6> Specie::baseStats()
{
    // Before returning the array, make sure values are within borders
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
    // make sure index and value are within proper borders and range
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
    // make sure index and value are within proper borders
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

Type* Specie::type(int index)
{
    if(!isTypeNumberValid(int(m_type[index]->value())))
    {
        throw exception();
    }
    return m_type[index];
}

Type* Specie::firstType()
{
    return type(0);
}

Type* Specie::secondType()
{
    return type(1);
}

array<Type*, 2> Specie::types()
{
    array<Type*, 2> retval;
    retval[0] = firstType();
    retval[1] = secondType();
    return retval;
}

void Specie::type(int index, Type* p_type)
{
    // make sure index and value are within proper borders
    if((index < 0) || (index > 1))
        throw exception();
    if(!isTypeNumberValid(int(p_type->value())))
        throw exception();
    m_type[index] = p_type;
}

void Specie::firstType(Type* p_type)
{
    type(0, p_type);
}

void Specie::secondType(Type* p_type)
{
    type(1, p_type);
}

void Specie::types(array<Type*, 2> tab)
{
    if((isTypeNumberValid(int(tab[0]->value())))
    && (isTypeNumberValid(int(tab[1]->value()))))
        m_type.swap(tab);  
    else
        throw exception();
}

bool Specie::isOfType(Type* p_type)
{
    return ((firstType()->value() == p_type->value()) 
        || (secondType()->value() == p_type->value()));
}

bool Specie::hasSecondType()
{
    if (secondType()->value() == Type_t::None)
    {
        return false;
    }
    return true;
}

// vector<Evolution*> Specie::evolutionLine()
// {
//     return m_evolutionLine;
// }

// vector<Evolution*> Specie::evolveWith(EvolutionTrigger trigger)
// {
//     vector<Evolution*> retarray;
//     for (unsigned int i = 0; i < evolutionLine().size(); ++i)
//     {
//         if(evolutionLine().at(i)->trigger() == trigger)
//             retarray.push_back(evolutionLine().at(i));
//     }
//     return retarray;
// }