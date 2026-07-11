#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int>  deq;
        PmergeMe();
    public:
        PmergeMe(int count , char **av);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        void parse_input(std::string  input);
        std::vector<int> vec_sort(std::vector<int> vect);
        std::deque<int> deq_sort(std::deque<int> deq);
        int check_range(std::string input);
};
#endif

