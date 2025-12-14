#include "Array.hpp"
#include <string>

int main()
{
    // Default constructor - empty array
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    try {
        empty[0] = 1;
    } catch (std::exception &e) {
        std::cout << "Empty access exception: " << e.what() << std::endl;
    }

    // Parameterized constructor
    Array<int> arr(5);
    std::cout << "Array size: " << arr.size() << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;
    std::cout << "Values: ";
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Copy constructor - deep copy test
    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "Original[0]: " << arr[0] << ", Copy[0]: " << copy[0] << std::endl;

    // Assignment operator - deep copy test
    Array<int> assigned;
    assigned = arr;
    assigned[0] = 888;
    std::cout << "Original[0]: " << arr[0] << ", Assigned[0]: " << assigned[0] << std::endl;

    // Out of bounds test
    try {
        arr[10] = 1;
    } catch (std::exception &e) {
        std::cout << "Out of bounds exception: " << e.what() << std::endl;
    }

    // Const array access test
    const Array<int> constArr(arr);
    std::cout << "Const arr[0]: " << constArr[0] << std::endl;

    // String array test
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "!";
    std::cout << "String arr: ";
    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;

    return 0;
}