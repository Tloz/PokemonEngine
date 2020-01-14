#ifndef MOVE_H_
#define MOVE_H_
#include <string>
#include "type.h"
#include "pkmnexceptions.h"
enum class Cat
{
    Physical,
    Special,
    Status
};

class Move
{

protected:
    int m_moveID;
    string m_name;
    int m_power; // [0; 250]
    int m_precision; // [0; 100]
    Type* m_type;
    Cat m_category;
    int m_priority; // [-7; 8]
    int m_ppBase;
    bool m_contact;
    int m_criticalLevel;
    int m_scareRate;
    // Targets

public:
    Move();
    ~Move();
    int moveID();
    string name();
    int power();
    int precision();
    Type* type();
    Cat category();
    int priority();
    int ppBase();
    int ppMax();
    bool contact();
    int criticalLevel();
    float criticalRate();
    int scareRate();

    bool affectedByProtectAndDetect();
    bool affectedBySnatch();
    bool affectedByMagicCoatOrMagicBounce();
    bool affectedByBrightPowder();
    bool affectedByKingsRock(); 
    bool isPowder();   
};


#endif  /* !MOVE_H_ */