#ifndef POKEMON_H_
#define POKEMON_H_

#include "gender.h"
#include "specie.h"
#include "type.h"
// #include "move.h"
// #include "object.h"
// #include "ability.h"

#define LEVEL_MIN 1
#define LEVEL_MAX 100
#define IV_MIN 0
#define IV_MAX 31
#define EV_MIN 0
#define EV_MAX_LOCAL 252
#define EV_MAX_GLOBAL 512

using namespace std;

class Pokemon : public Specie
{
private:
    string m_name; // specieName or nickname
    Gender m_gender; // 0 = none, 1 = male, 2 = female
    int m_personalityValue; // From 0 to 4 294 967 295

    int m_DOID;
    string m_DOName;
    int m_DOSecretID;
    
    // int m_metLevel;
    // // date m_metDate;
    // string m_metPlace;

    int m_level; // [1 -> 100]
    int m_px;
    
    int m_currentLP;
    array<int, 6> m_stats; // HPMax, Atk, Def, SpeAtk, SpeDef, Speed
    array<int, 6> m_IV;    // HP, Atk, Def, SpeAtk, SpeDef, Speed : [0 -> 31]
    array<int, 6> m_EV;    // HP, Atk, Def, SpeAtk, SpeDef, Speed : Max per stat: 252 // Global Max: 510
    
    /* TODO: remove comment
    Move m_moves[4]; // Max 4
    State (paralysed, asleep, poisoned, ...)
    other state (confusion, ...)
    Buffs
    */


    /* Gen II
    bool m_shiny;
    int m_happiness;
    Object m_heldItem;
    */


    /* Gen III
    Nature m_nature;
    POKERUS (date of infection, contagious, has it?)
    Ability m_talent;
    */

    /*
    int m_variant; // Alt. forms (Alola, Galar), Motisma, Exagide, Alt Sprites (Zarbi)
    Région d'origine, isForeign() // Gain supp d'xp
    Mega Evolution
    Z-Moves
    DynaMax
    GigaMax
    */

public:

    // for debug purposes
    Pokemon(); 

    ~Pokemon(); // Cuz we need it
    
    /*
    in: nothing
    retval: nickname 
    error: must not be empty
    */
    string name();

    /*
    in: the new name
    retval: nothing
    error: newName must not be empty
    */
    void name(string newName);

    /*
    in: nothing
    retval: the pokemon's gender as (Gender::) None, Male, or Female
    error: retval is not inNone, Male, or Female
    */
    Gender gender();

    /*
    in: the new gender as the pokemon's gender as (Gender::) None, Male, or Female
    retval: nothing
    error: newGender is not in None, Male, or Female
    */
    void gender(Gender newGender);

    /*
    in: nothing
    retval: a int pointer
    error: no types are set (min 1) or more than two are set
    */
    //Type* type(); // Max 2

    /*
    in: array (pointer on max two types)
    retval: nothing
    error: more than two types given or less than 1
    */
    //void type(Type types[2]);


    
    int level(); // [1 -> 100]
    void setLevel(int newLevel);
    void addLevel(int ammount);
    void removeLevel(int ammount);
    int px();
    void setPX(int newAmmount);
    void addPX(int ammount);
    void removePX(int ammount);

    int personalityValue(); // From 0 to 4 294 967 295
    int DOID();
    string DOName();
    int DOSecretID();

    

    int LP(); // [0 -> m_stats[0]]
    int maxLP();
    void setLP(int ammount);
    void addLP(int ammount);
    void removeLP(int ammount);
    array<int, 6> stats();
    int atk();
    int def();
    int speAtk();
    int speDef();
    int speed();
    array<int, 6> IV();
    int IV(int index);
    void setIV(int index, int newAmmount);
    void addIV(int index, int ammount);
    void removeIV(int index, int ammount);
    array<int, 6> EV();
    int EV(int index);
    int totalEV();
    void setEV(int index, int newAmmount);
    void addEV(int index, int ammount);
    void removeEV(int index, int ammount);

    void computeMaxLP();
    void computeAtk();
    void computeDef();
    void computeSpeAtk();
    void computeSpeDef();
    void computeSpeed();
    void computeStat(int index);
    void computeStats();

    
    /* TODO: remove comment
    Move* moves(); // Max 4
    */

    string toString();
};

#endif  /* !POKEMON_H_ */