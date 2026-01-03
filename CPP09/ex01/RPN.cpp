#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>

const std::string RPN::s_valid_operations = "+-/*";

RPN::RPN() {}

RPN::RPN(const RPN& other) { (void)other; }

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::solve(const std::string& input)
{
    if (_evaluate(input) == error)
    {
        std::cerr << "Error\n";
        return error;
    }
    return ok;
}

enum RPN::e_status RPN::_evaluate(const std::string& input)
{
    std::stack<int> values;
    std::istringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (_is_number(token))
        {
            values.push(std::atoi(token.c_str()));
        }
        else if (_is_operator(token))
        {
            if (_apply_operation(values, token[0]) == error)
                return error;
        }
        else
            return error;
    }
    if (values.size() != 1)
        return error;
    std::cout << values.top() << "\n";
    return ok;
}

enum RPN::e_status RPN::_apply_operation(std::stack<int>& values, char op) const
{
    if (values.size() < 2)
        return error;
    const int rhs = values.top();
    values.pop();
    const int lhs = values.top();
    values.pop();

    switch (op)
    {
    case '+':
        values.push(lhs + rhs);
        break;
    case '-':
        values.push(lhs - rhs);
        break;
    case '*':
        values.push(lhs * rhs);
        break;
    case '/':
        if (rhs == 0)
            return error;
        values.push(lhs / rhs);
        break;
    default:
        return error;
    }
    return ok;
}

bool RPN::_is_operator(const std::string& token) const
{
    return token.size() == 1 && s_valid_operations.find(token[0]) != std::string::npos;
}

bool RPN::_is_number(const std::string& token) const
{
    if (token.empty())
        return false;
    size_t i = 0;
    if (token[0] == '+' || token[0] == '-')
    {
        if (token.size() == 1)
            return false;
        i = 1;
    }
    for (; i < token.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(token[i])))
            return false;
    }
    return true;
}
