#ifndef KNOWNMOVE_H_
#define KNOWNMOVE_H_

#include "move.h"

class KnownMove : public Move
{
protected:
    int m_pp;
    int m_ppmax;

public:
    KnownMove();
    ~KnownMove();

    int pp();
    int ppmax();

    bool haveEnoughPP();
    void refilPP();
    void usePP();
    
};

#endif  /* !KNOWNMOVE_H_ */