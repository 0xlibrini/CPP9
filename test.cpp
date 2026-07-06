#include <iostream>
#include <unistd.h>
#include <vector>



int main()
{
    std::vector<int> pairs;

    int second = -1;

    pairs.push_back(0);
    pairs.push_back(1);
    pairs.push_back(2);
   // pairs.push_back(3);

    auto it = std::lower_bound(pairs.begin(), pairs.end(), 4);



    std::cout << it - pairs.begin() << std::endl;
}