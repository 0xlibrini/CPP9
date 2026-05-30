
#include <iostream>
#include <stack>

class Rpn
{
    private:
        std::string _input;
        std::stack<int> _mystack;
        Rpn();
    public:
        Rpn(std::string input);
        void do_operations(char input);
        void start_exec();

};