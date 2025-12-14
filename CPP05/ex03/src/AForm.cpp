#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void validateGrade(int grade)
{
    if (grade < Bureaucrat::highestGrade)
        throw AForm::GradeTooHighException();
    if (grade > Bureaucrat::lowestGrade)
        throw AForm::GradeTooLowException();
}

AForm::AForm():name("Unnamed"), formSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout<<"AForm default constructor was called"<<std::endl;
}

AForm::AForm(AForm const & src):name(src.name), formSigned(src.formSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout<<"AForm copy constructor was called"<<std::endl;
}

AForm::AForm(std::string const & name, const int & gradeToSign, const int & gradeToExecute): name(name), formSigned(false), gradeToSign((validateGrade(gradeToSign), gradeToSign)), gradeToExecute((validateGrade(gradeToExecute), gradeToExecute))
{
    std::cout<<"AForm constructor was called"<<std::endl;
}

AForm & AForm::operator=(AForm const & src)
{
    if(this!=&src)
    {
        this->formSigned = src.formSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout<<"AForm destructor was called"<<std::endl;
}

std::string const & AForm::getName() const { return this->name; }
bool AForm::getIsSigned() const { return this->formSigned; }
unsigned int AForm::getGradeToSign() const { return this->gradeToSign; }
unsigned int AForm::getGradeToExecute() const { return this->gradeToExecute; }

std::ostream & operator<<(std::ostream & os, const AForm & form)
{
    os << "Form: " << form.getName() 
       << ", signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
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


void    AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if(this->formSigned)
    {
        throw(AForm::AlreadySignedException());
    }
    if(bureaucrat.getGrade() > this->gradeToSign)
        throw (AForm::GradeTooLowException());

    this->formSigned = true;
}


void    AForm::execute(Bureaucrat const & bureaucrat) const
{
    if(this->formSigned == false)
        throw(AForm::NotSignedException());

    if(bureaucrat.getGrade() > this->gradeToExecute)
        throw(AForm::GradeTooLowException());

    this->beExecuted();
}