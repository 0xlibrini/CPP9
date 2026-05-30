#include "RPN.hpp"

void Rpn::do_operations(char input)
{
    if(_mystack.size() <= 1) throw "Size of element is not enough.";
    int a, b, result;
    
    b = _mystack.top();
     _mystack.pop();
    a = _mystack.top();
    _mystack.pop();
    
    if(input == '+') result = a + b;
    else if(input == '-') result = a - b;
    else if(input == '*') result = a * b;
    else if(input == '/') { if(!b) throw "division by zero"; result = a / b;}

    _mystack.push(result);

}
void Rpn::start_exec()
{
    std::string ValidInput("0123456789+-/* ");
    for(size_t i(0) ; i < _input.size() ; i++) // 2 2 
    {
        if(ValidInput.find(_input[i]) == std::string::npos) throw "Invalid charactere.";
        if(std::isdigit(_input[i])) {if(_input[i + 1] != ' ') throw "Invalid order."; _mystack.push(_input[i] - '0');}
        else if(_input[i] != ' ') do_operations(_input[i]);
    }

}

Rpn::Rpn(std::string input): _input(input) {start_exec();}

