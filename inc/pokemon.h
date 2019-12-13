#ifndef POKEMON_H_
#define POKEMON_H_

#include <iostream>
#include <string>
// #include "ability.h"
#include "move.h"
// #include "object.h"
#include "specie.h"
#include "type.h"

using namespace std;

class Pokemon()
{
private:
    int m_specieID;
    string m_name; // specieName or nickname
    int m_gender; // 0 = none, 1 = male, 2 = female

    Type m_type[2];

    int m_level; // [0 -> 100]
    int m_px;
    // GrowthRate m_growthRate;
    // EvolutionLine m_line;

    int m_personalityValue; // From 0 to 4 294 967 295
    int m_DOID;
    std::string m_DOName;
    int m_DOSecretID;

    int m_currentLP; // [0 -> m_stats[0]]
    int m_stats[6]; // HP, Atk, Def, SpeAtk, SpeDef, Speed
    int m_IV[6];    // HP, Atk, Def, SpeAtk, SpeDef, Speed : [0 -> 31]
    int m_EV[6];    // HP, Atk, Def, SpeAtk, SpeDef, Speed : Max per stat: 252 // Global Max: 510
    
    Move m_moves[4]; // Max 4
    // MoveTable


    /* Gen II
    bool m_shiny;
    int m_happiness;
    int m_affection;
    Object m_heldItem;
    */


    /* Gen III
    Nature m_nature;
    string m_like;
    Ability m_talent;
    */

    /*
    int m_metLevel;
    date m_metDate;
    string m_metPlace;
    int m_variant; // Alt. forms (Alola, Galar), Motisma, Exagide, Alt Sprites
    Région d'origine
    Mega Evolution
    Z-Moves
    DynaMax
    GigaMax
    */


public:

    int specieID();
    string name(); // specieName or nickname
    void name(string newName);
    int gender(); // 0 = none, 1 = male, 2 = female
    void gender(int newGender);

    Type[2] type(); // Max 2

    int level(); // [0 -> 100]
    void setLevel(int newLevel);
    void addLevel(int ammount);
    void removeLevel(int ammount);
    int px();
    void setPX(int newAmmount);
    void addPX(int ammount);
    void removePX(int ammount);

    int personalityValue(); // From 0 to 4 294 967 295
    int DOID();
    string m_DOName();
    int DOSecretID();

    int LP(); // [0 -> m_stats[0]]
    void setLP(int ammount);
    void addLP(int ammount);
    void removeLP(int ammount);
    int[6] stats();
    int atk();
    int def();
    int speAtk();
    int speDef();
    int speed();
    int[6] IV();
    int IV(int index);
    void setIV(int index, int newAmmount);
    void addIV(int index, int ammount);
    void removeIV(int index, int ammount);
    int[6] EV();
    void setEV(int index, int newAmmount);
    void addEV(int index, int ammount);
    void removeEV(int index, int ammount);
    
    Move[4] moves(); // Max 4
}

#endif  /* !POKEMON_H_ */