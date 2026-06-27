#include "PmergeMe.hpp"

bool   check_alpha(std::string sub)
{
    for(size_t i(0) ; i < sub.size(); i++)
        if(!isdigit(sub[i])) return 0;
    return 1;
}

int check_range(std::string input)
{
    double value = strtod(input.c_str(),NULL);
    if(value > INT_MAX || value < 0) return 0;
    return 1;
}


PmergeMe::PmergeMe(int ac ,char **av)
{
    for(int i = 1 ; i < ac ; i++)
        parse_input(av[i]);
}
void  PmergeMe::parse_input(std::string av)
{
    std::string input = av;
    {if(!check_range(input)) throw "Error";}
    {if(!check_alpha(input)) throw "Error";}
    deq.push_back(atoi(input.c_str()));
    vec.push_back(atoi(input.c_str()));
}

void PmergeMe::getvec()
{
    for(size_t i = 0 ; i < vec.size(); i++)
        std::cout << deq[i] << std::endl;
}