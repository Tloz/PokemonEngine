#ifndef KNOWNMOVE_H_
#define KNOWNMOVE_H_

#include "move.h"

using namespace std;

class KnownMove : public Move
{
protected:
    int m_pp;
    int m_ppmax;

public:
    KnownMove();
    KnownMove(vector<vector<string>> moveTokens, int cur, int max);
    KnownMove(Move m, int currentPP, int MaxPP);
    KnownMove(string fileName, int currentPP, int MaxPP);
    ~KnownMove();

    bool isSet();

    int pp();
    int ppmax();

    bool haveEnoughPP();
    void refilPP();
    void usePP();
    
};

#endif  /* !KNOWNMOVE_H_ */