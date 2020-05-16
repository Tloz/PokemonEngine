#include "../../inc/type.h"

Type::Type()
{
    m_value = 0;
    m_name = "None";
}

Type::Type(vector<vector<string>> tokens)
{
    bool verbose = false;
    vector<string> unsedTokens;
    for(auto token:tokens)
    {
        // Name, TypeID, IsStrongVS, IsWeakVS, NoEffectOn, NoEffectFrom
        if(token[0] == "Name")
        {
            name(token[1]);
        }
        else if(token[0] == "TypeID")
        {
            value(stoi(token[1]));
        }
        else
        {
            unsedTokens.push_back(token[0]);
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

Type::~Type()
{

}

void Type::print()
{
    cout << "Type " << value() << " (" << name() << ")" << endl;
}

string Type::name()
{
    return m_name;
}

void Type::name(string newName)
{
    m_name = newName;
}

int Type::value()
{
    return m_value;
}

void Type::value(int newVal)
{
    if(!Type::isNumberValid(newVal))
    {
        m_value = 0;
    }
    else
    {
        m_value = newVal;
    }
}

// checks that given number is between 0 and 18 (included)
bool Type::isNumberValid(int number)
{
    return (number >= 0) && (number <= 18);
}


// bool Type::isTouchingFloor()
// {
//     return m_value != Type_t::Fly;
// }

// bool Type::canBePoisoned()
// {
//     return m_value != Type_t::Poison;
// }

// bool Type::canBeParalysed()
// {
//     return m_value != Type_t::Electric;
// }

// bool Type::canBeBurned()
// {
//     return m_value != Type_t::Fire;
// }

// bool Type::canBeFrozen()
// {
//     return m_value != Type_t::Ice;
// }

// bool Type::immuneToPowder()
// {
//     return m_value != Type_t::Grass;
// }

// bool Type::canBeLeeched()
// {
//     return m_value != Type_t::Grass;
// }
