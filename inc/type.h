#ifndef TYPE_H_
#define TYPE_H_
#include <iostream>
#include <string>
#include <array>

using namespace std;
static float efficiencyTab[19][19] = // Whatever you do, DO NOT MESS WITH THAT !!!
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

bool isTypeNumberValid(int number); // checks that given number is between 0(included) and 18 (excluded)

class Type
{
private:
    Type_t m_value;

public:
    Type();
    Type(Type_t value);
    Type(int value);
    ~Type();
    string name();
    Type_t value();
    
    float multWhenHitBy(Type_t what);
    static Type* getType(Type_t value);
    static Type* getType(int value);

    bool isTouchingFloor();
    bool canBePoisoned();
    bool canBeParalysed();
    bool canBeBurned();
    bool canBeFrozen();
    bool immuneToPowder();
    bool canBeLeeched();
    

    
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