#include "iter.hpp"
#include <string>

template<typename T>
void print(T const &elem)
{
    std::cout << elem << " ";
}

template<typename T>
void increment(T &elem)
{
    elem++;
}

void printInt(int const &n)
{
    std::cout << n << " ";
}

int main()
{
    // Int array test
    int intArr[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(intArr, 5, print<int>);
    std::cout << std::endl;

    iter(intArr, 5, increment<int>);
    std::cout << "After increment: ";
    iter(intArr, 5, print<int>);
    std::cout << std::endl;

    // String array test
    std::string strArr[] = {"Hello", "World", "42"};
    std::cout << "String array: ";
    iter(strArr, 3, print<std::string>);
    std::cout << std::endl;

    // Const array test
    const int constArr[] = {10, 20, 30};
    std::cout << "Const array: ";
    iter(constArr, 3, print<int>);
    std::cout << std::endl;

    // Char array test
    char charArr[] = {'a', 'b', 'c'};
    std::cout << "Char array: ";
    iter(charArr, 3, print<char>);
    std::cout << std::endl;

    // Non-template function test
    int arr[] = {100, 200, 300};
    std::cout << "Non-template func: ";
    iter(arr, 3, printInt);
    std::cout << std::endl;

    return 0;
}