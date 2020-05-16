#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H

#include "move.h"
#include "knownmove.h"
#include <string>

#include "factories.h"

namespace MoveFactory
{    
    Move createMove(int moveID);
    KnownMove createKnownMove(int moveID, int current = 0, int max = 0);
}


#endif