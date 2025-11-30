#ifndef SHRUBBERY_CREATION_FORM_CLASS_H
#define SHRUBBERY_CREATION_FORM_CLASS_H

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

    void beExecuted() const;

    static int const    gradeToSign = 72;
    static int const    gradeToExecute = 45;

    private:
    std::string _target;
};

#endif