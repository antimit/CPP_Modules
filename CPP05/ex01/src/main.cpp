#include "Bureaucrat.hpp"
#include "Form.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void printTestHeader(const std::string &testName)
{
    std::cout << "\n" << GREEN << "=== " << testName << " ===" << RESET << std::endl;
}

int main()
{
    // Test 1: Create form with valid grades
    printTestHeader("Test 1: Valid form creation");
    try
    {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 2: Create form with grade to sign too high (0)
    printTestHeader("Test 2: Form with grade to sign too high (0)");
    try
    {
        Form badForm("Bad Form", 0, 50);
        std::cout << badForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 3: Create form with grade to execute too low (151)
    printTestHeader("Test 3: Form with grade to execute too low (151)");
    try
    {
        Form badForm("Bad Form", 50, 151);
        std::cout << badForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 4: Bureaucrat signs form successfully
    printTestHeader("Test 4: Bureaucrat signs form successfully");
    try
    {
        Form permit("Building Permit", 100, 50);
        Bureaucrat manager("Manager Mike", 50);
        std::cout << YELLOW << "Before signing:" << RESET << std::endl;
        std::cout << permit << std::endl;
        manager.signForm(permit);
        std::cout << YELLOW << "After signing:" << RESET << std::endl;
        std::cout << permit << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 5: Bureaucrat fails to sign form (grade too low)
    printTestHeader("Test 5: Bureaucrat fails to sign form (grade too low)");
    try
    {
        Form topSecret("Top Secret", 10, 5);
        Bureaucrat intern("Intern Ian", 100);
        std::cout << intern << std::endl;
        std::cout << topSecret << std::endl;
        intern.signForm(topSecret);
        std::cout << YELLOW << "After attempt:" << RESET << std::endl;
        std::cout << topSecret << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 6: Multiple bureaucrats try to sign the same form
    printTestHeader("Test 6: Multiple bureaucrats try to sign");
    try
    {
        Form contract("Contract", 75, 50);
        Bureaucrat lowGrade("Low Larry", 100);
        Bureaucrat highGrade("High Harry", 50);
        
        std::cout << contract << std::endl;
        lowGrade.signForm(contract);
        std::cout << YELLOW << "After first attempt:" << RESET << std::endl;
        std::cout << contract << std::endl;
        highGrade.signForm(contract);
        std::cout << YELLOW << "After second attempt:" << RESET << std::endl;
        std::cout << contract << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 7: Copy constructor and assignment operator
    printTestHeader("Test 7: Form copy and assignment");
    try
    {
        Form original("Original Form", 50, 25);
        Form copy(original);
        Form assigned("Assigned Form", 100, 75);
        assigned = original;
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 8: Default form
    printTestHeader("Test 8: Default form constructor");
    try
    {
        Form defaultForm;
        std::cout << defaultForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // Test 9: Bureaucrat with exact required grade
    printTestHeader("Test 9: Bureaucrat with exact required grade");
    try
    {
        Form exactForm("Exact Form", 75, 50);
        Bureaucrat exact("Exact Eric", 75);
        std::cout << exactForm << std::endl;
        std::cout << exact << std::endl;
        exact.signForm(exactForm);
        std::cout << YELLOW << "After signing:" << RESET << std::endl;
        std::cout << exactForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << GREEN << "=== All tests completed ===" << RESET << std::endl;
    return 0;
}
