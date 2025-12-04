#include "Form.hpp"
#include "Bureaucrat.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

Form::Form() : name("Unnamed form"), formSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout<<"Default Form constructor was called"<<std::endl;
}

Form::Form(const Form & other):name(other.name), formSigned(other.formSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) 
{
    std::cout<<"Copy constructor was called"<<std::endl;
}

Form::Form(std::string const & name, const int & gradeToSign, const int & gradeToExecute ) : name(name), formSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout<<"Form constructor was called"<<std::endl;
    if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
        throw Form::GradeTooLowException();
}

Form & Form::operator=(const Form &other)
{
    std::cout<<"Form assignment operator was called"<<std::endl;
    if (this != &other)
    {
        this->formSigned = other.formSigned;
    }

    return *this;
}

Form::~Form()
{
    std::cout <<"Default form destructor was called"<<std::endl;
}


const std::string Form::getName()const{return this->name;}
int Form::getGradeToExecute()const{return this->gradeToExecute;}
int Form::getGradeToSign()const{return this->gradeToSign;}
bool Form::getSignedValue()const{return this->formSigned;}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if(bureaucrat.getGrade() > this->gradeToSign)
    {
        throw GradeTooLowException();
    }
    this->formSigned = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too High");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return("Grade is too low");
}

std::ostream & operator<<(std::ostream & os, const Form & obj)
{
    os<<obj.getName()<< ", form's gradeToExecute: "<<obj.getGradeToExecute()<<", form's gradeToSign"<<obj.getGradeToSign()<<", isFormSigned: "<<obj.getSignedValue()<<std::endl;
    return os;
}
