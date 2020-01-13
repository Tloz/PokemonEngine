#ifndef SPECIE_H_
#define SPECIE_H_
#include <string>
#include <array>
#include <vector>
#include "pkmnexceptions.h"
#include "type.h"

using namespace std;

class Specie
{
private:
    vector<int> m_dexNumbers;
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
    array<Type*, 2> m_type;
    float m_size;
    float m_weight;
    // Gen II EggGroup m_group;
    // Gen II int m_stepsToHatch;
    array<int, 2> m_EVGiven; // 0 is type, 1 is value
    int m_baseExp;
    int m_captureRate;
    int m_sound;

    /* TODO: this must be a const int. For now, will remain int for debug puposes */
    array<int, 6> m_baseStats; // HPMax, Atk, Def, SpeAtk, SpeDef, Speed

    // GrowthRate m_growthRate; // aka Exp at lvl 100
    // EvolutionLine m_line;
    // MovePool (By Leveling, DT)

public:
    Specie();
    Specie(int id, int variant);
    ~Specie();

    int specieID();

    // [1 -> 255]
    array<int, 6> baseStats();
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

    Type* type(int index);
    Type* firstType();
    Type* secondType();
    array<Type*, 2> types();
    void type(int index, Type* type);
    void firstType(Type* type);
    void secondType(Type* type);
    void types(array<Type*, 2> tab);
    bool isOfType(Type* p_type);
    
};

#endif  /* !SPECIE_H_ */