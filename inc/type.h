#ifndef TYPE_H_
#define TYPE_H_
#include <iostream>
#include <tuple>

using namespace std;

enum class Type
{
    Dark,
    Dragon,
    Electric,
    Fairy,
    Fight,
    Fire,
    Floor,
    Fly,
    Ghost,
    Grass,
    Ice,
    Insect,
    Normal,
    Poison,
    Psy,
    Rock,
    Steel,
    Water
};

float efficiency(Type attackType, Type defenseType);
string efficiency_text_debug(Type attackType, Type defenseType);






#endif  /* !TYPE_H_ */