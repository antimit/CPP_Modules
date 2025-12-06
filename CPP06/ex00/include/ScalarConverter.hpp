
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include<iostream>


class  ScalarConverter
{
    private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter & operator=(ScalarConverter const & src);
    virtual ~ScalarConverter() = 0;

    static bool isChar(const std::string & representation);

    static bool isInteger(const std::string & representation);

    static bool isFloat(const std::string & representation);

    static bool isDouble(const std::string & representation);

    static bool isInfinite(const std::string & representation);


    static void convertToNumber(const std::string & representation, long double number);

    static void convertFromInfinite(const std::string & representation);

    static void convertFromChar(const std::string & representation);

    static void convertToChar(const char &c);


    public:

    static void convert(const std::string & representation);

};


#endif