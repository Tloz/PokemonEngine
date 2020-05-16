#ifndef POKEMON_H_
#define POKEMON_H_

#include <vector>

#include "specie.h"
#include "evolution.h"
#include "utils.h"
#include "gender.h"
#include "type.h"
#include "personalityvalue.h"
#include "knownmove.h"
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

enum class NonVolatileStatus_t
{
    None,
    Burn,
    Freeze,
    Paralysis,
    Poisoned,
    PoisonedBadly,
    Sleep
};

enum class VolatileStatus_t
{
    None,
    Bound,
    CantEscape,
    Confusion,
    Curse,
    Embargo,
    Encore,
    Flinch,
    HealBlock,
    Identified,
    Infatuation,
    LeechSeed,
    Nightmare,
    PerishSong,
    Taunt,
    Telekinesis,
    Torment
};

enum class VolatileBattleStatus_t
{
    AquaRing,
    Bracing,
    ChargingTurn,
    CenterOfAttention,
    DefenseCurl,
    Rooting,
    MagicCoat,
    MagneticLevitation,
    Minimize,
    Protection,
    Recharging,
    SemiInvulnerable,
    Substitute,
    TakingAim,
    Withdrawing   
};

class Pokemon : public Specie 
{

protected:
    string m_name;
    string m_origin;
    Gender m_gender; // 0 = none, 1 = male, 2 = female
    // TODO: optimize with bitset cuz for some reason a bool is stored on 8 bits...
    PersonalityValue m_ipv; // From 0 to 4 294 967 295
    int m_px;
    int m_level; // [1 -> 100]
    int m_currentLP;
    array<int, 6> m_stats; // HPMax, Atk, Def, SpeAtk, SpeDef, Speed
    array<int, 6> m_IV;    // HP, Atk, Def, SpeAtk, SpeDef, Speed : [0 -> 31]
    array<int, 6> m_EV;    // HP, Atk, Def, SpeAtk, SpeDef, Speed : Max per stat: 252 // Global Max: 510

    vector<KnownMove> m_moves;

    NonVolatileStatus_t m_status;
    VolatileStatus_t m_condition;
    VolatileBattleStatus_t m_battleStatus;
    
public:
    Pokemon();
    Pokemon(vector<vector<string>> tokensVector);
    Pokemon(string fileSpecie);
    virtual ~Pokemon() = 0;
    void print();
    Gender gender();
    void gender(Gender newGender);
    PersonalityValue ipv(); // From 0 to 4 294 967 295

    string name();
    void name(string newName);
    string origin();
    void origin(string newOrigin);

    NonVolatileStatus_t status();
    VolatileStatus_t condition();
    VolatileBattleStatus_t BattleStatus();
    void status(NonVolatileStatus_t status);
    void condition(VolatileStatus_t condition);
    void battleStatus(VolatileBattleStatus_t battleStatus);

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
    void setLPToMax();
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

    vector<KnownMove> moves();
    void addMove(int moveID, int cur, int max);
    void setMove(int moveID, int where);
    void setMove(int moveID, int where, int cur, int max);
    void eraseMove(int where);

    void evolve(int specie, int variant);
    // bool meetAllConditions(Evolution* evo);
};

#endif  /* !POKEMON_H_ */