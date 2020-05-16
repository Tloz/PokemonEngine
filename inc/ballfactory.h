#ifndef BALLFACTORY_H
#define BALLFACTORY_H

#include "parser.h"
#include "item.h"
#include "ball.h"

#include <string>

#define RESSOURCES_FOLDER "assets/"
#define ITEM_FOLDER "items/"
#define BALL_FOLDER "balls/"
#define ITEM_EXT ".itm"
#define BALL_FILE_NAME_PAD_UNIT 3


class BallFactory
{
public:
    BallFactory();
    ~BallFactory();

    static Ball createBall(int ballType = 1);
    static Ball createPokeball();
    static Ball createSuperball();
    static Ball createHyperball();
    static Ball createMasterball();
    
};

#endif