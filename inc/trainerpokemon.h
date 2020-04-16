#ifndef TRAINERPOKEMON_H_
#define TRAINERPOKEMON_H_

#include <string>
#include "pokemon.h"

using namespace std;

class TrainerPokemon : public Pokemon
{
private:
    int m_ballID;
    int m_metLevel;
    string m_metDate;
    string m_metPlace;
    int m_noIDDO;
    int m_noIDDOSecret;


public:
    TrainerPokemon(string fileName);
    TrainerPokemon(SavagePokemon const& pkmn);
    ~TrainerPokemon();

    int ballID();
    void ballID(int id);
    int metLevel();
    void metLevel(int lvl);
    string metDate();
    void metDate(string date);
    string metPlace();
    void metPlace(string place);
    int noIDDO();
    void noIDDO(int DO);
    int noIDDOSecret();
    void noIDDOSecret(int DOS);

};

#endif