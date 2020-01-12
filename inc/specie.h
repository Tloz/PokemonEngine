#ifndef SPECIE_H_
#define SPECIE_H_
#include <string>
#include <array>
#include "pkmnexceptions.h"
#include "type.h"

using namespace std;

class Specie
{
private:
    int* m_dexNumbers;
    string m_category;
    // Gen III Ability* m_posibleTalents;
    int m_genderBalance; // aka chances of beingFemale
    string m_color;
    int m_bodyShape;
    int m_footPrint;
    string* m_dexEntries;
    // const location* m_locations;


protected:
    int m_specieID; // equals to national dex number
    int m_variant;
    string m_specieName;
    array<int, 2> m_type;
    float m_size;
    float m_weight;
    // Gen II EggGroup m_group;
    // Gen II int m_stepsToHatch;
    int m_EVGiven[2]; // 0 is type, 1 is value
    int m_baseExp;
    // GrowthRate m_growthRate; // aka Exp at lvl 100
    int m_captureRate;
    int m_sound;

    /* TODO: this must be a const int. For now, will remain int for debug puposes */
    int* m_baseStats; // HPMax, Atk, Def, SpeAtk, SpeDef, Speed

    // EvolutionLine m_line;
    // MovePool (By Leveling, DT)

public:
    Specie();
    Specie(int id, int variant);
    ~Specie();

        /*
    in: nothing
    retval: unique specie identifier (a.k.a the row in DB)
    error: must be strictly positive
    */
    int specieID();

    // [1 -> 255]
    int* baseStats();
    int baseStat(int index);
    void baseStat(int index, int ammount);
    int baseLP();
    void baseLP(int ammount);
    int baseAtk();
    void baseAtk(int ammount);
    int baseDef();
    void baseDef(int ammount);
    int baseSpeAtk();
    void baseSpeAtk(int ammount);
    int baseSpeDef();
    void baseSpeDef(int ammount);
    int baseSpeed();
    void baseSpeed(int ammount);

    int type(int index);
    int firstType();
    int secondType();
    array<int, 2> types();
    void type(int index, int type);
    void firstType(int type);
    void secondType(int type);
    void types(array<int, 2> tab);
    
};

#endif  /* !SPECIE_H_ */