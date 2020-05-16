#include "../../inc/type.h"
#include "../../inc/typefactory.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    int id = 11;
    if(argc >= 2)
    {
        id = atoi(argv[1]);
    }
    try
    {
        Type t = TypeFactory::createType(id);
        t.print();
    }
    catch(exception const& e)
    {
        cerr << "Error: " << e.what() << endl;
        cerr << "ABORTING" << endl;
        return -1;
    }
    return 0;
}