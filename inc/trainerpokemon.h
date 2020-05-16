#ifndef TRAINERPOKEMON_H_
#define TRAINERPOKEMON_H_

#include <string>
#include "pokemon.h"
#include "parser.h"

using namespace std;

class TrainerPokemon : public Pokemon
{
private:
    int m_ballID;
    int m_metLevel;
    string m_nameDO;
    string m_metDate;
    string m_metPlace;
    int m_noIDDO;
    int m_noIDDOSecret;


public:
    TrainerPokemon();
    TrainerPokemon(vector<vector<string> > specieTokens, vector<vector<string> > pokeTokens);
    ~TrainerPokemon();
    void print();
    string name();
    void name(string newName);
    string fileName(string sep = "%");
    vector<vector<string>> tokens();
    int ballID();
    void ballID(int id);
    int metLevel();
    void metLevel(int lvl);
    string nameDO();
    void nameDO(string name);
    string metDate(bool nice = true);
    void metDate(string date, bool nice = false);
    string metPlace();
    void metPlace(string place);
    int noIDDO();
    void noIDDO(int DO);
    int noIDDOSecret();
    void noIDDOSecret(int DOS);

};

#endif