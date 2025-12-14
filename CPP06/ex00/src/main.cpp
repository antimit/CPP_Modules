#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
        return 0;
    }

    std::cout << "--- Char tests ---" << std::endl;
    ScalarConverter::convert("a");
    std::cout << std::endl;
    ScalarConverter::convert("*");
    std::cout << std::endl;

    std::cout << "--- Int tests ---" << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;
    ScalarConverter::convert("42");
    std::cout << std::endl;
    ScalarConverter::convert("-42");
    std::cout << std::endl;

    std::cout << "--- Float tests ---" << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << std::endl;
    ScalarConverter::convert("-4.2f");
    std::cout << std::endl;

    std::cout << "--- Double tests ---" << std::endl;
    ScalarConverter::convert("42.0");
    std::cout << std::endl;
    ScalarConverter::convert("-4.2");
    std::cout << std::endl;

    std::cout << "--- Pseudo-literals ---" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;

    std::cout << "--- Invalid ---" << std::endl;
    ScalarConverter::convert("abc");
    std::cout << std::endl;
    ScalarConverter::convert("");
    std::cout << std::endl;

    return 0;
}