#include "RPN.hpp"

void Rpn::do_operations(char input)
{
    if(_mystack.size() <= 1) throw "Size of element is not enough.";
    long a, b;
    long result;
    
    b = _mystack.top();
     _mystack.pop();
    a = _mystack.top();
    _mystack.pop();

    if(input == '+') result = a + b;
    else if(input == '-') result = a - b;
    else if(input == '*') result = a * b;
    else if(input == '/') { if(!b) throw "division by zero"; result = a / b;}
    if(result > INT_MAX || result < INT_MIN) throw "operation is out of range.";

    _mystack.push(result);
}
void Rpn::start_exec()
{
    std::string ValidInput("0123456789+-/* ");
    for(size_t i(0) ; i < _input.size() ; i++)
    {
        if(ValidInput.find(_input[i]) == std::string::npos) throw "Invalid character.";
        if(std::isdigit(_input[i])) {if(_input[i + 1] != ' ') throw "Invalid order."; _mystack.push(_input[i] - '0');}
        else if(_input[i] != ' ') do_operations(_input[i]);
    }
}
double  Rpn::get_result()
{
    if(_mystack.size() == 1) return _mystack.top();
    std::cout << _mystack.size() << std::endl;
    throw "Wrong expression.";
}
Rpn::Rpn(std::string input): _input(input) {start_exec();}

