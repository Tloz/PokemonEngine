#include "../../inc/trainerpokemon.h"
#include "../../inc/pokefactory.h"
#include <vector>

int main()
{
    TrainerPokemon p = PokeFactory::createTrainerPokemon("temp");
    p.print();
    PokeFactory::saveTrainerPokemon(&p);
    return 0;
}