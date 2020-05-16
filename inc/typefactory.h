#ifndef TYPEFACTORY_H
#define TYPEFACTORY_H

#include "parser.h"
#include "type.h"
#include <string>

#include "factories.h"


class TypeFactory
{
public:
    TypeFactory();
    ~TypeFactory();

    static Type createType(int typeID);
    static Type noType();
    static Type dark();
    static Type dragon();
    static Type electric();
    static Type fairy();
    static Type fight();
    static Type fire();
    static Type floor();
    static Type fly();
    static Type ghost();
    static Type grass();
    static Type ice();
    static Type insect();
    static Type normal();
    static Type poison();
    static Type psy();
    static Type rock();
    static Type steel();
    static Type water();
};


#endif