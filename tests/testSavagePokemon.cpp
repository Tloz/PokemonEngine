#include "../data/values.h"
#include "../inc/savagepokemon.h"

void printSPK(SavagePokemon s)
{
    cout << "Pokemon " << s.specieName();
    if((s.variant() != 0))
        cout << " " << s.variantName();
    cout << " Level " << s.level() << endl;
    cout << "Gender balance is " << s.genderBalance() << " and vfg is " <<s.ipv().valueForGender() <<endl;
    if(s.gender() != Gender::None)
    {
        cout <<"It's a ";
        if(s.gender() == Gender::Female)
            cout << "girl";
        else
            cout << "boy";
        cout << "! ";
    }
    cout << "Personality Value: ";
    for (int i = 0; i < 32; ++i)
    {
        cout << s.ipv().value()[i];
    }
    cout << " ("<< s.ipv().valueForGender() << ")" << endl;

    cout << "Type: " << s.firstType()->name();
    if (s.hasSecondType())
        cout << " and " << s.secondType()->name();

    cout << endl;
    cout << "Stat, IV, EV" << endl;
    cout << "LP: " << s.LP() << "/" << s.maxLP() << " (" << s.baseStat(0) << ", " << s.IV(0) << ", " << s.EV(0) << ")" << endl;
    cout << "ATK: " << s.atk() << " (" << s.baseStat(1) << ", " << s.IV(1) << ", " << s.EV(1) << ")" << endl;
    cout << "DEF: " << s.def() << " (" << s.baseStat(2) << ", " << s.IV(2) << ", " << s.EV(2) << ")" << endl;
    cout << "SpeEtk: " << s.speAtk() << " (" << s.baseStat(3) << ", " << s.IV(3) << ", " << s.EV(3) << ")" << endl;
    cout << "SpeDef: " << s.speDef() << " (" << s.baseStat(4) << ", " << s.IV(4) << ", " << s.EV(4) << ")" << endl;
    cout << "Speed: " << s.speed() << " (" << s.baseStat(5) << ", " << s.IV(5) << ", " << s.EV(5) << ")" << endl << endl;
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 1; ++i)
    {
        SavagePokemon s(TABspecieID[i], TABvariantID[i], 100);
        s.type(0, new Type(TABtypes1[i]));
        s.type(1, new Type(TABtypes2[i]));
        s.baseStat(0, TABLP[i]);
        s.baseStat(1, TABATK[i]);
        s.baseStat(2, TABDEF[i]);
        s.baseStat(3, TABSpeATK[i]);
        s.baseStat(4, TABSpeDEF[i]);
        s.baseStat(5, TABSpeed[i]);
        s.computeStats();
        s.setLP(s.baseStat(0));
        s.specieName(TABnames[i]);
        s.genderBalance(TABgenderBalance[i]);
        s.gender(determineGender(s.genderBalance(), s.ipv().valueForGender()));
        printSPK(s);
    }
    return 0;
}