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

    // clock_t start1 = std::clock();
    vec_sort(vec);
    // clock_t end1 = std::clock();

    // clock_t start2 = clock();
    // std::deque<int> s_deq = deq_sort(deq);
    // clock_t end2 = clock();

    // std::cout << "Before: ";

    // for(size_t i = 0 ; i < vec.size(); i++)
    //     std::cout << vec[i] << " " ;
    // std::cout << std::endl;

    // std::cout << "After: ";

    // for(size_t i = 0 ; i < vec.size(); i++)
    //     std::cout << vect[i] << " " ;
    // std::cout << std::endl;

    double time_vec =  (_time / CLOCKS_PER_SEC) * 1000000.00;
   // double time_deq =  (double)(end2 - start2) / CLOCKS_PER_SEC * 1000000;
     std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of 5 elements with std::[vector] " << time_vec << std::endl;
    //std::cout << "Time to process a range of 5 elements with std::[deque ] " << time_deq << std::endl;
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
    
    std::vector<int> exp_jacob;
    for(size_t i (0) ; i < jacob.size() ; i++)
    {
        int x = jacob[i];
        while( x > 1)
        {
            if(std::find(exp_jacob.begin(), exp_jacob.end(), x) != exp_jacob.end()) break;
            exp_jacob.push_back(x);
            x--;
        }
    }
    if(exp_jacob.size() + 1 != pend.size())
    {
        size_t x  = pend.size();
        while( x > 1)
        {
            if(std::find(exp_jacob.begin(), exp_jacob.end(), x) != exp_jacob.end()) break;
            exp_jacob.push_back(x);
            x--;
        }
    }
    return exp_jacob;
}

int get_index(int value , std::vector<int> mainchain)
{
   return  std::distance(mainchain.begin(), std::find(mainchain.begin(), mainchain.end(), value));
}
void   rearranging_pend(std::vector<int> new_main, std::vector<int> &mainchain, std::vector<int> &pendchain, int extra)
{
    std::vector<int> new_pend;
    for(size_t i = 0 ; i < new_main.size() ; i++)
            new_pend.push_back(pendchain[get_index(new_main[i], mainchain)]);
    mainchain = new_main;
    pendchain = new_pend;
    if(extra != -1) pendchain.push_back(extra);
}


int find_pair(std::vector<std::pair<int,int> > pairs, int target)
{
    for(size_t i(0) ; i < pairs.size() ; i++)
        if(pairs[i].first == target) return pairs[i].second;
    return -1;
}
void insert_pendchain(std::vector<int> &mainchain, std::vector<int> &pendchain,std::vector<int> jacob, int extra,std::vector<std::pair<int,int> > pairs)
{
    mainchain.insert(mainchain.begin(), pendchain[0]);
    pendchain.erase(pendchain.begin());
    std::vector<int>::iterator it;
    for(size_t i = 0; i < jacob.size(); i++)
    {
        int index = jacob[i] - 2;
        int value = pendchain[index];
        if(value == extra) it = std::lower_bound(mainchain.begin() , mainchain.end(), value);
        else
        {
            int second = find_pair(pairs, value);
            int range = get_index(second , mainchain);
            it = std::lower_bound(mainchain.begin() , mainchain.begin() + range , value);
        }
        mainchain.insert(it, value);
    }
}
std::vector<int> PmergeMe::vec_sort(std::vector<int>& vect)
{

    clock_t start = std::clock();
    if(vect.size() == 1) return vect;
    if(vect.size() == 2){ if(vect[0] > vect[1]) std::swap(vect[0], vect[1]); return vect;}
    int extra  = -1;
    if(vect.size() % 2) { extra  = vect[vect.size() - 1] ; vect.erase(vect.end() - 1);}
    std::vector<std::pair<int,int> > pairs;
    make_pairs(vect,pairs);
    swap_pairs(pairs);
    std::vector<int> mainchain;
    std::vector<int> pendchain;
    set_chaine(mainchain, pendchain, pairs);
    if(extra != -1) pendchain.push_back(extra);
    std::vector<int> new_main = vec_sort(mainchain);
    std::vector<int>jacob = JP_seq(pendchain);
    rearranging_pend(new_main,mainchain, pendchain, extra);
    insert_pendchain(mainchain, pendchain,jacob,extra,pairs);
    _time = std::clock() - start; 
    return mainchain;
}
