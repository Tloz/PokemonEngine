#include "../data/values.h"
#include "../inc/specie.h"
#include <iostream>

Specie::Specie(int testVal)
{
    m_specieName = TABnames[testVal];
    m_specieID = TABspecieID[testVal];
    m_variant = TABvariantID[testVal];
    m_baseStats[0] = TABLP[testVal];
    m_baseStats[1] = TABATK[testVal];
    m_baseStats[2] = TABDEF[testVal];
    m_baseStats[3] = TABSpeATK[testVal];
    m_baseStats[4] = TABSpeDEF[testVal];
    m_baseStats[5] = TABSpeed[testVal];
    m_type[0] = new Type(TABtypes1[testVal]);
    m_type[1] = new Type(TABtypes2[testVal]);
    m_genderBalance = TABgenderBalance[testVal];
}

Specie::Specie(int id, int variant = 0)
{
    m_specieID = id;
    m_variant = variant;
}

Specie::~Specie()
{
    //
    //  
}

void Specie::print()
{
    cout << "Specie " << m_specieName;
    if(m_variant != 0)
        cout << " " << m_variantName;
    cout << " (" << m_specieID << ")" << endl;
    cout << "Type: " << firstType()->name();
    if (hasSecondType())
        cout << " and " << secondType()->name();
    cout << endl;
    cout << "LP: " << baseStat(0) << " Speed: " << baseStat(5) << endl;
    cout << "ATK: " << baseStat(1) << " DEF: " << baseStat(2) << endl;
    cout << "ATK: " << baseStat(3) << " DEF: " << baseStat(4) << endl;
    cout << m_genderBalance << "% chances of being female" << endl << endl;
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