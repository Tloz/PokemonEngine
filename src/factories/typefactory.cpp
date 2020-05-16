#include "../../inc/typefactory.h"

Type TypeFactory::createType(int typeID)
{
    // On accède au dossier des espèces
    string fileName = RESSOURCES_FOLDER;
    fileName += TYPES_FOLDER;
    fileName += "type";
    // On ajoute des 0 de padding pour avoir le bon nom de fichier
    std::stringstream ss;
    ss << std::setw(TYPE_FILE_NAME_PAD_UNIT) << std::setfill('0') << typeID;
    fileName += ss.str();
    // On ajoute l'extension
    fileName += TYPE_EXT;
    
    Type retType;
    try
    {
        retType = Type(getTokensFromFile(fileName));
    }
    catch(exception const& e)
    {
        throw;
    }
    return retType;
}

Type TypeFactory::noType()
{
    return createType(0);
}

Type TypeFactory::dark()
{
    return createType(1);
}

Type TypeFactory::dragon()
{
    return createType(2);
}

Type TypeFactory::electric()
{
    return createType(3);
}

Type TypeFactory::fairy()
{
    return createType(4);
}

Type TypeFactory::fight()
{
    return createType(5);
}

Type TypeFactory::fire()
{
    return createType(6);
}

Type TypeFactory::floor()
{
    return createType(7);
}

Type TypeFactory::fly()
{
    return createType(8);
}

Type TypeFactory::ghost()
{
    return createType(9);
}

Type TypeFactory::grass()
{
    return createType(10);
}

Type TypeFactory::ice()
{
    return createType(11);
}

Type TypeFactory::insect()
{
    return createType(12);
}

Type TypeFactory::normal()
{
    return createType(13);
}

Type TypeFactory::poison()
{
    return createType(14);
}

Type TypeFactory::psy()
{
    return createType(15);
}

Type TypeFactory::rock()
{
    return createType(16);
}

Type TypeFactory::steel()
{
    return createType(17);
}

Type TypeFactory::water()
{
    return createType(18);
}
