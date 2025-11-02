#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point p1(2.5f, 2.0f); // inside
    Point p2(5.0f, 0.0f); // vertex -> on edge -> false
    Point p3(3.0f, 3.5f); // inside
    Point p4(2.5f, 5.0f); // vertex -> false
    Point p5(6.0f, 1.0f); // outside

    std::cout << std::boolalpha;
    std::cout << "p1 inside: " << bsp(a,b,c,p1) << "\n";
    std::cout << "p2 inside: " << bsp(a,b,c,p2) << "\n";
    std::cout << "p3 inside: " << bsp(a,b,c,p3) << "\n";
    std::cout << "p4 inside: " << bsp(a,b,c,p4) << "\n";
    std::cout << "p5 inside: " << bsp(a,b,c,p5) << "\n";
}