#include "RPN.hpp"

int main(int ac , char **av)
{
    if(ac != 2) {std::cerr << "Invalid arguments.\n"; return 1;}
    std::string rpn = av[1];
    
    try { Rpn _rpn(rpn); std::cout << _rpn.get_result() << std::endl;}
    catch(const char *e) {std::cerr << "Error: " << e << std::endl;}

}