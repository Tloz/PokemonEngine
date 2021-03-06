#include <math.h>
#include <fstream>
#include "../inc/pokemon.h"
#include "../inc/movefactory.h"

Pokemon::Pokemon() : Specie()
{

}

Pokemon::Pokemon(vector<vector<string>> tokensVector) : Specie(tokensVector)
{
    
}

Pokemon::~Pokemon()
{

}

void Pokemon::print()
{

}

string Pokemon::name()
{
    return m_specieName;
}

void Pokemon::name(string newName)
{
    if(newName.size() > 0)
        m_name = newName;
}

string Pokemon::origin()
{
    return m_origin;
}

void Pokemon::origin(string newOrigin)
{
    m_origin = newOrigin;
}

Gender Pokemon::gender()
{
    if((m_gender != Gender::None) && (m_gender != Gender::Female) && (m_gender != Gender::Male) )
    {
        throw invalid_argument("in Pokemon.gender()");
    }
    return m_gender;
}

void Pokemon::gender(Gender newGender)
{
    if((m_gender != Gender::None) && (m_gender != Gender::Male) && (m_gender != Gender::Female))
        throw invalid_argument("in Pokemon.gender(newGender)");
    m_gender = newGender;
}

int Pokemon::level()
{
    if(m_level < LEVEL_MIN)
        m_level = LEVEL_MIN;
    else if(m_level > LEVEL_MAX)
        m_level = LEVEL_MAX;
    return m_level;
}

void Pokemon::setLevel(int newLevel)
{
    if(newLevel <= LEVEL_MIN)
        m_level = LEVEL_MIN;
    else if(newLevel >= LEVEL_MAX)
        m_level = LEVEL_MAX;
    else
        m_level = newLevel;
    computeStats();
}

void Pokemon::levelUp()
{
    addLevel(1);
}

void Pokemon::addLevel(int ammount)
{
    // Make sure  we ADD levels, must be positive
    if(ammount < 0)
        ammount = -ammount;
    // Don't add too much level
    int threshold = LEVEL_MAX - m_level;
    if (ammount > threshold)
        m_level += threshold;
    else
        m_level += ammount;

    /* TODO: Implement evolution system
    // Get all evolutions that triggers by level 
    // and checks them. Evolves the first one that can
    vector<Evolution*> targets = evolveWith(EvolutionTrigger::LevelUp);
    if(targets.size() != 0)
    {
        for (unsigned int i = 0; i < targets.size(); ++i)
        {
            Evolution* target = targets.at(i);
            if(meetAllConditions(target))
            {
                evolve(target->who()->specieID(), target->who()->variant());
                break;
            }
        }
    }
    */
    // Update stats
    computeStats();
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
    computeStats();
}

int Pokemon::px()
{
    if(m_px > m_expAt100)
        m_px = m_expAt100;
    return m_px;
}
/*
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
PersonalityValue Pokemon::ipv()
{
    // From 0 to 4 294 967 295
    return m_ipv;
}

int Pokemon::LP()
{
    int threshold = maxLP();
    if(m_currentLP < 0)
        m_currentLP = 0;
    if(m_currentLP > threshold)
        m_currentLP = threshold;
    return m_currentLP;
}
 // [0 -> m_stats[0]]
void Pokemon::setLP(int ammount)
{
    const int threshold = maxLP();
    if(ammount <= 0)
        m_currentLP = 0;
    else if (ammount > threshold)
        m_currentLP = threshold;
    else
        m_currentLP = ammount;
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

void Pokemon::setLPToMax()
{
    m_currentLP = maxLP();
}

array<int, 6> Pokemon::stats()
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

array<int, 6> Pokemon::IVs()
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
    computeStat(index);
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
    computeStat(index);
}

void Pokemon::removeIV(int index, int ammount)
{
    if(ammount < 0)
        ammount = -ammount;
    if((index < 0) || (index > 5))
        throw exception();
    
    if((m_IV[index] - ammount) < IV_MIN)
        m_IV[index] = IV_MIN;
    else
        m_IV[index] -= ammount;
    computeStat(index);
}

array<int, 6> Pokemon::EVs()
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
    computeStat(index);
}

void Pokemon::addEV(int index, int ammount)
{
    if((index < 0) || (index > 5))
        throw exception();
    if (ammount < 0)
        ammount =- ammount;
    int t1 = EV_MAX_LOCAL - m_EV[index];
    int t2 = EV_MAX_GLOBAL - m_EV[index];
    int threshold = min(t1, t2);
    if(ammount > threshold)
        ammount = threshold;
    m_EV[index] += ammount;
    computeStat(index);
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
    computeStat(index);
}

void Pokemon::computeMaxLP()
{
    computeStat(0);
}

void Pokemon::computeAtk()
{
    computeStat(1);
}

void Pokemon::computeDef()
{
    computeStat(2);
}

void Pokemon::computeSpeAtk()
{
    computeStat(3);
}

void Pokemon::computeSpeDef()
{
    computeStat(4);
}

void Pokemon::computeSpeed()
{
    computeStat(5);
}

void Pokemon::computeStat(int index)
{
    if((index < 0) || (index > 5))
        throw exception();
    float val = 2.0;
    val *= m_baseStats[index];
    val += m_IV[index];
    val += floor(m_EV[index] / 4.0);
    val *= m_level;
    val = floor(val / 100.0);
    if(index == 0)
    {
        val += m_level;
        val += 10;
    }
    else
    {
        val += 5;
        /* TODO: When nature is implemented
        val *= natureModifier(index);
        */
    }

    m_stats[index] = int(val);
}

