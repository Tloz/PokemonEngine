#include "typetests.h"

int main(int argc, char const *argv[])
{
    std::cout << efficiency(Type::Fire, Type::Grass) << std::endl;
    std::cout << efficiency_text_debug(Type::Fairy, Type::Ghost) << std::endl;
    return 0;
}