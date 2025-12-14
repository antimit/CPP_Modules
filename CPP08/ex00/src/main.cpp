#include "easyfind.hpp"

int main()
{
    std::vector<int> toCheck;

    for (size_t i = 0; i < 5; i++)
    {
        toCheck.push_back(std::rand()%5);
    }
    
    try {
        easyfind(toCheck, 2);
    }
    catch (const ValueNotFound& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}