#include "../../inc/savagepokemon.h"
#include "../../inc/pokefactory.h"
#include "../../inc/ballfactory.h"
#include "../../inc/ball.h"


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int id = 133;
    int level = 25;

    if(argc == 2)
    {
        id = atoi(argv[1]);
    }
    if(argc == 3)
    {
        id = atoi(argv[1]);
        level = atoi(argv[2]);
    }

    SavagePokemon encounter = PokeFactory::createSavagePokemon(id, level);
    encounter.setLP(1);
    cout << "Un " << encounter.name() << " sauvage apparaît !" << endl;
    encounter.print();

    Ball pokeball = BallFactory::createBall(1);
    Ball superball = BallFactory::createBall(2);
    Ball hyperball = BallFactory::createBall(3);
    Ball masterball = BallFactory::createBall(4);

    char c;
    int shakes = 0;
    while(cin >> c)
    {
        switch(c)
        {
            case '1':
                shakes = pokeball.catchIt(&encounter);
                break;
            case '2':
                shakes = superball.catchIt(&encounter);
                break;
            case '3':
                shakes = hyperball.catchIt(&encounter);
                break;
            case '4':
                shakes = masterball.catchIt(&encounter);
                break;
        }
        if(shakes == 4)
        {
            cout << "Il est capturé" << endl;
            break;
        }
        else
        {
            cout << shakes << " shake(s)" << endl;
        }
        shakes = 0;
    }
    return 0;
}