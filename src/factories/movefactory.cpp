#include "../../inc/movefactory.h"
#include "../../inc/parser.h"
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>

Move MoveFactory::createMove(int moveID)
{
    string fileName = RESSOURCES_FOLDER;
    fileName += MOVES_FOLDER;
    std::stringstream ss;
    ss << std::setw(MOVE_FILE_NAME_PAD_UNIT) << std::setfill('0') << moveID;
    fileName += ss.str();
    fileName += MOVE_EXT;

    Move retval;
    try
    {
        retval = Move(Parser::getTokensFromFile(fileName));
    }
    catch(exception const& e)
    {
        throw;
    }
    return retval;
}

KnownMove MoveFactory::createKnownMove(int moveID, int current, int max)
{
    string fileName = RESSOURCES_FOLDER;
    fileName += MOVES_FOLDER;

    std::stringstream ss;
    ss << std::setw(MOVE_FILE_NAME_PAD_UNIT) << std::setfill('0') << moveID;
    fileName += ss.str();
    fileName += ".move";

    KnownMove kn;
    try
    {
        kn = KnownMove(Parser::getTokensFromFile(fileName), current, max);
    }
    catch(exception const& e)
    {
        throw;
    }
    return kn;
}
