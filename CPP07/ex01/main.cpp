#include "Iter.hpp"
template <typename T>
void printElement(T const &element)
{
    std::cout <<element << std::endl;
}
int main()
{
    std::cout << "\033[32m------- PRINT INT ELEMENTS -------\033[0m" << std::endl;
    int intArray[] = {1,2,3,4,5};
    iter(intArray, 5, printElement<int>);

    std::cout << "\033[32m------- PRINT DOUBLE ELEMENTS -------\033[0m" << std::endl;
    double doubleArray[] = {1.1, 2.1, 3.1, 4.1, 5.1};
    iter(doubleArray, 5, printElement<double>);

    std::cout << "\033[32m------- PRINT STRING ELEMENTS -------\033[0m" << std::endl;
    std::string stringArray[] = {"elma", "armut", "muz", "çilek", "ayva"};
    iter(stringArray, 5, printElement<std::string>);

    return 0;
}