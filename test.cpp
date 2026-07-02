#include <iostream>
#include <vector>

int main()
{

    std::vector<int> jacob;
    std::vector<int> pend;
    //pend.push_back(1);
    //pend.push_back(2);

    int x = 0;
    jacob.push_back(0) ; jacob.push_back(1);
    while( x < pend.size())
    {
        std::cout << "is here" << std::endl;
        x = jacob[jacob.size() - 1] + ( 2 * jacob[jacob.size() - 2] );
        jacob.push_back(x);
    }
    if(jacob[jacob.size() - 1] > pend.size()) jacob.pop_back();
    if(jacob.size() >= 3) jacob.erase(jacob.begin(), jacob.begin() + 3);

    for(size_t i = 0; i < jacob.size(); i++)
    {
        std::cout << jacob[i] << std::endl;
    }
}