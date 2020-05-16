#ifndef MOVE_H_
#define MOVE_H_
#include <string>
#include <array>
#include <vector>
#include "type.h"
#include "pkmnexceptions.h"

enum Cat
{
    Physical,
    Special,
    Status
};

enum TargetClass
{
    NoTarget,
    Self,
    AnyFoe,
    AnyTeam,
    AnyAdj,
    AdjFoe,
    AdjTeam,
    AllButSelf,
    All
};

class Move
{

protected:
    // Primary
    int m_moveID;
    string m_name;
    Type m_type;
    int m_power; // [0; 250]
    int m_precision; // [0; 100]
    Cat m_category;
    int m_ppBase;
    // Secondary
    TargetClass m_target;
    int m_priority; // [-7; 8]
    bool m_direct;
    int m_criticalLevel;
    // Tertiary
    int m_scareRate;
    int m_effetChance;
    void* m_sideEffectFunction;
    bool m_isPowder;  
    array<bool, 4> m_affectedBy;
    // 0 for protec and detect
    // 1 for snatch
    // 2 for MagicCoat or Magic Bounce
    // 3 for Bright Powder

public:
    Move();
    Move(vector< vector< string > > moveTokens);
    ~Move();
    void print();
    // Primary
    int moveID();
    string name();
    Type type();
    int power();
    int precision();
    Cat category();
    int ppBase();
    int ppMax();

    string targetClassName();
    string catName();
    // Secondary
    TargetClass target();
    int priority();
    bool contact();
    int criticalLevel();
    // Tertiary
    float criticalRate();
    int scareRate();
    bool isPowder();   
    array<bool, 4> affectedBy();
    bool affectedBy(int index);
    bool affectedByProtectAndDetect();
    bool affectedBySnatch();
    bool affectedByMagicCoatOrMagicBounce();
    bool affectedByBrightPowder();
    bool affectedByKingsRock(); 
};

#endif  /* !MOVE_H_ */