void Pokemon::computeStats()
{
    for (int i = 0; i < 6; ++i)
    {
        computeStat(i);
    }
}

// Si une des conditions n'est pas remplie, renvoie false
// Sinon, renvoie true
/*
bool Pokemon::meetAllConditions(Evolution* evo)
{
    vector<pair<EvolutionCondition, EvolutionValue>> cond = evo->conditions();
    for (unsigned int i = 0; i < cond.size(); ++i)
    {
        switch(int(cond.at(i).first))
        {
            case int(EvolutionCondition::MinLevel):
            if(cond.at(i).second.getInt() >= m_level)
                return true;
            break;

            case int(EvolutionCondition::Item):
            //do something
            break;

            case int(EvolutionCondition::HeldItem):
            //do something
            break;

            case int(EvolutionCondition::MinHappiness):
            //do something
            break;

            case int(EvolutionCondition::TimeOfDay): // can be Day or Nigh
            //do something
            break;
            
            case int(EvolutionCondition::Gender):
            //do something
            break;

            case int(EvolutionCondition::MinBeauty):
            //do something
            break;

            case int(EvolutionCondition::RelativePhysicalStats):
            //do something
            break;

            case int(EvolutionCondition::Location):
            //do something
            break;

            case int(EvolutionCondition::KnownMove):
            //do something
            break;

            case int(EvolutionCondition::KnownMoveType):
            //do something
            break;

            case int(EvolutionCondition::PartySpecies):
            //do something
            break;

            case int(EvolutionCondition::PartyType):
            //do something
            break;

            case int(EvolutionCondition::OverworldWeather):
            //do something
            break;

            case int(EvolutionCondition::TradeSpecies):
            //do something
            break;

            case int(EvolutionCondition::TurnUpsideDown):
            //do something
            break;
            
            case int(EvolutionCondition::None):
            default:
            //do something
            break;
        }
    }
    return false;
}
*/


vector<KnownMove> Pokemon::moves()
{
    return m_moves;
}

void Pokemon::addMove(int moveID, int cur, int max)
{
    m_moves.push_back(MoveFactory::createKnownMove(moveID, cur, max));
}

void Pokemon::setMove(int moveID, int where)
{
    if((where < 0) || (where > 4))
        throw exception();
    m_moves[where] = MoveFactory::createKnownMove(moveID);
}

void Pokemon::setMove(int moveID, int where, int cur, int max)
{
    if((where < 0) || (where > 4))
        throw exception();
    m_moves[where] = MoveFactory::createKnownMove(moveID, cur, max);
}



void Pokemon::eraseMove(int where)
{
    if((where < 0) || (where > 4))
        throw exception();
    m_moves[where] = KnownMove();
}

NonVolatileStatus_t Pokemon::status()
{
    return m_status;
}

VolatileStatus_t Pokemon::condition()
{
    return m_condition;
}

VolatileBattleStatus_t Pokemon::BattleStatus()
{
    return m_battleStatus;
}

void Pokemon::status(NonVolatileStatus_t status)
{
    m_status = status;
}

void Pokemon::condition(VolatileStatus_t condition)
{
    m_condition = condition;
}

void Pokemon::battleStatus(VolatileBattleStatus_t battleStatus)
{
    m_battleStatus = battleStatus;
}

// void Pokemon::evolve(int specie, int variant)
// {

// }

