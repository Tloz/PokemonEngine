#ifndef TYPE_H_
#define TYPE_H_
#include <iostream>
#include <string>
#include <array>

using namespace std;

bool isTypeNumberValid(int number)
{
    return true;
}

bool isTypeTabValid(array<int, 2> types)
{
    return true;
}

float m_efficiency_values[19][19] = 
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


class Type
{
private:

    string m_typeNames[18] = {string("Ténèbres"), string("Dragon"), string("Électrik"), string("Fée"), string("Combat"), string("Feu"), 
         string("Sol"), string("Vol"), string("Spectre"), string("Plante"), string("Glace"), string("Insecte"), 
         string("Normal"), string("Poison"), string("Psy"), string("Roche"), string("Acier"), string("Eau")};

   
public:
    enum class Val
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
    static std::string* names();
    static float** efficiency_values();
    static float efficiency(int attackType, int defenseType);
    static float efficiency_text_debug(int attackType, int defenseType);
};


#endif  /* !TYPE_H_ */