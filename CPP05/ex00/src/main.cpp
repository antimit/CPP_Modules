#include "Bureaucrat.hpp"

int main()
{

    // try
    // {
    //     Bureaucrat BurA("Bill", 151);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << "=============" << std::endl;

    // std::cout << "Correct Grade" << std::endl;
    // try
    // {
    //     Bureaucrat BurB("Frank", 1);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // try
    // {
    //     Bureaucrat BurC("John", 1);
    //     BurC.incrementGrade();
    //     BurC.incrementGrade();
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << e.what() <<std::endl;
    // }

    try
    {
        Bureaucrat BurD("Bob", 150);
        BurD.incrementGrade();
        // BurD.decrementGrade();
        // BurD.decrementGrade();

    }
    catch(const std::exception& e)
    {
        std::cout<< e.what()<<std::endl;
    }
}

