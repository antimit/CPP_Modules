#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
  public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int solve(const std::string& input);

  private:
    enum e_status
    {
        ok,
        error,
    };
    static const std::string s_valid_operations;

    enum e_status _evaluate(const std::string& input);
    enum e_status _apply_operation(std::stack<int>& values, char op) const;
    bool _is_operator(const std::string& token) const;
    bool _is_number(const std::string& token) const;
};
#endif
