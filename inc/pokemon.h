#ifndef POKEMON_H_
#define POKEMON_H_
#include "pkmnexceptions.h"
// #include "ability.h"
#include "move.h"
// #include "object.h"
#include "specie.h"
#include "type.h"

#define LEVEL_MIN 1
#define LEVEL_MAX 100
#define IV_MIN 0
#define IV_MAX 31
#define EV_MIN 0
#define EV_MAX_LOCAL 252
#define EV_MAX_GLOBAL 512

enum class Gender
{
    None,
    Male,
    Female
};

using namespace std;

class Pokemon
{
private:
    int m_specieID;
    string m_name; // specieName or nickname
    Gender m_gender; // 0 = none, 1 = male, 2 = female

    // /!\ Un pokémon a normalement toujours un type, mais il peut avrriver qu'un pokémon perd son/ses type(s) et se retrouve sans type
    int m_type[2];

    int m_level; // [1 -> 100]
    int m_px;
    // GrowthRate m_growthRate;
    // EvolutionLine m_line;

    int m_personalityValue; // From 0 to 4 294 967 295
    int m_DOID;
    string m_DOName;
    int m_DOSecretID;

    int m_currentLP; 
    int m_stats[6]; // HPMax, Atk, Def, SpeAtk, SpeDef, Speed
    int m_IV[6];    // HP, Atk, Def, SpeAtk, SpeDef, Speed : [0 -> 31]
    int m_EV[6];    // HP, Atk, Def, SpeAtk, SpeDef, Speed : Max per stat: 252 // Global Max: 510
    
    /* TODO: remove comment
    Move m_moves[4]; // Max 4
    */
    // MoveTable
    // State (paralysed, asleep, poisoned, ...)


    /* Gen II
    bool m_shiny;
    int m_happiness;
    int m_affection;
    Object m_heldItem;
    POKERUS (date of infection, contagious, has it?)
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
    Région d'origine, isForeign() // Gain supp d'xp
    Mega Evolution
    Z-Moves
    DynaMax
    GigaMax
    */

public:

    // for debug purposes
    Pokemon(); 

    /*
    in: nothing
    retval: unique specie identifier (a.k.a the row in DB)
    error: must be strictly positive
    */
    int specieID();
    
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
    int* stats();
    int atk();
    int def();
    int speAtk();
    int speDef();
    int speed();
    int* IV();
    int IV(int index);
    void setIV(int index, int newAmmount);
    void addIV(int index, int ammount);
    void removeIV(int index, int ammount);
    int* EV();
    int EV(int index);
    int totalEV();
    void setEV(int index, int newAmmount);
    void addEV(int index, int ammount);
    void removeEV(int index, int ammount);
    
    /* TODO: remove comment
    Move* moves(); // Max 4
    */

    string toString();
};

#endif  /* !POKEMON_H_ */