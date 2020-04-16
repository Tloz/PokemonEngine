#include "../trainerpokemon.h"

TrainerPokemon::TrainerPokemon(string fileName)
{

}

TrainerPokemon::TrainerPokemon(SavagePokemon const& pkmn)
{

}

TrainerPokemon::~TrainerPokemon()
{

}

int TrainerPokemon::ballID()
{
    return m_ballID;
}

void TrainerPokemon::ballID(int id)
{
    m_ballID = id;
}

int TrainerPokemon::metLevel()
{
    return m_metLevel;
}

void TrainerPokemon::metLevel(int lvl)
{
    m_metLevel = lvl;
}

string TrainerPokemon::metDate()
{
    return m_metDate;
}

void TrainerPokemon::metDate(string date)
{
    m_metDate = date;
}

string TrainerPokemon::metPlace()
{
    return m_metPlace;
}

void TrainerPokemon::metPlace(string place)
{
    m_metPlace = place;
}

int TrainerPokemon::noIDDO()
{
    return m_noIDDO;
}

void TrainerPokemon::noIDDO(int DO)
{
    m_noIDDO = DO;
}

int TrainerPokemon::noIDDOSecret()
{
    return m_noIDDOSecret;
}

void TrainerPokemon::noIDDOSecret(int DOS)
{
    m_noIDDOSecret = DOS;
}
