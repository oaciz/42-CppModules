#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

#include <sstream>
class BitcoinExchange
{
    private:
        std::map<std::string, float> csvRead;
		std::map<std::string, float> argRead;
    public:
        BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange &arg);
        BitcoinExchange(const BitcoinExchange &cpy);
        ~BitcoinExchange();
        void data_read();
		void exchange(const char * arg, int min_year);
		void parser(std::string first, double second, int min_year);
		void double_it_and_give_it_the_next_person(std::string date,double value);
		int min_year();
};


