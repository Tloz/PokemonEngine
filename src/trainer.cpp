#include "../inc/trainer.h"
#include "../inc/utils.h"

Trainer::Trainer(string name)
{
    m_name = name;
    m_DO = randFloatInRange(0, DOID_MAX);
    m_DOSecret = randFloatInRange(0, DOID_MAX);
    m_money = randFloatInRange(0, 5000);
}

Trainer::Trainer(vector<vector<string>> trainerTokens)
{
    vector<vector<string>> unsedTokens;
    for(auto token:trainerTokens)
    {
        if(token[0] == "Name")
        {
            m_name = token[1];
        }
        else if(token[0] == "DO")
        {
            m_DO = stoi(token[1]);
        }
        else if(token[0] == "DOS")
        {
            m_DOSecret = stoi(token[1]);
        }
        else if(token[0] == "Money")
        {
            m_money = stoi(token[1]);
        }
        else
        {
            unsedTokens.push_back(token);
        }
    }
    if(unsedTokens.size() > 0)
    {
        cout << "Unused tokens: ";
        for(auto token:unsedTokens)
            cout << token[0] << "; ";
        cout << endl;
    }
}

Trainer::~Trainer()
{

}

void Trainer::print()
{
    cout << "Dresseur " << name() << endl;
    cout << "(" << DO() << "/" << DOS() << ")" << endl;
    cout << "With " << money() << " PokeDollars" << endl << endl;
}


string Trainer::name()
{
    return m_name;
}

void Trainer::name(string newName)
{
    if(newName.size() == 0)
    {
        cout << "newName can't be empty" << endl;
        throw exception();
    }
}

int Trainer::money()
{
    return m_money;
}

void Trainer::money(int val)
{
    if(val < 0)
        val = 0;
    m_money = val;
}

void Trainer::addMoney(int val)
{
    if(val < 0)
    {
        val = -val;
    }
    money(m_money + val);
}

void Trainer::removeMoney(int val)
{
    if(val < 0)
    {
        val = -val;
    }
    m_money -= val;
    money(m_money - val);
}

void Trainer::setMoney(int val)
{
    money(val);
}

int Trainer::DO()
{
    if(m_DO > DOID_MAX)
    {
        m_DO = DOID_MAX;
    }
    return m_DO;
}

void Trainer::DO(int val)
{
    if(val > DOID_MAX)
        val = DOID_MAX;
    m_DO = val;
}

int Trainer::DOS()
{
    if(m_DOSecret > DOID_MAX)
    {
        m_DOSecret = DOID_MAX;
    }
    return m_DOSecret;
}

void Trainer::DOS(int val)
{
    if(val > DOID_MAX)
        val = DOID_MAX;
    m_DOSecret = val;
}

int Trainer::valueForShiny()
{
    return DO() xor DOS();
}


vector<TrainerPokemon> Trainer::team()
{
    return m_team;
}

// vector<Item> Trainer::inventory()
// {
//     return m_inventory;
// }