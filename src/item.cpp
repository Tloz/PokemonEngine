#include "../inc/item.h"
#include <iostream>

Item::Item()
{
    gid("i_s_0");
    id(0);
    name("Null Object");
    basePrice(10);
    sellingFactor(-1);
}

Item::Item(vector<vector<string>> tokensVector)
{
    bool verbose = false;
    vector<string> unsedTokens;
    for(auto tokens:tokensVector)
    {
        //cout << tokens[0] << ":" << tokens[1] << endl;
        if(tokens[0] == "GID")
        {
            gid(tokens[1]);
        }
        else if(tokens[0] == "ID")
        {
            id(stoi(tokens[1]));
        }
        else if(tokens[0] == "Name")
        {
            name(tokens[1]);
        }
        else if(tokens[0] == "BasePrice")
        {
            basePrice(stoi(tokens[1]));
        }
        else if(tokens[0] == "sellingFactor")
        {
            sellingFactor(stoi(tokens[1]));
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

Item::~Item()
{

}

void Item::print()
{
    cout << "Item " << name() << " (" << gid() << "/" << id() << ")" << endl;
    cout << "Base price: " << basePrice() << " | Selling factor: " << sellingFactor() << endl;
}

string Item::gid()
{
    return m_gid;
}

void Item::gid(string gid)
{
    m_gid = gid;
}

int Item::id()
{
    return m_id;
}

void Item::id(int id)
{
    m_id = id;
}

string Item::name()
{
    return m_name;
}

void Item::name(string name)
{
    m_name = name;
}

int Item::basePrice()
{
    return m_basePrice;
}

void Item::basePrice(int price)
{
    m_basePrice = price;
}

int Item::sellingFactor()
{
    return m_sellingFactor;
}

void Item::sellingFactor(int sf)
{
    m_sellingFactor = sf;
}

bool Item::canBeSold()
{
    return (sellingFactor() != -1);
}

int Item::sellPrice()
{
    if(canBeSold())
    {
        string s = name();
        s += "can't be sold";
        throw runtime_error(s);
    }
    if(sellingFactor() == 0)
        return 0;
    else
        return basePrice() / 2;

}