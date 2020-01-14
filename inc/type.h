#ifndef TYPE_H_
#define TYPE_H_
#include <iostream>
#include <string>
#include <array>

using namespace std;
static float efficiencyTab[19][19] = 
    {
     {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0},
     {1.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0},
     {1.0, 1.0, 2.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5},
     {1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0},
     {1.0, 0.5, 0.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0},
     {1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0},
     {1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 0.5, 0.5, 1.0, 1.0, 1.0, 2.0, 0.5, 2.0},
     {1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 0.5, 1.0, 2.0},
     {1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.0, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0},
     {1.0, 2.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0},
     {1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 2.0, 0.5, 2.0, 1.0, 0.5, 2.0, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5},
     {1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0},
     {1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0},
     {1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0},
     {1.0, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 0.5, 1.0, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0},
     {1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0},
     {1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 2.0, 0.5, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 2.0, 2.0},
     {1.0, 1.0, 0.5, 1.0, 0.5, 2.0, 2.0, 2.0, 0.5, 1.0, 0.5, 0.5, 0.5, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0},
     {1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.5}
    };
    
enum Type_t
{
    None,
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

bool isTypeNumberValid(int number);

class Type
{
private:
    Type_t m_value;

public:
    Type(Type_t value);
    Type(int value);
    ~Type();
    Type_t value();
    bool isTouchingFloor();
    bool canBePoisoned();
    bool canBeParalysed();
    bool canBeBurned();
    bool canBeFrozen();
    bool immuneToPowder();
    bool canBeLeeched();
    float multWhenHitBy(Type_t what);

    
};

// class Type
// {
// private:

//     string m_typeNames[18] = {string("Ténèbres"), string("Dragon"), string("Électrik"), string("Fée"), string("Combat"), string("Feu"), 
//          string("Sol"), string("Vol"), string("Spectre"), string("Plante"), string("Glace"), string("Insecte"), 
//          string("Normal"), string("Poison"), string("Psy"), string("Roche"), string("Acier"), string("Eau")};

//     static std::string* names();
//     static float** efficiency_values();
//     static float efficiency(int attackType, int defenseType);
//     static float efficiency_text_debug(int attackType, int defenseType);
// };


#endif  /* !TYPE_H_ */