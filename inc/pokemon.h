#ifndef POKEMON_H_
#define POKEMON_H_

#include <vector>

#include "specie.h"
#include "evolution.h"
#include "utils.h"
#include "gender.h"
#include "type.h"
#include "personalityvalue.h"
// #include "knownMove.h"
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

protected:
    Gender m_gender; // 0 = none, 1 = male, 2 = female
    // TODO: optimize with bitset cuz for some reason a bool is stored on 8 bits...
    PersonalityValue m_ipv; // From 0 to 4 294 967 295
    int m_px;
    int m_level; // [1 -> 100]
    int m_currentLP;
    array<int, 6> m_stats; // HPMax, Atk, Def, SpeAtk, SpeDef, Speed
    array<int, 6> m_IV;    // HP, Atk, Def, SpeAtk, SpeDef, Speed : [0 -> 31]
    array<int, 6> m_EV;    // HP, Atk, Def, SpeAtk, SpeDef, Speed : Max per stat: 252 // Global Max: 510
    
public:

    Pokemon(int id, int variant); 
    virtual ~Pokemon() = 0;
    Gender gender();
    void gender(Gender newGender);
    PersonalityValue ipv(); // From 0 to 4 294 967 295

    int level(); // [1 -> 100]
    void setLevel(int newLevel);
    void levelUp();
    void addLevel(int ammount);
    void removeLevel(int ammount);
    int px();
    void setPX(int newAmmount);
    void addPX(int ammount);
    void removePX(int ammount);

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
    array<int, 6> IVs();
    int IV(int index);
    void setIV(int index, int newAmmount);
    void addIV(int index, int ammount);
    void removeIV(int index, int ammount);
    array<int, 6> EVs();
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

    void evolve(int specie, int variant);
    // bool meetAllConditions(Evolution* evo);

    /* TODO: remove comment
    Move* moves(); // Max 4
    */
};

#endif  /* !POKEMON_H_ */