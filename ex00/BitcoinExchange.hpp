#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::fstream _input;
        std::map<std::string, float> _dataset;
        BitcoinExchange();
    public:
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        BitcoinExchange(std::string input, std::map<std::string , float>dataset);
        bool parsedate(std::string date);
        void Startexchange();
};
#endif