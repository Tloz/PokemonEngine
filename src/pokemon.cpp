#include "../inc/pokemon.h"

Pokemon::Pokemon()
{

}

int Pokemon::specieID()
{
    return m_specieID;
}

string Pokemon::name()
{
    if(m_name.size() == 0)
        throw EmptyNameException();
    return m_name;
}
 // specieName or nickname
void Pokemon::name(string newName)
{
    if(newName.size() == 0)
        throw EmptyNameException();
    m_name = newName;
}

Gender Pokemon::gender()
{
    if((m_gender < Gender::None) || (m_gender > Gender::Female) )
        throw UnknownGenderException();
    return m_gender;
}

void Pokemon::gender(Gender newGender)
{
    if((m_gender != Gender::None) && (m_gender != Gender::Male) && (m_gender != Gender::Female))
        throw UnknownGenderException();
    m_gender = newGender;
}


// Type* Pokemon::type()
// {
//     if((m_type == NULL) || (m_type[0] == Type(NULL)))
//         throw NoTypeException();
//     return m_type;
// }

// void Pokemon::type(Type type[2])
// {
//     if (type[0] == Type(NULL))
//         throw NoTypeException();
//     m_type[0] = type[0];
//     if (type[1] != Type(NULL))
//         m_type[1] = type[1];
// }


int Pokemon::level()
{
    
}
 // [1-> 100]
void Pokemon::setLevel(int newLevel)
{
    if(newLevel <= LEVEL_MIN)
        m_level = LEVEL_MIN;
    else if(newLevel >= LEVEL_MAX)
        m_level = LEVEL_MAX;
    else
        m_level = newLevel;
}

void Pokemon::addLevel(int ammount)
{
    // Make sure  we ADD levels, must be positive
    if(ammount <0)
        ammount = -ammount;

    // Don't add too much level
    int threshold = LEVEL_MAX - m_level;
    if (ammount > threshold)
        m_level += threshold;
    else
        m_level += ammount;
}

void Pokemon::removeLevel(int ammount)
{
    // Make sure we REMOVE levels, must be positive
    if(ammount < 0)
        ammount = -ammount;

    // Don't remove too much level
    if((m_level - ammount) < LEVEL_MIN)
        m_level = LEVEL_MIN;
    else
        m_level -= ammount;
}
/*
int Pokemon::px()
{
    
}

void Pokemon::setPX(int newAmmount)
{
    
}

void Pokemon::addPX(int ammount)
{
    
}

void Pokemon::removePX(int ammount)
{
    
}
*/
int Pokemon::personalityValue()
{
    // From 0 to 4 294 967 295
    return m_personalityValue;
}
int Pokemon::DOID()
{
    return m_DOID;
}

string Pokemon::DOName()
{
    if (m_DOName.size() == 0)
        throw exception();
    return m_DOName;
}

int Pokemon::DOSecretID()
{
    return m_DOSecretID;
}


int Pokemon::LP()
{
    if(m_currentLP < 0)
        m_currentLP = 0;
    if(m_currentLP > m_stats[0])
        m_currentLP = m_stats[0];

    return m_currentLP;
}
 // [0 -> m_stats[0]]
void Pokemon::setLP(int ammount)
{
    if(ammount <= 0)
        m_currentLP = 0;
    else if (ammount > m_stats[0])
        m_currentLP = m_stats[0];
}

void Pokemon::addLP(int ammount)
{
    if(ammount < 0)
        ammount = -ammount;

    m_currentLP += ammount;
    
    if(m_currentLP  > m_stats[0])
        m_currentLP = m_stats[0];
    else if(m_currentLP < 0)
        m_currentLP = ammount;
}

void Pokemon::removeLP(int ammount)
{
    if(ammount < 0)
        ammount = -ammount;

    if(m_currentLP > m_stats[0])
        m_currentLP = m_stats[0];
    m_currentLP -= ammount;
    if(m_currentLP < 0)
        m_currentLP = 0;

}

int* Pokemon::stats()
{
    return m_stats;
}

int Pokemon::maxLP()
{
    return m_stats[0];
}

int Pokemon::atk()
{
    return m_stats[1];
}

int Pokemon::def()
{
    return m_stats[2];
}

int Pokemon::speAtk()
{
    return m_stats[3];
}

int Pokemon::speDef()
{
    return m_stats[4];
}

int Pokemon::speed()
{
    return m_stats[5];
}

int* Pokemon::IV()
{
    return m_IV;
}

int Pokemon::IV(int index)
{
    if((index < 0) || (index > 5))
        throw exception();
    return m_IV[index];
}

void Pokemon::setIV(int index, int newAmmount)
{
    if((index < 0) || (index > 5))
        throw exception();
    if(newAmmount > IV_MAX)
        throw exception();
    m_IV[index] = newAmmount;
}

void Pokemon::addIV(int index, int ammount)
{
    if(ammount < 0)
        ammount = -ammount;
    if((index < 0) || (index > 5))
        throw exception();
    int threshold = IV_MAX - m_IV[index];
    if(ammount > threshold)
        ammount = threshold;
    m_IV[index] += ammount;
}

void Pokemon::removeIV(int index, int ammount)
{
    if(ammount < 0)
        ammount = -ammount;
    if((index < 0) || (index
     > 5))
        throw exception();
    
    if((m_IV[index] - ammount) < IV_MIN)
        m_IV[index] = IV_MIN;
    else
        m_IV[index] -= ammount;
}

int* Pokemon::EV()
{
    return m_EV;
}

int Pokemon::EV(int index)
{
    if((index < 0) || (index > 5))
        throw exception();
    return m_EV[index];
}

int Pokemon::totalEV()
{
    int EVs = 0;
    for (int i = 0; i < 6; ++i)
    {
        EVs += m_EV[i];
    }
    return EVs;
}

void Pokemon::setEV(int index, int newAmmount)
{
    
    if((index < 0) || (index > 5))
        throw exception();

    if (newAmmount < 0)
        newAmmount = -newAmmount;

    if (newAmmount > EV_MAX_LOCAL)
        newAmmount = EV_MAX_LOCAL;

    if((totalEV() + newAmmount) > EV_MAX_GLOBAL)
        newAmmount = EV_MAX_GLOBAL - totalEV();

    m_EV[index] = newAmmount;
}

void Pokemon::addEV(int index, int ammount)
{
    if((index < 0) || (index > 5))
        throw exception();

    if (ammount < 0)
        ammount = -ammount;

    int t1 = EV_MAX_LOCAL - m_EV[index];
    int t2 = EV_MAX_GLOBAL - m_EV[index];
    int threshold = min(t1, t2);
    if(ammount > threshold)
        ammount = threshold;

    m_EV[index] += ammount;
}

void Pokemon::removeEV(int index, int ammount)
{
    if((index < 0) || (index > 5))
        throw exception();

    if (ammount < 0)
        ammount = -ammount;

    if(ammount >= m_EV[index])
        m_EV[index] = 0;
    else
        m_EV[index] -= ammount;
}


/* TODO: remove comment
Move* Pokemon::moves()
*/

string Pokemon::toString()
{
    return "";
}