#ifndef TRAINERFACTORY_H
#define TRAINERFACTORY_H

#include "parser.h"
#include "trainer.h"
#include <string>
#include <iostream>

#include "factories.h"


class TrainerFactory
{
public:
    TrainerFactory();
    ~TrainerFactory();
    static Trainer loadPlayer();
    static Trainer readTrainer(string identifier);    
};


#endif