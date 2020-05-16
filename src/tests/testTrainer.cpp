#include "../../inc/trainer.h"
#include "../../inc/trainerfactory.h"

int main()
{
    srand(time(NULL));
    Trainer t1;
    Trainer t2("Blue... Er, no, Red!");
    Trainer t3 = TrainerFactory::loadPlayer();
    t1.print();
    t2.print();
    t3.print();
    return 0;
}