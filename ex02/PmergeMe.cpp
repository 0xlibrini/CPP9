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
    std::vector<int>vect = vec;
    vect = vec_sort(vect);

    for(size_t i = 0 ; i < vect.size(); i++)
        std::cout << vect[i] << std::endl;
}
void  PmergeMe::parse_input(std::string av)
{
    std::string input = av;
    {if(!check_range(input)) throw "Error";}
    {if(!check_alpha(input)) throw "Error";}
    deq.push_back(atoi(input.c_str()));
    vec.push_back(atoi(input.c_str()));
}

void make_pairs(std::vector<int> vect , std::vector<std::pair<int,int> > &pairs)
{
    for(size_t i = 0 ; i < vect.size() ; i += 2) pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
}
void swap_pairs(std::vector<std::pair<int , int> > &pair)
{
    for(size_t i = 0 ; i < pair.size() ; i++)
        if(pair[i].first > pair[i].second) std::swap(pair[i].first , pair[i].second);
}

void set_chaine(std::vector<int> &mainchain , std::vector<int> &pendchain,std::vector<std::pair<int , int> > & pairs)
{
    for(size_t i  = 0 ; i < pairs.size() ; i++) {pendchain.push_back(pairs[i].first) ; mainchain.push_back(pairs[i].second);}
}

std::vector<int> JP_seq(std::vector<int> pend)
{
    std::vector<int>jacob;
    size_t x = 0;
    jacob.push_back(0) ; jacob.push_back(1);
    while( x < pend.size())
    {
        x = jacob[jacob.size() - 1] + ( 2 * jacob[jacob.size() - 2] );
        jacob.push_back(x);
    }
    if(jacob[jacob.size() - 1] > static_cast<int>(pend.size())) jacob.pop_back();
    if(jacob.size() >= 3) jacob.erase(jacob.begin(), jacob.begin() + 3);

    return jacob;
}
std::vector<int> PmergeMe::vec_sort(std::vector<int> vect)
{
    int extra  = -1;
    if(vect.size() % 2) { extra  = vect[vect.size() - 1] ; vect.erase(vect.end() - 1);}
    std::vector<std::pair<int,int> > pairs;
    make_pairs(vect,pairs);
    swap_pairs(pairs);
    std::vector<int> mainchain;
    std::vector<int> pendchain;
    set_chaine(mainchain, pendchain, pairs);
    if(extra != -1) pendchain.push_back(extra);
    if(mainchain.size() == 1) {
        mainchain.insert(mainchain.begin(),*(pendchain.begin())); 
        return mainchain;
    }
    vec_sort(mainchain);
    std::vector<int>jacob = JP_seq(pendchain);
    for( size_t i = 0; i < jacob.size(); i++)
        std::cout << jacob[i] << std::endl;
    return mainchain;
}
