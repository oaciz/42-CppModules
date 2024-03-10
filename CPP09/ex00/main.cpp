#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    BitcoinExchange a;
	int min_year;

    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (0);
    }
    a.data_read();
	min_year = a.min_year();
	a.exchange(argv[1], min_year);
}