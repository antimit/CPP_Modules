#include "Whatever.hpp"
#include <string>

int main(void)
{
    // Subject test
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    // Equal values test (should return second)
    int x = 42;
    int y = 42;
    std::cout << "Equal test - min returns b: " << (&::min(x, y) == &y ? "OK" : "FAIL") << std::endl;
    std::cout << "Equal test - max returns b: " << (&::max(x, y) == &y ? "OK" : "FAIL") << std::endl;

    // Float test
    float f1 = 3.14f;
    float f2 = 2.71f;
    ::swap(f1, f2);
    std::cout << "Float swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;

    return 0;
}