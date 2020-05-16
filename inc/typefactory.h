#ifndef TYPEFACTORY_H
#define TYPEFACTORY_H

#include "parser.h"
#include "type.h"
#include <string>

#include "factories.h"


namespace TypeFactory
{
    Type createType(int typeID);
    Type noType();
    Type dark();
    Type dragon();
    Type electric();
    Type fairy();
    Type fight();
    Type fire();
    Type floor();
    Type fly();
    Type ghost();
    Type grass();
    Type ice();
    Type insect();
    Type normal();
    Type poison();
    Type psy();
    Type rock();
    Type steel();
    Type water();
}


#endif