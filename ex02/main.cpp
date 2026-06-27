#include "PmergeMe.hpp"

int main(int ac , char **av)
{
    if(ac < 2) {std::cout << "Invalid arguments." << std::endl; return 1;}
    try
    {
        PmergeMe  merge(ac , av);
        merge.vec_sort();
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    
}