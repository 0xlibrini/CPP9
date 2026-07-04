#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int get_index(int value , std::vector<int> mainchain)
{
   return  std::distance(mainchain.begin(), std::find(mainchain.begin(), mainchain.end(), value));
}

int main()
{


    
    std::vector<int> new_pend;

    vector<int> new_main;
    new_main.push_back(2);
    new_main.push_back(3);
    new_main.push_back(5);
    new_main.push_back(6);



     vector<int> mainchain;
    mainchain.push_back(3);
    mainchain.push_back(2);
    mainchain.push_back(5);
    mainchain.push_back(6);


    vector<int> pendchain;
    pendchain.push_back(1);
    pendchain.push_back(0);
    pendchain.push_back(15);
    pendchain.push_back(20);

        for(size_t i = 0 ; i < new_main.size() ; i++)
        {
            new_pend.push_back(pendchain[get_index(new_main[i], mainchain)]);
        }
    

    for(size_t i = 0 ; i < new_pend.size(); i++)
    {
        std::cout << new_pend[i] << std::endl;
    }
}