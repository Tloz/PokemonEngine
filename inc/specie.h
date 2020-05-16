#ifndef SPECIE_H_
#define SPECIE_H_
#include <string>
#include <array>
#include <vector>
#include "pkmnexceptions.h"
#include "type.h"
#include "typefactory.h"
#include "evolution.h"
#include "utils.h"

using namespace std;

class Specie
{
private:
    /*
        // vector<int> m_dexNumbers;
        // string m_category;
        // // Gen III Ability* m_posibleTalents;
        // string m_color;
        // int m_bodyShape;
        // int m_footPrint;
        // string* m_dexEntries;
        // const location* m_locations;
    */

protected:
    float m_genderBalance; // aka chances of beingFemale
    string m_specieName;
    int m_specieID; // equals to national dex number
    int m_variant;
    string m_variantName;
    array<Type, 2> m_type;
    array<int, 6> m_baseStats; // HPMax, Atk, Def, SpeAtk, SpeDef, Speed

    int m_baseExp;
    int m_catchRate;
    int m_expAt100;
    vector<pair<int, int>> m_EVGiven; // 0 is type, 1 is value
    
    // vector<Evolution*> m_evolutionLine;

    /*
        // float m_size;
        // float m_weight;
        // // Gen II EggGroup m_group;
        // // Gen II int m_stepsToHatch;
        // int m_sound;
        // EvolutionLine m_line;
    */

public:
    Specie();
    Specie(vector<vector<string>> tokens);
    ~Specie();
    void print();

    int specieID();
    void specieID(int id);
    string specieName();
    void specieName(string newName);
    int variant();
    void variant(int id);
    string variantName();
    void variantName(string name);
    string fullName();
    float genderBalance();
    void genderBalance(float val);

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

    array<Type, 2> types();
    Type type(int index);
    Type firstType();
    Type secondType();
    void type(int index, Type type);
    void type(int index, int typeNo);
    void firstType(Type type);
    void firstType(int typeNo);
    void secondType(Type type);
    void secondType(int typeNo);
    void types(array<Type, 2> tab);
    void types(array<int, 2> typeNo);

    bool isOfType(Type p_type);
    bool isOfType(int typeNo);

    bool hasSecondType();

    int baseExp();
    void baseExp(int val);
    int catchRate();
    void catchRate(int rate);
    int expAt100();
    void expAt100(int val);
    vector<pair<int, int>> EVGiven();
    void EVGiven(vector<pair<int, int>>  value);

    // vector<Evolution*> evolutionLine();
    // vector<Evolution*> evolveWith(EvolutionTrigger trigger);
    
};

#endif  /* !SPECIE_H_ */