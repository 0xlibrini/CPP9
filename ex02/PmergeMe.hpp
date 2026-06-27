#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
#include <cstdlib>


class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int>  deq;
        PmergeMe();
    public:
        PmergeMe(int count , char **av);
        ~PmergeMe();
        void parse_input(std::string  input);


};
#endif

