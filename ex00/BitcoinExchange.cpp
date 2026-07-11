#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {_dataset = other._dataset;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {if(this != &other) _dataset = other._dataset; return *this;}

bool  isdigits(std::string name)
{
    for(size_t i = 0; i < name.size() ; i++) {if (!isdigit(name[i])) return false;} return true;
}

bool is_leap(int year)
{
    if((year % 4 == 0  && year % 100 != 0 ) || year % 400 == 0) {return true;} return  false;
}
bool   BitcoinExchange::parsedate(std::string date)
{
    size_t sep = date.find("-");
    if(sep == std::string::npos) return false;

    std::string year = date.substr(0,sep);
    date.erase(0,sep + 1);
    
    sep = date.find("-");
    if(sep == std::string::npos) return false;
    std::string month = date.substr(0,sep);
    date.erase(0, sep + 1);
    std::string day = date.substr(0);
    
    if(year.size() != 4 || !isdigits(year)) return false;
    if(month.size() != 2 || !isdigits(month)) return false;
    if(day.size() != 2 || !isdigits(month)) return false;
    if(month  < "01" || month > "12") return false;

    if(month == "02")
    {
        if(is_leap(std::atoi(year.c_str()))) { if(day < "01"|| day > "29") return false;}
        else if(day < "01" || day > "28") return false;
    }
    else
    {
        if(month == "01" || month == "03" || month == "05" || month == "07" || month == "08" 
                     || month == "10" || month == "12") { if(day < "01"|| day > "31") return false;}
        else if(day < "01"|| day > "30") return false;
    }
    return true;
}
std::string parse_value(std::string value)
{
    char *end = NULL;
    double val = strtod(value.c_str(), &end);
    if(*end) return "bad input.";
    if(val > 1000) return "too large a number.";
    if(val < 0) return "not a positive number.";
    return "";
}
double    extract_value(std::string date, std::map<std::string ,float>dataset)
{
   std::map<std::string , float>::iterator it = dataset.lower_bound(date);
   if(it == dataset.end() || (it == dataset.begin() && it->first != date))
        {throw "Error: out of range.";}
    if(it->first != date) it--;
    return it->second;
}
void    BitcoinExchange::Startexchange()
{
    std::string line;
    if(!_input.is_open()) throw "file cannot open.";

    getline(_input , line);
    if(line != "date | value") throw "bad input.";
    while(getline(_input,line))
    {
        size_t pos  = line.find("|");
        if(pos == std::string::npos) {std::cout << "Error: bad input: => " + line << std::endl; continue;}

        std::string date = line.substr(0,pos);
        std::string value = line.substr(pos + 1);

        if(date[date.size() - 1] != ' ' || value[0] != ' ') {std::cout << "Error: bad input: => " + line << std::endl; continue;}
        date.erase(date.size() - 1);
        value.erase(0,1);

        if(!parsedate(date)) {std::cout << "Error: bad input: => " + line << std::endl; continue;}
        std::string message = parse_value(value);
        if(!message.empty()) {
            if(message == "bad input.") std::cout << "Error: " + message + ": => "  + line << std::endl; 
            else std::cout << "Error: " + message << std::endl; 
            continue;}
                                
        try
        {
            float val = extract_value(date,_dataset);
            val *= atof(value.c_str());
            std::cout << date << " => " << value + " = " << val << std::endl;
        }
        catch(const char *e)
        {
            std::cout << e << std::endl;
        }
    }
}
BitcoinExchange::BitcoinExchange(std::string input , std::map<std::string ,float>dataset) : _input(input.c_str()) 
    , _dataset(dataset) { Startexchange();}
