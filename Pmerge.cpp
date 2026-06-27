#include <vector>
#include <iostream>

std::vector<std::pair<int, int> >   pairedList(std::vector<int> vec)
{
    std::vector<std::pair<int, int>>    res;
    size_t  i(0);

    while (i < vec.size())
    {
        if (vec[i] < vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
        res.push_back(std::make_pair(vec[i], vec[i + 1]));
        i += 2;
    }
    return res;
}

std::vector<int>    sort_algo(std::vector<int> vec)
{
    std::vector<int>    mainChain;
    std::vector<int>    pendinChain;
    int                 unpaired(-1);

    size_t  size = vec.size();
    if (size > 2 && size % 2 != 0)
    {
        unpaired = vec[size - 1];
        vec.erase(vec.end() - 1);
        size--;
    }
    if (size <= 2)
    {
        if (size == 2 && vec[0] > vec[1])
            std::swap(vec[0], vec[1]);
        if (unpaired != -1)
        {
            std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), unpaired);
            vec.insert(it, unpaired);
        }
        return vec;
    }
    std::vector<std::pair<int, int> >   paires = pairedList(vec);
    for (size_t i(0); i < paires.size(); i++)
    {
        mainChain.push_back(paires[i].first);
        pendinChain.push_back(paires[i].second);
    }
    mainChain = sort_algo(mainChain);
    if (!pendinChain.empty()) {
        mainChain.insert(mainChain.begin(), pendinChain[0]);
    }
    std::vector<int>    jacoblist = jacobstahlsequence();
    std::vector<bool>   inserted(pendinChain.size(), false);
    for (size_t i(0); i < jacoblist.size(); i++)
    {
        int idx = jacoblist[i];
        if (idx >= pendinChain.size()) continue;
        if (inserted[idx]) continue;
        std::vector<int>::iterator  it = std::lower_bound(mainChain.begin(), mainChain.end(), pendinChain[idx]);
        mainChain.insert(it, pendinChain[idx]);
        inserted[idx] = true;
        for (size_t i(idx - 1); idx >= 0; i--)
        {
            if (!inserted[i])
            {
                std::vector<int>::iterator  it = std::lower_bound(mainChain.begin(), mainChain.end(), pendinChain[i]);
                mainChain.insert(it, pendinChain[i]);
                inserted[i] = true;
            }
        }
    }
    for (size_t i(0); i < pendinChain.size(); i++)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator  it = std::lower_bound(mainChain.begin(), mainChain.end(), pendinChain[i]);
            mainChain.insert(it, pendinChain[i]);
            inserted[i] = true;
        }
    }
    if (unpaired != 1)
    {
        std::vector<int>::iterator  it = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(it, unpaired);
    }
    return mainChain;
}

int main(int ac , char **av)
{
    if(ac < 2) {std::cout << "Error" << std::endl; return 0;}
    std::vector<int> vec;
    for(int i(1); i < ac ; i++) 
        vec.push_back(std::atoi(av[i]));
    std::vector<int>    result = sort_algo(vec);
}