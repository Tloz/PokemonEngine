#ifndef TRAINERFACTORY_H
#define TRAINERFACTORY_H

#include "parser.h"
#include "trainer.h"
#include <string>
#include <iostream>

#include "factories.h"


namespace TrainerFactory
{
    Trainer loadPlayer();
    Trainer readTrainer(string identifier);    
}


#endif