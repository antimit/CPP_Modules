#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target("default")
{
    std::cout<<"ShrubberyCreationForm default constructor was called"<<std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm(src), _target(src._target)
{
    std::cout<<"ShrubberyCreationForm copy constructor was called"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout<<"ShrubberyCreationForm destructor was called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target(target)
{
    std::cout<<"ShrubberyCreationForm constructor was called"<<std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    std::cout<<"Assignment operator was called"<<std::endl;
    if(this != &src)
    {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

std::string const & ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void ShrubberyCreationForm::beExecuted() const
{
    std::cout << this->_target<< "Driiiiiiiiil" << std::endl;

    if(std::rand()%2)
    {
        std::cout<<"Target" <<this->_target<<"has been robotized"<<std::endl;
    }
    else
    {
        std::cout <<"Oh. no" <<this->_target<<" resisted robotomization"<<std::endl;
    }
}
