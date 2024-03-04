#include "Span.hpp"

int main()
{
    Span sp = Span(3);
    try 
    {
        sp.addNumber(4);
        sp.addNumber(7);
        sp.addNumber(6);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}