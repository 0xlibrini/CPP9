#include "PmergeMe.hpp"

int find_pair(std::deque<std::pair<int,int> > pairs, int target)
{
    for(size_t i(0) ; i < pairs.size() ; i++)
        if(pairs[i].first == target) return pairs[i].second;
    return -1;
}
int get_index(int value , std::deque<int> mainchain)
{
   return  std::distance(mainchain.begin(), std::find(mainchain.begin(), mainchain.end(), value));
}
void insert_pendchain(std::deque<int> &mainchain, std::deque<int> &pendchain,std::deque<int> jacob, int extra,std::deque<std::pair<int,int> > pairs)
{
    mainchain.insert(mainchain.begin(), pendchain[0]);
    pendchain.erase(pendchain.begin());
    std::deque<int>::iterator it;
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
std::deque<int> JP_seq(std::deque<int> pend)
{
    std::deque<int>jacob;
    size_t x = 0;
    jacob.push_back(0) ; jacob.push_back(1);
    while( x < pend.size())
    {
        x = jacob[jacob.size() - 1] + ( 2 * jacob[jacob.size() - 2] );
        jacob.push_back(x);
    }
    if(jacob[jacob.size() - 1] > static_cast<int>(pend.size())) jacob.pop_back();
    if(jacob.size() >= 3) jacob.erase(jacob.begin(), jacob.begin() + 3);
    
    std::deque<int> exp_jacob;
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
void   rearranging_pend(std::deque<int> new_main, std::deque<int> &mainchain, std::deque<int> &pendchain, int extra)
{
    std::deque<int> new_pend;
    for(size_t i = 0 ; i < new_main.size() ; i++)
            new_pend.push_back(pendchain[get_index(new_main[i], mainchain)]);
    mainchain = new_main;
    pendchain = new_pend;
    if(extra != -1) pendchain.push_back(extra);
}
void make_pairs(std::deque<int> deq , std::deque<std::pair<int,int> > &pairs)
{
    for(size_t i = 0 ; i < deq.size() ; i += 2) pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
}
void swap_pairs(std::deque<std::pair<int , int> > &pair)
{
    for(size_t i = 0 ; i < pair.size() ; i++)
        if(pair[i].first > pair[i].second) std::swap(pair[i].first , pair[i].second);
}
void set_chaine(std::deque<int> &mainchain , std::deque<int> &pendchain,std::deque<std::pair<int , int> > & pairs)
{
    for(size_t i  = 0 ; i < pairs.size() ; i++) {pendchain.push_back(pairs[i].first) ; mainchain.push_back(pairs[i].second);}
}

std::deque<int> PmergeMe::deq_sort(std::deque<int> deq)
{
    if(deq.size() == 1) return deq;
    if(deq.size() == 2){ if(deq[0] > deq[1]) std::swap(deq[0], deq[1]); return deq;}
    int extra  = -1;
    if(deq.size() % 2) { extra  = deq[deq.size() - 1] ; deq.erase(deq.end() - 1);}
    std::deque<std::pair<int,int> > pairs;
    make_pairs(deq,pairs);
    swap_pairs(pairs);
    std::deque<int> mainchain;
    std::deque<int> pendchain;
    set_chaine(mainchain, pendchain, pairs);
    if(extra != -1) pendchain.push_back(extra);
    std::deque<int> new_main = deq_sort(mainchain);
    std::deque<int>jacob = JP_seq(pendchain);
    rearranging_pend(new_main,mainchain, pendchain, extra);
    insert_pendchain(mainchain, pendchain,jacob,extra,pairs);
    return mainchain;
}