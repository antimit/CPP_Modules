#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name_("Unnamed Bureaucrat"), grade_(150)
{
    std::cout<<"Default bureaucrat constructor"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const & grade) : name_(name)
{
    std::cout << "Bureaucrat constructor was called"<<std::endl;

    if(grade< MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if(grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    
    this->grade_ = grade;
}


Bureaucrat::Bureaucrat(Bureaucrat const & other) : name_(other.name_), grade_(other.grade_)
{
    std::cout<<"Bureaucrat copy constructor was called"<<std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    std::cout<<"Bureaucrat assignment operator was called"<<std::endl;
    if(this!= &src)
    {
        this->grade_ = src.grade_;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Bureaucrat destructor was called"<<std::endl;
}


void Bureaucrat::incrementGrade()
{
    if(this->grade_ - 1 < MAX_GRADE)
        throw GradeTooHighException();
    this->grade_--;
    std::cout<<"Bureaucrat grade was incremented"<<std::endl;
}

void Bureaucrat::decrementGrade()
{
    if(this->grade_ + 1 > MIN_GRADE)
        throw GradeTooLowException();
    this->grade_++;
    std::cout<<"Bureaucrat grade was decremented"<<std::endl;
}

unsigned int Bureaucrat::getGrade() const { return this->grade_; }

std::string Bureaucrat::getName() const {return this->name_;}



const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too High");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low");
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat &obj)
{
    os<<obj.getName() << ", bureaucrat grade "<< obj.getGrade() << "." <<std::endl;
    return os;
}
