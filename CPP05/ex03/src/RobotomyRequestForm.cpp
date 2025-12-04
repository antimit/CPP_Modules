#include "RobotomyRequestForm.hpp"
#include <cstdlib>

const int RobotomyRequestForm::gradeToSign;
const int RobotomyRequestForm::gradeToExecute;

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
    std::cout << "* DRILLING NOISES * Bzzzzzt... Vrrrrrr..." << std::endl;
    if (std::rand() % 2)
    {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
    }
}
