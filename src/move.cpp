#include "../inc/move.h"

Move::Move()
{

}

Move::~Move()
{

}

int Move::moveID()
{
    return m_moveID;
}

string Move::name()
{
    return m_name;
}

int Move::power()
{
    return m_power;
}

int Move::precision()
{
    return m_precision;
}

Type* Move::type()
{
    return m_type;
}

Cat Move::category()
{
    return m_category;
}

int Move::priority()
{
    return m_priority;
}

int Move::ppBase()
{
    return m_ppBase;
}

int Move::ppMax()
{
    return ppBase() * 1.6; // add 60%
}

bool Move::contact()
{
    return m_contact;
}

int Move::criticalLevel()
{
    return m_criticalLevel;
}

float Move::criticalRate()
{
    int tab[4] = {24, 8, 2, 1};
    return 1.0 / tab[criticalLevel() - 1];
}

int Move::scareRate()
{
    if(m_scareRate < 0)
        m_scareRate = 0;
    else if(m_scareRate > 100)
        m_scareRate = 100;
    return m_scareRate;
}


bool Move::affectedByProtectAndDetect()
{
    // contient les moveID des attaques qui ne sont pas affectées
    int tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // TODO: inclure le moveID de
    /*
    Boost
    Carnareket
    Conversion2
    Hurlement
    Imitation
    Malédiction
    Morphing
    Possessif
    Prescience
    Requiem
    */
    for (int i = 0; i < 1; ++i)
    {
        if(tab[i] == moveID())
            return false;
    }
    return true;
}

bool Move::affectedBySnatch()
{
    // contient les moveID des attaques qui ne sont pas affectées
    int tab[1] = {0}; // TODO: inclure le moveID de Coupd'main
    for (int i = 0; i < 1; ++i)
    {
        if(tab[i] == moveID())
            return false;
    }
    return true;
}

bool Move::affectedByMagicCoatOrMagicBounce()
{
    // contient les moveID des attaques qui ne sont pas affectées
    int tab[2] = {0, 0}; // TODO: inclure les moveID de danse folle et malédiction
    for (int i = 0; i < 2; ++i)
    {
        if(tab[i] == moveID())
            return false;
    }
    return true;
}

bool Move::affectedByBrightPowder()
{
    return (category() == Cat::Status);
}

bool Move::affectedByKingsRock()
{
    return (scareRate() == 0);
}

bool Move::isPowder()
{
    
    // contient les moveID des attaques qui ne sont pas affectées
    int tab[7] = {0, 0, 0, 0, 0, 0, 0}; // TODO: inclure les moveID de 
    /*
    Nuée de Poudre
    Para-Spore
    Poudre Dodo
    Poudre Fureur
    Poudre Toxik
    Spore
    Spore Coton
    */
    for (int i = 0; i < 2; ++i)
    {
        if(tab[i] == moveID())
            return false;
    }
    return true;
}