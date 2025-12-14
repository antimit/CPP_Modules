#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

void printTestHeader(const std::string &testName)
{
    std::cout << "\n" << GREEN << "=== " << testName << " ===" << RESET << std::endl;
}

void testInternFormCreation(const std::string &formName, const std::string &target)
{
    std::cout << YELLOW << "Creating form \"" << formName << "\" with target \"" << target << "\"" << RESET << std::endl;
    Intern intern;
    Bureaucrat president("President Pete", 1);
    AForm *form = NULL;
    
    try
    {
        form = intern.makeForm(formName, target);
        if (form)
        {
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        if (form)
            delete form;
    }
}

int main(void)
{
    std::srand(std::time(NULL));

    // Test 1: Create ShrubberyCreationForm via Intern
    printTestHeader("Test 1: Intern creates ShrubberyCreationForm");
    testInternFormCreation("shrubbery creation", "Park");

    // Test 2: Create RobotomyRequestForm via Intern
    printTestHeader("Test 2: Intern creates RobotomyRequestForm");
    testInternFormCreation("robotomy request", "Bender");

    // Test 3: Create PresidentialPardonForm via Intern
    printTestHeader("Test 3: Intern creates PresidentialPardonForm");
    testInternFormCreation("presidential pardon", "Arthur Dent");

    // Test 4: Try to create invalid form
    printTestHeader("Test 4: Intern tries to create invalid form");
    testInternFormCreation("invalid form name", "Nobody");

    // Test 5: Empty form name
    printTestHeader("Test 5: Intern tries empty form name");
    testInternFormCreation("", "Empty");

    // Test 6: Case sensitivity test
    printTestHeader("Test 6: Case sensitivity test");
    testInternFormCreation("SHRUBBERY CREATION", "CaseTest");
    testInternFormCreation("Robotomy Request", "CaseTest2");

    // Test 7: Intern copy constructor and assignment
    printTestHeader("Test 7: Intern copy constructor and assignment");
    {
        Intern intern1;
        Intern intern2(intern1);
        Intern intern3;
        intern3 = intern1;
        
        std::cout << YELLOW << "All interns creating the same form:" << RESET << std::endl;
        AForm *form1 = NULL;
        AForm *form2 = NULL;
        AForm *form3 = NULL;
        
        try
        {
            form1 = intern1.makeForm("presidential pardon", "Target1");
            form2 = intern2.makeForm("presidential pardon", "Target2");
            form3 = intern3.makeForm("presidential pardon", "Target3");
            
            std::cout << *form1 << std::endl;
            std::cout << *form2 << std::endl;
            std::cout << *form3 << std::endl;
            
            delete form1;
            delete form2;
            delete form3;
        }
        catch (std::exception &e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
            if (form1) delete form1;
            if (form2) delete form2;
            if (form3) delete form3;
        }
    }

    // Test 8: Full workflow with different bureaucrats
    printTestHeader("Test 8: Full workflow with different bureaucrats");
    {
        Intern intern;
        Bureaucrat lowGrade("Intern Ivan", 150);
        Bureaucrat highGrade("Director Dave", 1);
        
        AForm *shrub = NULL;
        try
        {
            shrub = intern.makeForm("shrubbery creation", "Office");
            std::cout << *shrub << std::endl;
            
            std::cout << YELLOW << "Low grade bureaucrat tries to sign and execute:" << RESET << std::endl;
            lowGrade.signForm(*shrub);
            lowGrade.executeForm(*shrub);
            
            std::cout << YELLOW << "\nHigh grade bureaucrat signs and executes:" << RESET << std::endl;
            highGrade.signForm(*shrub);
            highGrade.executeForm(*shrub);
            
            delete shrub;
        }
        catch (std::exception &e)
        {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
            if (shrub) delete shrub;
        }
    }

    std::cout << "\n" << GREEN << "=== All tests completed ===" << RESET << std::endl;
    std::cout << CYAN << "Check for Park_shrubbery and Office_shrubbery files!" << RESET << std::endl;
    return 0;
}
