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

void  parse_input(std::string av, std::vector<int>& vec)
{
    std::string input = av;
    {if(!check_range(input)) throw "Error";}
    {if(!check_alpha(input)) throw "Error";}
    vec.push_back(atoi(input.c_str()));
}

int main(int ac , char **av)
{
    if(ac < 2) {std::cout << "Invalid arguments." << std::endl; return 1;}
    std::vector<int> vec;
    try
    {
       for(int i = 1; i < ac ; i++)
            parse_input(av[i],vec);
     for(size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl; 
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    
}