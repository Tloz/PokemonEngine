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
    cout << "Debuging main" << endl;
    for (int i = 0; i < 17; ++i)
    {
        Specie s(TABspecieID[i], TABvariantID[i]);
        s.specieName(TABnames[i]);
        s.baseStat(0, TABLP[i]);
        s.baseStat(1, TABATK[i]);
        s.baseStat(2, TABDEF[i]);
        s.baseStat(3, TABSpeATK[i]);
        s.baseStat(4, TABSpeDEF[i]);
        s.baseStat(5, TABSpeed[i]);
        s.type(0, new Type(TABtypes1[i]));
        s.type(1, new Type(TABtypes2[i]));
        s.genderBalance(TABgenderBalance[i]);
        printSpecie(s);
    }
    return 0;
}