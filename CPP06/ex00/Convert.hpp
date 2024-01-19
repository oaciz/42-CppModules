#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>

class ScalarConverter 
{
    private:
        static int getInt(int val);
        static double doubleCasting(double val);
        static float  floatCasting(float val);
        static char   charCasting(int val);

    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);

    static void convert(const std::string &input);
};