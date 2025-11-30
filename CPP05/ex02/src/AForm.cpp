#include "AForm.hpp"

AForm::AForm():name("Unnamed"), gradeToSign(1), gradeToExecute(1)
{
    std::cout<<"AForm default constructor was called"<<std::endl;
}

AForm::AForm(AForm const & src):formSigned(src.formSigned), gradeToSign(1), gradeToExecute(1)
{
    std::cout<<"AForm copy constructor was called"<<std::endl;
}

AForm::AForm(std::string const & name, const int & gradeToSign, const int & gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout<<"AForm constructor was called"<<std::endl;
}

AForm & AForm::operator=(AForm const & src)
{
    if(this!=&src)
    {
        this->formSigned = src.formSigned;
    }
}

AForm::~AForm()
{
    std::cout<<"AForm destructor was called"<<std::endl;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too High");
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return("Grade is too low");
}

const char * AForm::AlreadySignedException::what() const throw()
{
    return("Form is already signed");
}

const char * AForm::NotSignedException::what() const throw()
{
    return("Form hasn't been signed yet");
}