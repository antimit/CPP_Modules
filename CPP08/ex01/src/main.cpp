#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try {
        sp.addNumber(42);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Span sp2(10000);
    std::vector<int> vec;
    for (int i = 0; i < 10000; ++i)
        vec.push_back(i);
    sp2.addNumber(vec.begin(), vec.end());

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    return 0;
}
