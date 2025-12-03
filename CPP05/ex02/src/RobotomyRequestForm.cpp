#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", gradeToSign, gradeToExecute), _target("default")
{
    std::cout<<"RobotomyRequestForm default constructor was called"<<std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src), _target(src._target)
{
    std::cout<<"RobotomyRequestForm copy constructor was called"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout<<"RobotomyRequestForm destructor was called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", gradeToSign, gradeToExecute), _target(target)
{
    std::cout<<"RobotomyRequestForm constructor was called"<<std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    std::cout<<"Assignment operator was called"<<std::endl;
    if(this != &src)
    {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

std::string const & RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void RobotomyRequestForm::beExecuted() const
{
    std::cout << this->_target<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
