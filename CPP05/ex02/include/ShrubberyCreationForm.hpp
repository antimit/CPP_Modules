#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const & src);
    ShrubberyCreationForm(std::string const & target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

    std::string const & getTarget() const;

    static int const gradeToSign = 145;
    static int const gradeToExecute = 137;

    private:
    std::string _target;
    void beExecuted() const;
};

#endif
