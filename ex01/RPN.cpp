#include "RPN.hpp"

void RNP::start_exec()
{
    std::string ValidInput("0123456789+-/* ");
    for(size_t i(0) ; i < _input.size() ; i++)
    {
        if(ValidInput.find(_input[i]) == std::string::npos) throw "Invalid charactere."
        
    }

}

RNP::RNP(std::string input): _input(input) {start_exec();}

