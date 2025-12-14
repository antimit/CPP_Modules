#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern
{
    public:
    Intern();
    Intern(Intern const & src);
    ~Intern();
    Intern & operator=(Intern const & src);

    AForm * makeForm(std::string formName, std::string target);

    class InvalidFormName : public std::exception
    {
        public:
        virtual const char * what() const throw();
    };

    private:
    typedef struct sFormList
    {
        std::string formName;
        AForm * (*function)(std::string const &);
    } formList;
    
};

#endif