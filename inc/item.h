#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

using namespace std;

class Item
{
protected:
    string m_gid; // Global identifer
    int m_id;
    string m_name;
    int m_basePrice;
    int m_sellingFactor; // -1 is can't be sold, 0 is O, anything else is basePrice / 2
    // ItemType_t type;
public:
    Item();
    Item(vector<vector<string>> tokens);
    virtual ~Item() = 0;
    void print();
    
    string gid();
    void gid(string gid);
    int id();
    void id(int id);
    string name();
    void name(string name);
    int basePrice();
    void basePrice(int price);
    int sellingFactor();
    void sellingFactor(int sf);

    bool canBeSold();
    int sellPrice();
};



#endif