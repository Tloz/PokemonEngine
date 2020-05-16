#include "../inc/specie.h"
#include "../inc/parser.h"
#include "../inc/typefactory.h"
#include <iostream>
#include <fstream>
#include <string>

Specie::Specie()
{
    
}

Specie::Specie(vector<vector<string>> tokensVector)
{
    bool verbose = false;
    vector<string> unsedTokens;
    for(auto tokens:tokensVector)
    {
        //cout << tokens[0] << ":" << tokens[1] << endl;
        if(tokens[0] == "Specie")
        {
            specieID(stoi(tokens[1]));
        }
        else if(tokens[0] == "VariantID")
        {
            variant(stoi(tokens[1]));
        }
        else if(tokens[0] == "Name")
        {
            specieName(tokens[1]);
        }
        else if((tokens[0] == "NameExt") && (tokens.size() == 2))
        {
            variantName(tokens[1]);
        }
        else if(tokens[0] == "Types")
        {
            firstType(TypeFactory::createType(stoi(tokens[1])));
            secondType(TypeFactory::createType(stoi(tokens[2])));
        }
        else if(tokens[0] == "Stats")
        {
            for (int i = 0; i < 6; ++i)
                baseStat(i, stoi(tokens[i + 1]));
        }
        else if(tokens[0] == "GB")
        {
            m_genderBalance = stof(tokens[1]);
        }
        else if(tokens[0] == "CatchRate")
        {
            m_catchRate = stoi(tokens[1]);
        }
        else if(tokens[0] == "EffortValue")
        {
            vector<pair<int, int >> v;
            for (unsigned int i = 1; i < tokens.size(); i = i + 2)
            {
                int EVIndex = stoi(tokens[i]);
                int EVAmmount = stoi(tokens[i + 1]);
                v.push_back(make_pair(EVIndex, EVAmmount));
            }
            EVGiven(v);
        }
        else if(tokens[0] == "BaseXP")
        {
            m_baseExp = stoi(tokens[1]);
        }
        else if(tokens[0] == "XPat100")
        {
            m_expAt100 = stoi(tokens[1]);
        }
        else
        {
            unsedTokens.push_back(tokens[0]);
        }
    }
    if(verbose && (unsedTokens.size() > 0))
    {
        cout << "Unused tokens: ";
        for(auto token:unsedTokens)
            cout << token << "; ";
        cout << endl;
    }
}

Specie::~Specie()
{

}

void Specie::print()
{
    cout << "Specie " << specieName();
    if((variant() != 0))
    {
        cout << " " << variantName();
    }
    cout << " (" << specieID() << ")" << endl;
    cout << "Type: " << firstType().name();
    if (hasSecondType())
    {
        cout << " and " << secondType().name();
    }
    cout << endl;
    cout << "LP: " << baseStat(0) << " Speed: " << baseStat(5) << endl;
    cout << "ATK: " << baseStat(1) << " DEF: " << baseStat(2) << endl;
    cout << "ATK: " << baseStat(3) << " DEF: " << baseStat(4) << endl;
    cout << genderBalance() << "% chances of being female" << endl;
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
        throw invalid_argument("SpecieID is invalid");
}

string Specie::specieName()
{
    if(m_specieName.size() == 0)
    {
        throw invalid_argument("SpecieName is invalid");
    }
    return m_specieName;
}

void Specie::specieName(string newName)
{
    if(newName.size() == 0)
        throw invalid_argument("newName is invalid");
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
        throw invalid_argument("variantID must be positive");
}

string Specie::variantName()
{
    return m_variantName;
}

void Specie::variantName(string name)
{
    m_variantName = name;
}

string Specie::fullName()
{
    return m_specieName + " " + m_variantName;
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
        throw invalid_argument("Index is OoB");
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
        throw invalid_argument("Index is OoB");
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

Type Specie::type(int index)
{
    if(!Type::isNumberValid(m_type[index].value()))
    {
        string what = "given index is OoB, must be 0 or 1";
        what += m_type[index].value();
        throw invalid_argument(what);
    }
    return m_type[index];
}

Type Specie::firstType()
{
    return type(0);
}

Type Specie::secondType()
{
    return type(1);
}

array<Type, 2> Specie::types()
{
    return m_type;
}

void Specie::type(int index, Type p_type)
{
    // make sure index and value are within proper borders
    if((index < 0) || (index > 1))
        throw invalid_argument("Out of bounds in Specie.type(index, p_type)");
    if(!Type::isNumberValid(p_type.value()))
        throw invalid_argument("invalide type number given in Specie.type(index, p_type)");
    m_type[index] = p_type;
}

void Specie::firstType(Type p_type)
{
    type(0, p_type);
}

void Specie::secondType(Type p_type)
{
    type(1, p_type);
}

void Specie::types(array<Type, 2> tab)
{
    if((Type::isNumberValid(tab[0].value()))
    && (Type::isNumberValid(tab[1].value())))
        m_type.swap(tab);  
    else
        throw invalid_argument("At least one given type is invalid in Specie.types()");
}

bool Specie::isOfType(Type p_type)
{
    return ((firstType().value() == p_type.value()) 
        || (secondType().value() == p_type.value()));
}

bool Specie::hasSecondType()
{
    if (secondType().value() == 0)
    {
        return false;
    }
    return true;
}

void Specie::type(int index, int typeNo)
{
    // make sure index and value are within proper borders
    if((index < 0) || (index > 1))
        throw invalid_argument("Out of bounds in Specie.type(index, p_type) with int");
    if(!Type::isNumberValid(typeNo))
        throw invalid_argument("At least one givent type is invalid in Specie.type(index, p_type) with int");
    m_type[index] = TypeFactory::createType(typeNo);
}

void Specie::firstType(int typeNo)
{
    type(0, typeNo);
}

void Specie::secondType(int typeNo)
{
    type(1, typeNo);
}

void Specie::types(array<int, 2> tab)
{
    if((Type::isNumberValid(tab[0]))
    && (Type::isNumberValid(tab[1])))
    {
        array<Type, 2> newTab;
        newTab[0] = TypeFactory::createType(tab[0]);
        newTab[1] = TypeFactory::createType(tab[1]);
        m_type.swap(newTab);  
    }
    else
        throw invalid_argument("in Specie.types() with int");
}

bool Specie::isOfType(int typeNo)
{
    return ((firstType().value() == typeNo) 
        || (secondType().value() == typeNo));
}

int Specie::catchRate()
{
    return m_catchRate;
}

void Specie::catchRate(int rate)
{
    m_catchRate = rate;
}

int Specie::baseExp()
{
    return m_baseExp;
}

void Specie::baseExp(int val)
{
    m_baseExp = val;
}

int Specie::expAt100()
{
    return m_expAt100;
}

void Specie::expAt100(int val)
{
    m_expAt100 = val;
}

vector<pair<int, int>> Specie::EVGiven()
{
    return m_EVGiven;
}

void Specie::EVGiven(vector<pair<int, int>>  value)
{
    m_EVGiven = value;
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