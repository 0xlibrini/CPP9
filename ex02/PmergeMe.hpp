#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
#include <cstdlib>
#include <utility>
#include <algorithm>


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
        std::vector<int> vec_sort(std::vector<int> vect);
        std::deque<int> deq_sort(std::deque<int> deq);

        //void make_pairs(std::vector<std::pair<int, int> >&pairs);
};
#endif

