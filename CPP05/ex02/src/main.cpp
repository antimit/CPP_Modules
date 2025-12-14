#include "Bureaucrat.hpp"
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

int main(void)
{
    std::srand(std::time(NULL));

    printTestHeader("Creating Bureaucrats");
    Bureaucrat intern("Intern Larry", 150);
    Bureaucrat clerk("Clerk Carl", 140);
    Bureaucrat manager("Manager Mike", 70);
    Bureaucrat director("Director Dave", 40);
    Bureaucrat president("President Pete", 1);

    std::cout << intern << std::endl << manager << std::endl << director << std::endl << president << std::endl;

    // Test 1: ShrubberyCreationForm
    printTestHeader("Test 1: ShrubberyCreationForm");
    {
        ShrubberyCreationForm shrub("Home");
        std::cout << shrub << std::endl;

        std::cout << YELLOW << "Intern tries to sign (grade 150, needs 145):" << RESET << std::endl;
        intern.signForm(shrub);
        intern.executeForm(shrub);

        std::cout << YELLOW << "\nClerk tries to sign (grade 140, needs 145):" << RESET << std::endl;
        clerk.signForm(shrub);
        
        std::cout << YELLOW << "\nClerk tries to execute (grade 140, needs 137):" << RESET << std::endl;
        clerk.executeForm(shrub);

        std::cout << YELLOW << "\nManager executes (grade 70, needs 137):" << RESET << std::endl;
        manager.executeForm(shrub);
        std::cout << CYAN << "Check for Home_shrubbery file!" << RESET << std::endl;
    }

    // Test 2: RobotomyRequestForm
    printTestHeader("Test 2: RobotomyRequestForm");
    {
        RobotomyRequestForm robot("Employee");
        std::cout << robot << std::endl;

        std::cout << YELLOW << "Manager tries to sign (grade 70, needs 72):" << RESET << std::endl;
        manager.signForm(robot);
        
        std::cout << YELLOW << "\nManager tries to execute (grade 70, needs 45):" << RESET << std::endl;
        manager.executeForm(robot);

        std::cout << YELLOW << "\nDirector executes (grade 40, needs 45):" << RESET << std::endl;
        director.executeForm(robot);
        
        std::cout << YELLOW << "\nExecuting multiple times to show 50% success rate:" << RESET << std::endl;
        for (int i = 0; i < 4; i++)
        {
            RobotomyRequestForm tempRobot("Test Subject");
            director.signForm(tempRobot);
            director.executeForm(tempRobot);
        }
    }

    // Test 3: PresidentialPardonForm
    printTestHeader("Test 3: PresidentialPardonForm");
    {
        PresidentialPardonForm pardon("Criminal");
        std::cout << pardon << std::endl;

        std::cout << YELLOW << "Director tries to sign (grade 40, needs 25):" << RESET << std::endl;
        director.signForm(pardon);

        std::cout << YELLOW << "\nPresident signs (grade 1, needs 25):" << RESET << std::endl;
        president.signForm(pardon);
        
        std::cout << YELLOW << "\nDirector tries to execute (grade 40, needs 5):" << RESET << std::endl;
        director.executeForm(pardon);

        std::cout << YELLOW << "\nPresident executes (grade 1, needs 5):" << RESET << std::endl;
        president.executeForm(pardon);
    }

    // Test 4: Execute unsigned form
    printTestHeader("Test 4: Execute unsigned form");
    {
        ShrubberyCreationForm unsigned_form("Garden");
        std::cout << unsigned_form << std::endl;
        std::cout << YELLOW << "Trying to execute without signing:" << RESET << std::endl;
        president.executeForm(unsigned_form);
    }

    // Test 5: Copy constructor and assignment
    printTestHeader("Test 5: Copy constructor and assignment");
    {
        ShrubberyCreationForm original("Forest");
        president.signForm(original);
        ShrubberyCreationForm copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        
        ShrubberyCreationForm assigned("Meadow");
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
    }

    // Test 6: Default constructors
    printTestHeader("Test 6: Default constructors");
    {
        ShrubberyCreationForm defaultShrub;
        RobotomyRequestForm defaultRobot;
        PresidentialPardonForm defaultPardon;
        std::cout << defaultShrub << std::endl;
        std::cout << defaultRobot << std::endl;
        std::cout << defaultPardon << std::endl;
    }

    std::cout << "\n" << GREEN << "=== All tests completed ===" << RESET << std::endl;
    return 0;
}
