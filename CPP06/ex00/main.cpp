#include "Convert.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
    }
    else
        std::cout << "ERROR: Enter two arguments" << std::endl;
    return (0);
}