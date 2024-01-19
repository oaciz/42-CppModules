#include "Convert.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
   *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    return *this;
}

int ScalarConverter::getInt(int val) 
{
    return val;
}

char ScalarConverter::charCasting(int val)
{
    char c = static_cast<char>(val);
    if (!std::isprint(c))
        std::cout << "Char: Non displayble character" << std::endl;
    else
        std::cout << "Char: " << c << std::endl;
    return c;
}

double ScalarConverter::doubleCasting(double val)
{
    if (std::isnan(val) || std::isinf(val))
        std::cout << "Double: nan" << std::endl;
    else
        std::cout << "Double: " << val << (val == static_cast<int>(val) ? ".0" : "") << std::endl;
    return val;
}

float ScalarConverter::floatCasting(float val)
{
    if (std::isnan(val) || std::isinf(val))
        std::cout << "Float: nanf" << std::endl;
    else
        std::cout << "Float: " << val << (val == static_cast<int>(val) ? ".0f" : "f") << std::endl;
    return val;
}

void ScalarConverter::convert(const std::string &inp)
{
     size_t dotCount = std::count(inp.begin(), inp.end(), '.');
    if (dotCount > 1)
    {
        std::cout << "ERROR: Invalid number format" << std::endl;
        return;
    }

    for (size_t i = 0; i < inp.size(); i++)
    {
        if (!isdigit(inp[i]) && !(inp == "nan"))
        {
            std::cout << "ERROR: Invalid number format" << std::endl;
            return;
        }    
    }
    
    try
    {
        int x = std::stoi(inp);
        char c = charCasting(x); 
    }
    catch(const std::exception& e)
    {
        std::cout << "char: Impossible" << std::endl;
    }

    try
    {
        int intVal = std::stoi(inp);
        intVal = getInt(intVal);
        std::cout << "int: " << intVal << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cout << "int: Impossible" << std::endl;
    }

    try
    {
        float floatVal = std::stof(inp);
        floatVal = floatCasting(floatVal);
    }
    catch(const std::exception& e)
    {
        std::cout << "Float: Impossible" << std::endl;
    }
    try
    {
        double doubleVal = std::stod(inp);
        doubleVal = doubleCasting(doubleVal);
    }
    catch(const std::exception& e)
    {
        std::cout << "Double: Impossible" << std::endl;
    }
    
}

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f

double: 42.0


45.45.66
45.
45a5


*/
