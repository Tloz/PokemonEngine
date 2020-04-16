#include "../inc/savagepokemon.h"
#include "../inc/trainer.h"

SavagePokemon::SavagePokemon(int id, int variant, int level) : Pokemon(id, variant)
{

    m_gender = determineGender(genderBalance(), ipv().valueForGender());

    // check level and sets it
    if(level > 100)
        m_level = 100;
    else if(level < 0)
        m_level = 0;
    else
        m_level = level;

    // give a random number of IVs and no EV
    for (int i = 0; i < 6; ++i)
    {
        m_IV[i] = randFloatInRange(0, 31);
        m_EV[i] = 0;
    }
    computeStats();
}



SavagePokemon::~SavagePokemon()
{

}

int SavagePokemon::catchRate()
{
    return m_catchRate;
}

bool SavagePokemon::determineShinyness()
{
    unsigned int p1 = (ipv().valueForShiny1() xor ipv().valueForShiny2());
    unsigned int p2 = ( Trainer::DO xor Trainer::DO_Secret);
    if ((p1 xor p2) < 8)
        return true;
    return false;
}