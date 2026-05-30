#include "RPN.hpp"

int main(int ac , char **av)
{
    if(ac != 2) {std::cerr << "Invalid arguments.\n"; return 1;}
    std::string rpn = av[1];
    try
    {
        Rpn _rpn(rpn);
    }
    catch(const char *e)
    {
        std::cerr << e << std::endl;
    }
}