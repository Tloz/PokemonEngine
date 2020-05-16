#include <cmath>
#include "../inc/ball.h"
#include "../inc/utils.h"

Ball::Ball() : Item()
{

}

Ball::Ball(vector<vector<string> > tokensVector) : Item(tokensVector)
{
    bool verbose = false;
    vector<string> unsedTokens;
    for(auto tokens:tokensVector)
    {
        //cout << tokens[0] << ":" << tokens[1] << endl;
        if(tokens[0] == "Name")
        {
            name(tokens[1]);
        }
        else if(tokens[0] == "BallID")
        {
            id(stoi(tokens[1]));
        }
        else if(tokens[0] == "BonusBall")
        {
            bonusBall(stof(tokens[1]));
        }
        else
        {
            unsedTokens.push_back(tokens[0]);
        }
    }
    if(verbose && (unsedTokens.size() > 0))
    {
        cout << "Unused tokens: ";
        for(auto token:unsedTokens)
            cout << token << "; ";
        cout << endl;
    }
}

Ball::~Ball()
{

}

float Ball::bonusBall()
{
    return m_bonusBall;
}

void Ball::bonusBall(float bonus)
{
    if(bonus < 0.1)
        bonus = 1;
    m_bonusBall = bonus;
}

int Ball::catchIt(SavagePokemon* target)
{
    int retval = 0;
    float a = (3 * target->maxLP() - 2 * target->LP());
    a *= target->catchRate();
    a *= bonusBall();
    a /= (3 * target->maxLP());
    a *= target->catchBonus();

    if(a >= 255)
        return 4;
    
    float b = 65536 / pow((255.0/a),0.1875);

    for(int i = 0; i < 4; ++i)
    {
        float miniB = randFloatInRange(0, 65535);
        if(miniB <= b)
            retval++;
    }

    return retval;
}
