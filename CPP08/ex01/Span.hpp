#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
class Span
{
private:
    unsigned int N;
    std::vector<int> numbers;
public:
    Span();
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();
    Span(unsigned int N);
    void addNumber(int number);
    void printNumbers();
    int shortestSpan();
    int longestSpan();
    void addNumbers();
    class BoundOfNumbersException : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Number of elements is at maximum.");
            };
    };
    class NotEnoughNumbersException : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Not numbers to calculate span.");
            };
    };
};

#endif