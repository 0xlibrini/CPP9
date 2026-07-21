#include "BitcoinExchange.hpp"

void    parse_dataset(std::map<std::string , float>&data)
{
    std::ifstream input("data.csv");
    if(!input.is_open()) throw "file cannot open";
    std::string line;
    getline(input,line);
    while(getline(input, line)) { size_t pos = line.find(","); data[line.substr(0,pos)] = atof(line.substr(pos + 1).c_str());}
}

int main(int ac , char **av)
{
    if(ac != 2) {std::cout << "Error: could not open file.\n" ; return 1;}
    std::map<std::string ,float> dataset;
    try
    {
        parse_dataset(dataset);
        BitcoinExchange btc(av[1] , dataset);
    }
    catch(const char *e)
    {
        std::cerr << e <<  '\n';
    }
    


}