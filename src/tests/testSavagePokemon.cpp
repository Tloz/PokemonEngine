#include "../../inc/savagepokemon.h"
#include "../../inc/pokefactory.h"
#include "../../inc/world.h"

int main(int argc, char const *argv[])
{
    int id = 4;
    int level = 15;
    if(argc == 2)
    {
        id = atoi(argv[1]);
    }
    if(argc == 3)
    {
        id = atoi(argv[1]);
        level = atoi(argv[2]);
    }

    srand(time(NULL));
    SavagePokemon s = PokeFactory::createSavagePokemon(id, level);
    s.print();
    return 0;
}