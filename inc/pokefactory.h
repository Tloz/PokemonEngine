#ifndef POKEFACTORY_H
#define POKEFACTORY_H

#include "parser.h"
#include "specie.h"
#include "savagepokemon.h"
#include "trainerpokemon.h"
#include <string>

#include "factories.h"

namespace PokeFactory
{

    Specie createSpecie(int id, int variantID = 0);
    SavagePokemon createSavagePokemon(int id, int level, int variantID = 0);
    SavagePokemon createUniqueSavagePokemon(string fileName);
    TrainerPokemon createTrainerPokemon(string identifier);
    void saveTrainerPokemon(TrainerPokemon *pkmn);
}


#endif
