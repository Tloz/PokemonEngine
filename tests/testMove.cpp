#include "../inc/move.h"
#include "../data/values.h"
#include <iostream>

using namespace std;

    // m_criticalLevel = ATKTABCrit[i];
    // m_scareRate = ATKTABScare[i];
    // m_target = ATKTABTargetClass[i];
    // m_direct = ATKTABDir[i];


void printMove(Move m)
{
    cout << "Attaque " << m.name() << " (PPbase/PPMax: " << m.ppBase() << "/" << m.ppMax() << ")" << endl;
    cout << "Puissance: " << m.power() << " Précision: " << m.precision() << endl;
    cout <<"Type: " << m.type()->name() << " Categorie: " << catName(m.category()) << endl;

    cout << endl;
}

int main()
{
    for (int i = 0; i < 7; ++i)
    {
        printMove(Move(i, ATKTABNames[i], ATKTABType[i], ATKTABPow[i], ATKTABPre[i], ATKTABCat[i], ATKTABPP[i]));
    }
    return 0;
}