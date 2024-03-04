#include "Span.hpp"

Span::Span() : N(0) {}
Span::Span(Span const &other)
{
    *this = other;
}
Span &Span::operator=(Span const &other)
{
    (void)other;
    return *this;
}
Span::~Span() {}

Span::Span(unsigned int N) : N(N) {}

void Span::addNumber(int number)
{
    if (numbers.size() == N)
        throw BoundOfNumbersException();
    numbers.push_back(number);
}

void Span::printNumbers()
{
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::sort(numbers.begin(), numbers.end());
    int min = numbers[1] - numbers[0];
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end() - 1; it++)
    {
        if (min > *(it + 1) - *it)
            min = *(it + 1) - *it;
    }
    return min;
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::sort(numbers.begin(), numbers.end());
    return numbers[numbers.size() - 1] - numbers[0];
}

void Span::addNumbers()
{
    srand(time(NULL));
    for (unsigned int i = 0; i < this->N; i++)
    {
        this->numbers.push_back(rand());
    }
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    else if (numbers.size() == N )
        throw BoundOfNumbersException();
}