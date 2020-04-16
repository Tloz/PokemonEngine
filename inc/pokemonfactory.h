#ifndef POKEMONFACTORY_H
#define POKEMONFACTORY_H

#include "savagepokemon.h"
#include "trainerpokemon.h"
#include <string>

class PokeFactory
{

private:
    // string m_ressourcesFolder = "assets/";
    // string m_speciesFolder = "species/";
public:
    PokeFactory();
    ~PokeFactory();

    // static string ressourcesFolder();
    // static string speciesFolder();
    static Specie createSpecie(int id, int variantID = 0);
    static SavagePokemon createSavagePokemon(int id, int variantID = 0);
    static TrainerPokemon createTrainerPokemon();
    
};


#endif