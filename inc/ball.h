#ifndef BALL_H
#define BALL_H

#include <string>
#include <vector>
#include "item.h"
#include "savagepokemon.h"

using namespace std;

class Ball : public Item
{
protected:
    float m_bonusBall;
    // conditions
public:
    Ball();
    Ball(vector<vector<string> > tokens);
    ~Ball();

    float bonusBall();
    void bonusBall(float bonus);
    int catchIt(SavagePokemon* target);
};
#endif