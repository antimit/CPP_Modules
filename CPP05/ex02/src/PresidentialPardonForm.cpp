#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", gradeToSign, gradeToExecute), _target("default")
{
    std::cout<<"PresidentialPardonForm default constructor was called"<<std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src), _target(src._target)
{
    std::cout<<"PresidentialPardonForm copy constructor was called"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout<<"PresidentialPardonForm destructor was called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", gradeToSign, gradeToExecute), _target(target)
{
    std::cout<<"PresidentialPardonForm constructor was called"<<std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    std::cout<<"Assignment operator was called"<<std::endl;
    if(this != &src)
    {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

std::string const & PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

void PresidentialPardonForm::beExecuted() const
{
    std::cout << this->_target<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
