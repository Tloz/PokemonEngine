#include "testSpecie.h"

int main()
{
    for (int i = 0; i < 17; ++i)
    {
        Specie s(i);
        s.print();
    }
    return 0;
}