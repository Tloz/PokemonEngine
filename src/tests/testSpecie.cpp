#include "../../inc/specie.h"
#include "../../inc/pokefactory.h"
#include <vector>

int main(int argc, char const *argv[])
{
    int id = 4;
    if(argc >= 2)
    {
        id = stoi(argv[1]);
    }

    Specie s = PokeFactory::createSpecie(id);
    s.print();
    return 0;
}