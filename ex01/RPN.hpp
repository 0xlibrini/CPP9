#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <limits.h>

class Rpn
{
    private:
        std::string _input;
        std::stack<int> _mystack;
        Rpn();
    public:
        Rpn(std::string input);
        Rpn(const Rpn& other);
        Rpn& operator=(const Rpn& other);
        ~Rpn();
        void do_operations(char input);
        double get_result();
        void start_exec();

};

#endif