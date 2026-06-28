#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

bool   check_alpha(std::string sub)
{
    for(size_t i(0) ; i < sub.size(); i++) if(!isdigit(sub[i])) return 0;
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
    for(int i = 1 ; i < ac ; i++) parse_input(av[i]);
}
void  PmergeMe::parse_input(std::string av)
{
    std::string input = av;
    {if(!check_range(input)) throw "Error";}
    {if(!check_alpha(input)) throw "Error";}
    deq.push_back(atoi(input.c_str()));
    vec.push_back(atoi(input.c_str()));
}

void PmergeMe::make_pairs(std::vector<std::pair<int,int> > &pairs)
{
    for(size_t i = 0 ; i < vec.size() ; i+= 2) pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
}
void swap_pairs(std::vector<std::pair<int , int> > &pair)
{
    for(size_t i = 0 ; i < pair.size() ; i++)
        if(pair[i].first > pair[i].second) std::swap(pair[i].first , pair[i].second);
}
void PmergeMe::vec_sort()
{
    int extra  = -1;
    if(vec.size() % 2) { extra  = vec[vec.size() - 1] ; vec.erase(vec.end() - 1);}
    std::vector<std::pair<int,int> > pairs;
    make_pairs(pairs);
    swap_pairs(pairs);
    for(size_t i = 0 ; i < pairs.size() ; i++)
        std::cout << pairs[i].first << "  " << pairs[i].second << std::endl;\
    
}
