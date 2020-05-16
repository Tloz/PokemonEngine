#ifndef POKEFACTORY_H
#define POKEFACTORY_H

#include "parser.h"
#include "specie.h"
#include "savagepokemon.h"
#include "trainerpokemon.h"
#include <string>

#include "factories.h"

class PokeFactory
{

private:

public:
    PokeFactory();
    ~PokeFactory();

    static Specie createSpecie(int id, int variantID = 0);
    static SavagePokemon createSavagePokemon(int id, int level, int variantID = 0);
    static SavagePokemon createUniqueSavagePokemon(string fileName);
    static TrainerPokemon createTrainerPokemon(string identifier);
    static void saveTrainerPokemon(TrainerPokemon *pkmn);

};


#endif
