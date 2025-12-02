#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const & src);
    RobotomyRequestForm(std::string const & target);
    ~RobotomyRequestForm();

    RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

    std::string const & getTarget() const;

    void beExecuted() const;

    static int const gradeToSign = 72;
    static int const gradeToExecute = 45;

    private:
    std::string _target;
};

#endif
