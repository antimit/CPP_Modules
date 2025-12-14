#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (const ValueNotFound &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(vec, 42);
    } catch (const ValueNotFound &e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> lst;
    for (int i = 0; i < 5; i++)
        lst.push_back(i * 10);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found: " << *it << std::endl;
    } catch (const ValueNotFound &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}