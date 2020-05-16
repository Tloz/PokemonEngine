#ifndef SAVAGEPOKEMON_H_
#define SAVAGEPOKEMON_H_

#include "pokemon.h"

class SavagePokemon : public Pokemon
{
private:


protected:



public:
    SavagePokemon();
    SavagePokemon(vector<vector<string> > specieTokens, int level);
    SavagePokemon(vector<vector<string> > specieTokens, vector<vector<string> > pokeTokens);
    ~SavagePokemon();
    void print();

    int catchRate();
    bool determineShinyness();
    float catchBonus();
    
};


#endif