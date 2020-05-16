#include "../../inc/ballfactory.h"

Ball BallFactory::createBall(int ballType)
{
    // cout << "Debug: building ball with ID: " << ballType << endl;
    string ballFileName = RESSOURCES_FOLDER;
    ballFileName += ITEM_FOLDER;
    ballFileName += BALL_FOLDER;
    ballFileName += "i_b_";
    // adding padding
    std::stringstream ss;
    ss << std::setw(BALL_FILE_NAME_PAD_UNIT) << std::setfill('0') << ballType;
    ballFileName += ss.str();
    ballFileName += ITEM_EXT;

    Ball b;
    try
    {
        b = Ball(getTokensFromFile(ballFileName));
    }
    catch(exception const& e)
    {
        throw;
    }
    return b;
}

Ball BallFactory::createPokeball()
{
    return createBall(1);
}

Ball BallFactory::createSuperball()
{
    return createBall(2);
}

Ball BallFactory::createHyperball()
{
    return createBall(3);
}

Ball BallFactory::createMasterball()
{
    return createBall(4);
}
