#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> pend;


    pend.push_back(1);
    pend.push_back(3);
    // pend.push_back(10);
    // pend.push_back(12);
    // pend.push_back(5);
    // pend.push_back(5);
    // pend.push_back(5);
    // pend.push_back(5);
    // pend.push_back(5);
    // pend.push_back(5);
    // pend.push_back(5);


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
    for(size_t i = 0 ; i < jacob.size() ; i++)
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
        //std::cout << pend.size() << std::endl;
        size_t x  = pend.size();
        while( x > 1)
        {
            if(std::find(exp_jacob.begin(), exp_jacob.end(), x) != exp_jacob.end()) break;
            exp_jacob.push_back(x);
            x--;
        }
    }

    for(size_t i (0) ; i < exp_jacob.size() ; i++)
    {
        std::cout << exp_jacob[i] << std::endl;
    }
}