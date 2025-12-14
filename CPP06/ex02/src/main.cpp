#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    // Test known types
    std::cout << "--- Known types ---" << std::endl;
    A a;
    B b;
    C c;

    std::cout << "A (ptr): ";
    identify(&a);
    std::cout << "A (ref): ";
    identify(a);

    std::cout << "B (ptr): ";
    identify(&b);
    std::cout << "B (ref): ";
    identify(b);

    std::cout << "C (ptr): ";
    identify(&c);
    std::cout << "C (ref): ";
    identify(c);

    // Test generate()
    std::cout << std::endl << "--- Random generate() ---" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base *ptr = generate();
        std::cout << "Generated: ";
        identify(ptr);
        delete ptr;
    }

    return 0;
}

