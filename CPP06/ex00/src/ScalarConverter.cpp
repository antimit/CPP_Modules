#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
    std::cout<<"ScalarConverter default constructor was called"<<std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    (void)src;
    std::cout<<"Scalar copy constructor was called"<<std::endl;
}


ScalarConverter::~ScalarConverter()
{
    std::cout<<"ScalarConverter default destructor was called"<<std::endl;
}


ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
    if(this !=&src)
        return *this;
    return *this;
}


bool ScalarConverter::isChar(const std::string & representation)
{
    return (representation.size() == 1 && std::isprint(representation[0]) && !isdigit(representation[0]));
}

bool ScalarConverter::isInteger(const std::string & representation)
{
    const size_t sign = representation.find('-');

    if(sign != 0 && sign != std::string::npos)
        return false;

    if(representation.find_first_not_of("0123456789", sign != std::string::npos ? 1 : 0) != std::string::npos)
    {
        return false;
    }

    return true;
}


bool ScalarConverter::isFloat(const std::string & representation)
{
    const size_t sign = representation.find('-');

    if(sign != 0 && sign != std::string::npos)
        return false;
    
    const size_t dot = representation.find('.');
    if(dot == std::string::npos)
        return false;
    
    if(representation[representation.size() -1] != 'f')
        return false;
    
    const size_t index = sign == 0 ? 1 : 0;

    const std::string decimalPart = representation.substr(index, dot - index);

    const std::string fractionalPart = representation.substr(dot +1, representation.size() - dot -1);

    if(decimalPart.find_first_not_of("0123456789") || fractionalPart.find_first_not_of("0123456789"))
        return false;
    
    return(!decimalPart.empty() && !fractionalPart.empty());
}

bool ScalarConverter::isDouble(const std::string & representation)
{
    const size_t sign = representation.find('-');

    if(sign != 0 && sign != std::string::npos)
        return false;

    const size_t dot = representation.find('.');
    if(dot == std::string::npos)
        return false;
    
    const size_t index = sign == 0 ? 1 : 0;

    const std::string decimalPart = representation.substr(index, dot - index);

    const std::string fractionalPart = representation.substr(dot + 1, representation.size() - dot - 1);

    if(decimalPart.find_first_not_of("0123456789") || fractionalPart.find_first_not_of("0123456789"))
        return false;
    
    return(!decimalPart.empty() && !fractionalPart.empty());
}

bool ScalarConverter::isInfinite(const std::string & representation)
{
    if(representation == "-inff" || representation == "+inff" || representation == "nanf"
    || representation == "-inf" || representation == "+inf" || representation == "nan")
    {
        return true;
    }
    return false;
}

void ScalarConverter::convertToNumber(const std::string & representation, long double number)
{
    if(number < std::numeric_limits<char>::min() || number > std::numeric_limits<char>::max())
    {
        std::cout<<"char: overflows"<<std::endl;
    }
    else
        convertToChar(static_cast<char>(number));

    if(number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
        std::cout<<"int: overflows"<<std::endl;
    else
        std::cout<<"int: "<<std::atoi(representation.c_str()) <<std::endl;
    
    if(number < std::numeric_limits<float>::min() || number > std::numeric_limits<float>::max())
        std::cout<<"float overflows"<<std::endl;
    else
        std::cout<<"float: "<<std::atof(representation.c_str())<<std::endl;
    
    if(number < std::numeric_limits<double>::min() || number > std::numeric_limits<double>::max())
        std::cout<<"double overflows"<<std::endl;
    else
        std::cout<<"double: "<<std::strtod(representation.c_str(), NULL)<<std::endl;
}

void ScalarConverter::convertFromInfinite(const std::string & representation)
{
    std::cout<<"char: impossible"<<std::endl;
    std::cout<<"int: impossible"<<std::endl;

    if(representation.find("nan") != std::string::npos)
    {
        std::cout<<"float: nanf" <<std::endl;
        std::cout<<"double: nan"<<std::endl;
    }
    else
    {
        std::cout<<"float: "<<representation[0]<< "inff"<<std::endl;
        std::cout<<"double: "<<representation[0] << "inf"<<std::endl;
    }
}


void ScalarConverter::convertFromChar(const std::string & representation)
{
    convertToChar(representation[0]);

    std::cout<<"int: "<<static_cast<int>(representation[0])<<std::endl;

    std::cout<<"float: "<<static_cast<float>(representation[0])<<"f"<<std::endl;
    std::cout<<"double: "<<static_cast<double>(representation[0])<<std::endl;
}

void ScalarConverter::convertToChar(const char &c)
{
    if(std::isprint(c))
    {
        std::cout<<"char: "<<"'"<<c<<"'"<<std::endl;
    }
    else
    {
        std::cout<<"char: Non displayable"<<std::endl;
    }
}

void ScalarConverter::convert(const std::string & representation)
{
    if(isChar(representation))
        convertFromChar(representation);
    
    else if(isInteger(representation))
    {
        convertToNumber(representation, std::strtold(representation.c_str(), NULL));
    }

    else if(isDouble(representation))
    {
        convertToNumber(representation, std::strtold(representation.c_str(), NULL));
    }
    else if(isInfinite(representation))
    {
        convertFromInfinite(representation);
    }
    else
    {
        std::cout<<"Uknown type"<<std::endl;
    }
}