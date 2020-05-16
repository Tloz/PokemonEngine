#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>
#include "../inc/utils.h"
#include "../inc/parser.h"
#include "../inc/trainerpokemon.h"
// #include "../inc/item.h"

#define DOID_MAX 65535

class Trainer
{
private:
    string m_name;
    int m_money;
    int m_DO = 53190;
    int m_DOSecret = 22983;
    vector<TrainerPokemon> m_team;
    // vector<Item> m_inventory;

public:
    Trainer(string name = "Ash");
    Trainer(vector<vector<string>> trainerTokens);
    ~Trainer();
    void print();

    string name();
    void name(string newName);
    int money();
    void money(int val);
    void addMoney(int val);
    void removeMoney(int val);
    void setMoney(int val);
    int DO();
    void DO(int val);
    int DOS();
    void DOS(int val);
    int valueForShiny();
    vector<TrainerPokemon> team();
    // vector<Item> inventory();
};

#endif