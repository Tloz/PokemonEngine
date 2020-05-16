#include "../inc/move.h"
#include "../inc/parser.h"
#include "../inc/typefactory.h"
#include <vector>
#include <iomanip>
#include <fstream>

Move::Move()
{
    m_name = "Lutte";
    m_power = 50;
    m_precision = 100;
}

Move::Move(vector<vector<string>> moveTokens)
{
    bool verbose = false;
    vector<string> unsedTokens;
    for(auto tokens:moveTokens)
    {
        if(tokens[0] == "ID")
        {
            m_moveID = stoi(tokens[1]);
        }
        else if(tokens[0] == "Name")
        {
            m_name = tokens[1];
        }
        else if(tokens[0] == "Pow")
        {
            m_power = stoi(tokens[1]);
        }
        else if(tokens[0] == "Pre")
        {
            m_precision = stoi(tokens[1]);
        }
        else if(tokens[0] == "PPBase")
        {
            m_ppBase = stoi(tokens[1]);
        }
        else if(tokens[0] == "Type")
        {
            m_type = TypeFactory::createType(stoi(tokens[1]));
        }
        else if(tokens[0] == "Category")
        {
            m_category = Cat(stoi(tokens[1]));
        }
        else if(tokens[0] == "TargetClass")
        {
            m_target = TargetClass(stoi(tokens[1]));
        }
        else if(tokens[0] == "Direct")
        {
            m_direct = stoi(tokens[1]);
        }
        else if(tokens[0] == "Priority")
        {
            m_priority = stoi(tokens[1]);
        }
        else if(tokens[0] == "CritRate")
        {
             m_criticalLevel = stoi(tokens[1]);
        }
        else if(tokens[0] == "scareRate")
        {
            m_scareRate = stoi(tokens[1]);
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

Move::~Move()
{

}

void Move::print()
{
    cout << "Attaque " << name() << " (PPbase/PPMax: " << ppBase() << "/" << ppMax() << ")" << endl;
    cout << "Puissance: " << power() << " Précision: " << precision() << endl;
    cout <<"Type: " << type().name() << " Categorie: " << catName() << endl;
}



int Move::moveID()
{
    if(m_moveID < 0)
        m_moveID = 0;
    return m_moveID;
}

string Move::name()
{
    if(m_name.length() == 0)
        m_name = "Attaque sans nom";
    return m_name;
}

int Move::power()
{
    if(m_power < 0)
        m_power = 10;
    return m_power;
}

int Move::precision()
{
    if(m_precision < 0)
        m_precision = 50;
    return m_precision;
}

Type Move::type()
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

string Move::targetClassName()
{
    switch(TargetClass())
    {
        case Self:
            return "Soi-même";
        case AnyFoe:
            return "Un adversaire";
        case AnyTeam:
            return "Un équipier";
        case AnyAdj:
            return "Une cible adjacente";
        case AdjFoe:
            return "Un adversaire adjacent";
        case AdjTeam:
            return "Un équipier adjacent";
        case AllButSelf:
            return "Tout le monde sauf le lanceur";
        case All:
            return "Tout le monde";
        case NoTarget:
        default:
            return "Aucune cible";
    }
}

string Move::catName()
{
    switch(category())
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