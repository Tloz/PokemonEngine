#include "../inc/move.h"

string targetClassName(TargetClass t)
{
    // switch()
    // {
    //     case :

    //         break;

    //     case :

    //         break;

    //     default:
    //         break;
    // }
    return "UnDeTeRmInEd";
}
string catName(Cat category)
{
    switch(category)
    {
        case Cat::Physical:
            return "Physical";
            break;

        case Cat::Special:
            return "Special";
            break;

        case Cat::Status:
            return "Status";
            break;

        default:
            return "uDeTeRmInEd";
            break;
    }
}
Move::Move(int ID, string name, Type_t type, int power, int pre, Cat cat, int pp)
{
    m_moveID = ID;
    m_name = name;
    m_power = power;
    m_precision = pre;
    m_type = new Type(type);
    m_category = cat;
    m_ppBase = pp;
}

Move::Move(int ID, string name, int power, int pre, Type_t type, Cat cat, int prio, int pp, int critLevel, int scare, TargetClass tg, bool dir)
{
    m_moveID = ID;
    m_name = name;
    m_power = power;
    m_precision = pre;
    m_type = new Type(type);
    m_category = cat;
    m_priority = prio;
    m_ppBase = pp;
    m_criticalLevel = critLevel;
    m_scareRate = scare;
    m_target = tg;
    m_direct = dir;
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
    return m_direct;
}

int Move::criticalLevel()
{
    return m_criticalLevel;
}

float Move::criticalRate()
{
    int tab[4] = {24, 8, 2, 1};
    return 1.0 / tab[m_criticalLevel - 1];
}

int Move::scareRate()
{
    if(m_scareRate < 0)
        m_scareRate = 0;
    else if(m_scareRate > 100)
        m_scareRate = 100;
    return m_scareRate;
}

TargetClass Move::target()
{
    return m_target;
}

array<bool, 4> Move::affectedBy()
{
    return m_affectedBy;
}

bool Move::affectedBy(int index)
{
    if((index >= 0) && (index <= 3))
    {
        return m_affectedBy[index];
    }
    else
        throw exception();
}


bool Move::affectedByProtectAndDetect()
{
    return affectedBy(0);
}

bool Move::affectedBySnatch()
{
    return affectedBy(1);
}

bool Move::affectedByMagicCoatOrMagicBounce()
{
    return affectedBy(2);
}

bool Move::affectedByBrightPowder()
{
    return affectedBy(3);
}

bool Move::affectedByKingsRock()
{
    // N'est affectée que si l'attaque a un scareRate de 0
    return (scareRate() == 0);
}

bool Move::isPowder()
{
    return m_isPowder;
}