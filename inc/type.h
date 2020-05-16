#ifndef TYPE_H_
#define TYPE_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isTypeNumberValid(int number); // checks that given number is between 0 and 18 (included)

class Type
{
private:
    int m_value;
    string m_name;
    vector<float> weaknesses;
    vector<float> resistances;
    vector<float> immunities;

public:
    Type();
    Type(vector<vector<string>> tokens);
    ~Type();
    void print();
    
    string name();
    void name(string newName);
    int value();
    void value(int newVal);
    static bool isNumberValid(int number); // checks that given number is between 0 and 18 (included)
    
    float multWhenHitBy(Type* what);
    float multWhenHitBy(int typeId);

    bool isTouchingFloor();
    bool canBePoisoned();
    bool canBeParalysed();
    bool canBeBurned();
    bool canBeFrozen();
    bool immuneToPowder();
    bool canBeLeeched();
    

    
};

// class Type
// {
// private:

//     static std::string* names();
//     static float** efficiency_values();
//     static float efficiency(int attackType, int defenseType);
//     static float efficiency_text_debug(int attackType, int defenseType);
// };


#endif  /* !TYPE_H_ */