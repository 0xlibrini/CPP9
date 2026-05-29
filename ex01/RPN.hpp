
#include <iostream>
#include <stack>

class RNP
{
    private:
        std::string _input;
        std::stack<int> _mystack;
        RNP();
    public:
        RNP(std::string input);
        void start_exec();

};