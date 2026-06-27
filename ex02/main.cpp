#include "PmergeMe.hpp"


bool   check_alpha(std::string sub)
{
    std::string valid = "0123456789";
    for(size_t i(0) ; i < sub.size(); i++)
    {
        if(!isdigit(sub[i]))
        {
            return 0;
        }
    }
    return 1;
}

bool check_range(std::string input)
{
    double value = strtod(input.c_str(),NULL);
    if(value > INT_MAX || value < INT_MIN) return 0;
    return 1;
}

void  parse_input(char **av, std::vector<int>& vec)
{
    std::string input = av[1];
    std::string subinput;

    while(1)
    {
        size_t pos = input.find(" ");
        if(pos != std::string::npos)
        {
            subinput = input.substr(0,pos);
            for (size_t i(pos); i < input.size(); i++)
            {
                if (input[i] != ' ' || input[i] != '\t')
                {
                    //std::cout << "is here" << std::endl;
                    break;   
                }     
                input.erase(0, 1);
            }
            if(subinput.empty()) 
            {
                continue;
            }
        }
        else { subinput = input; input.clear();}
        if(!check_alpha(subinput)) throw "Error invalid charactre.";
        if(!check_range(subinput)) throw "Error the numbre is out of range.";
        vec.push_back(std::atoi(subinput.c_str()));
        if(input.empty()) break;
    }
}

int main(int ac , char **av)
{
    if(ac != 2) {std::cout << "Invalid arguments." << std::endl; return 1;}
    std::vector<int> vec;
    try
    {
        parse_input(av,vec);
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    
}