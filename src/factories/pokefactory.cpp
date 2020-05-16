#include "../../inc/pokefactory.h"
#include "../../inc/parser.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Specie PokeFactory::createSpecie(int id, int variantID)
{
    // On accède au dossier des espèces
    string fileName = RESSOURCES_FOLDER;
    fileName += SPECIES_FOLDER;

    // On ajoute des 0 de padding pour avoir le bon nom de fichier
    std::stringstream ss;
    ss << std::setw(POKE_FILE_NAME_PAD_UNIT) << std::setfill('0') << id;
    fileName += ss.str();

    // On ajoute au besoin la forme
    if(variantID != 0)
        fileName += "-" + to_string(variantID);

    // On ajoute l'extension
    fileName += SPECIE_EXT;
    
    Specie retSpecie;
    try
    {
        vector<vector<string>> tokens = getTokensFromFile(fileName);
        retSpecie = Specie(tokens);
    }
    catch(exception const& e)
    {
        throw;
    }
    return retSpecie;
}

SavagePokemon PokeFactory::createUniqueSavagePokemon(string fileName)
{
    string filePoke = RESSOURCES_FOLDER;
    filePoke += SAVAGE_POKE_FOLDER;
    filePoke += fileName;
    filePoke += SAVAGE_POKE_EXT;

    int specieID = 0;
    int variantID = 0;
    bool found1 = false;
    bool found2 = false;

    vector<vector<string>> tokens = getTokensFromFile(filePoke);
    for(auto token:tokens)
    {
        if(token[0] == "SpecieID")
            {
                found1 = true;
                specieID = stoi(token[1]);
            }
            if(token[0] == "VariantID")
            {
                found2 = true;
                variantID = stoi(token[1]);
            }
    }
    if(!(found1 && found2))
    {
        string s = "Unable to find specie in ";
        s += filePoke;
        throw runtime_error(s);
    }

    string fileSpecie = RESSOURCES_FOLDER;
    fileSpecie += SPECIES_FOLDER;

    // On ajoute des 0 de padding pour avoir le bon nom de fichier
    std::stringstream ss;
    ss << std::setw(POKE_FILE_NAME_PAD_UNIT) << std::setfill('0') << specieID;
    fileSpecie += ss.str();

    // On ajoute au besoin la forme
    if(variantID != 0)
        fileSpecie += "-" + to_string(variantID);

    // On ajoute l'extension
    fileSpecie += SPECIE_EXT;

    SavagePokemon retSPKMN;
    try
    {
        retSPKMN = SavagePokemon(getTokensFromFile(fileSpecie), tokens);
    }
    catch(exception const& e)
    {
        throw;
    }
    return retSPKMN;
}

SavagePokemon PokeFactory::createSavagePokemon(int id, int level, int variantID)
{
    // On accède au dossier des espèces
    string fileName = RESSOURCES_FOLDER;
    fileName += SPECIES_FOLDER;
    // On ajoute des 0 de padding pour avoir le bon nom de fichier
    std::stringstream ss;
    ss << std::setw(POKE_FILE_NAME_PAD_UNIT) << std::setfill('0') << id;
    fileName += ss.str();
    // On ajoute au besoin la forme
    if(variantID != 0)
        fileName += "-" + to_string(variantID);
    // On ajoute l'extension
    fileName += SPECIE_EXT;

    SavagePokemon retPKMN;
    try
    {
        retPKMN = SavagePokemon(getTokensFromFile(fileName), level);
    }
    catch(exception const& e)
    {
        throw;
    }
    return retPKMN;
}

TrainerPokemon PokeFactory::createTrainerPokemon(string identifier)
{
    string filePoke = RESSOURCES_FOLDER;
    filePoke += TRAINER_POKE_FOLDER;
    filePoke += identifier;
    filePoke += TRAINER_POKE_EXT;

    int specieID = 0;
    int variantID = 0;
    bool found1 = false;
    bool found2 = false;

    vector<vector<string>> tokens = getTokensFromFile(filePoke);
    for(auto token:tokens)
    {
        if(token[0] == "SpecieID")
            {
                found1 = true;
                specieID = stoi(token[1]);
            }
            if(token[0] == "VariantID")
            {
                found2 = true;
                variantID = stoi(token[1]);
            }
    }
    if(!(found1 && found2))
    {
        string s = "Unable to find specie in ";
        s += filePoke;
        throw runtime_error(s);
    }

    string fileSpecie = RESSOURCES_FOLDER;
    fileSpecie += SPECIES_FOLDER;
    // On ajoute des 0 de padding pour avoir le bon nom de fichier
    std::stringstream ss;
    ss << std::setw(POKE_FILE_NAME_PAD_UNIT) << std::setfill('0') << specieID;
    fileSpecie += ss.str();
    // On ajoute au besoin la forme
    if(variantID != 0)
        fileSpecie += "-" + to_string(variantID);
    // On ajoute l'extension
    fileSpecie += SPECIE_EXT;

    TrainerPokemon retPKMN;
    try
    {
        retPKMN = TrainerPokemon(getTokensFromFile(fileSpecie), tokens);
    }
    catch(exception const& e)
    {
        throw;
    }
    return retPKMN;
}

void PokeFactory:: saveTrainerPokemon(TrainerPokemon *pkmn)
{
    string filePoke = RESSOURCES_FOLDER;
    filePoke += TRAINER_POKE_FOLDER;
    filePoke += pkmn->fileName();
    filePoke += TRAINER_POKE_EXT;
    try
    {
        writeTokensToFile(pkmn->tokens(), filePoke);
    }
    catch(exception const& e)
    {
        throw;
    }
}