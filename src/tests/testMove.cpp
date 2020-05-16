#include "../../inc/move.h"
#include "../../inc/movefactory.h"
#include <iostream>

using namespace std;

int main()
{
    Move m = MoveFactory::createMove(10);
    m.print();
    return 0;
}