#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H

#include "move.h"
#include "knownmove.h"
#include <string>

#include "factories.h"

class MoveFactory
{

private:

public:
    MoveFactory();
    ~MoveFactory();
    
    static Move createMove(int moveID);
    static KnownMove createKnownMove(int moveID, int current = 0, int max = 0);
};


#endif