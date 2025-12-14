#include "Bureaucrat.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

void printTestHeader(const std::string &testName)
{
    std::cout << "\n" << GREEN << "=== " << testName << " ===" << RESET << std::endl;
}

int main()
{
    // Test 1: Create bureaucrat with valid grade
    printTestHeader("Test 1: Valid bureaucrat creation");
    try
    {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 2: Create bureaucrat with grade too high (0)
    printTestHeader("Test 2: Grade too high (0)");
    try
    {
        Bureaucrat bill("Bill", 0);
        std::cout << bill << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 3: Create bureaucrat with grade too low (151)
    printTestHeader("Test 3: Grade too low (151)");
    try
    {
        Bureaucrat frank("Frank", 151);
        std::cout << frank << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 4: Increment grade at highest (1)
    printTestHeader("Test 4: Increment at highest grade (1)");
    try
    {
        Bureaucrat john("John", 1);
        std::cout << john << std::endl;
        std::cout << "Trying to increment..." << std::endl;
        john.incrementGrade();
        std::cout << john << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 5: Decrement grade at lowest (150)
    printTestHeader("Test 5: Decrement at lowest grade (150)");
    try
    {
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;
        std::cout << "Trying to decrement..." << std::endl;
        alice.decrementGrade();
        std::cout << alice << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 6: Valid increment and decrement
    printTestHeader("Test 6: Valid increment and decrement");
    try
    {
        Bureaucrat charlie("Charlie", 75);
        std::cout << "Initial: " << charlie << std::endl;
        charlie.incrementGrade();
        std::cout << "After increment: " << charlie << std::endl;
        charlie.decrementGrade();
        std::cout << "After decrement: " << charlie << std::endl;
        charlie.decrementGrade();
        std::cout << "After decrement: " << charlie << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 7: Copy constructor and assignment operator
    printTestHeader("Test 7: Copy constructor and assignment operator");
    try
    {
        Bureaucrat original("Original", 50);
        Bureaucrat copy(original);
        Bureaucrat assigned("Assigned", 100);
        assigned = original;
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 8: Default constructor
    printTestHeader("Test 8: Default constructor");
    try
    {
        Bureaucrat noname;
        std::cout << noname << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << GREEN << "=== All tests completed ===" << RESET << std::endl;
    return 0;
}
