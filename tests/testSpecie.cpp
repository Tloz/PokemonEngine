#include "../inc/specie.h"
#include "../data/values.h"
#include <vector>

void printSpecie(Specie s)
{
    cout << "Specie " << s.specieName();
    if((s.variant() != 0))
        cout << " " << s.variantName();
    cout << " (" << s.specieID() << ")" << endl;
    cout << "Type: " << s.firstType()->name();
    if (s.hasSecondType())
        cout << " and " << s.secondType()->name();
    cout << endl;
    cout << "LP: " << s.baseStat(0) << " Speed: " << s.baseStat(5) << endl;
    cout << "ATK: " << s.baseStat(1) << " DEF: " << s.baseStat(2) << endl;
    cout << "ATK: " << s.baseStat(3) << " DEF: " << s.baseStat(4) << endl;
    cout << s.genderBalance() << "% chances of being female" << endl << endl;
}

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
        printSpecie(v[i]);
    }
    return 0;
}