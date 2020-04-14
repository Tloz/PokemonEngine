#include "../inc/specie.h"
#include <vector>

int main()
{
    std::vector<Specie> v;
    for (int i = 0; i < 17; ++i)
    {
        Specie s(i);
        v.push_back(s);
    }
    
    for (int i = 0; i < 17; ++i)
    {
        v[i].print();
    }
    return 0;
}