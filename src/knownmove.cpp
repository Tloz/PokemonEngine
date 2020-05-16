#include "../inc/knownmove.h"

KnownMove::KnownMove()
{
    
}

KnownMove::KnownMove(vector<vector<string>> moveTokens, int pp, int max) : Move(moveTokens)
{
    m_pp = pp;
    m_ppmax = max;
}

KnownMove::~KnownMove()
{

}

bool KnownMove::isSet()
{
    if (m_moveID)
        return true;
    return false;
}

int KnownMove::pp()
{
    if(m_pp < 0)
        m_pp = 0;
    if(m_pp > ppmax())
        m_pp = ppmax();
    return m_pp;
}

int KnownMove::ppmax()
{
    if(m_ppmax <= 0)
        return 10;
    return m_ppmax;
}

bool KnownMove::haveEnoughPP()
{
    return (m_pp < 0);
}

void KnownMove::refilPP()
{
    m_pp = ppmax();
}

void KnownMove::usePP()
{
    if(haveEnoughPP())
        m_pp -= 1;
    else
        throw exception();
}
