#ifndef SAVAGEPOKEMON_H_
#define SAVAGEPOKEMON_H_

#include "pokemon.h"

class SavagePokemon : public Pokemon
{
private:


protected:



public:
    SavagePokemon(int id, int variant, int level);
    ~SavagePokemon();

    int catchRate();
    bool determineShinyness();
    
};


#endif