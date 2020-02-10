#ifndef TRAINERPOKEMON_H_
#define TRAINERPOKEMON_H_

#include <string>
#include <ctime>
#include "pokemon.h"

using namespace std;

class TrainerPokemon : public Pokemon
{
private:
    int m_ballID;
    int m_metLevel;
    time_t m_metDate;
    string m_metPlace;


public:

}

#endif