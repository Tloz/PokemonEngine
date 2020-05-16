#include "../../inc/trainerfactory.h"
#include "../../inc/parser.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>

Trainer TrainerFactory::loadPlayer()
{
    string fileName;
    fileName = RESSOURCES_FOLDER;
    fileName += TRAINER_FOLDER;
    fileName += "player";
    fileName += TRAINER_EXT;

    Trainer retval;
    try
    {;
        retval = Trainer(Parser::getTokensFromFile(fileName));
    }
    catch(exception const& e)
    {
        throw;
    }
    return retval;
}

Trainer TrainerFactory::readTrainer(string identifier)
{
    string fileName;
    fileName = RESSOURCES_FOLDER;
    fileName += TRAINER_FOLDER;
    fileName += identifier;
    fileName += TRAINER_EXT;

    Trainer retval;
    try
    {
        retval = Trainer(Parser::getTokensFromFile(fileName));
    }
    catch(exception const& e)
    {
        throw;
    }
    return retval;
}