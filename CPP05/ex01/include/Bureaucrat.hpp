#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
    private:
    std::string const name_;
    unsigned int grade_;
    
    public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat & other);
    Bureaucrat(std::string const &name, int const &grade);
    Bureaucrat & operator=(const Bureaucrat & other);
    ~Bureaucrat();

    void incrementGrade();
    void decrementGrade();
       


    std::string getName() const;
    unsigned int getGrade() const;

    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };


    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char * what() const throw();
    };

    void signForm(Form & form); 
};

std::ostream & operator<<(std::ostream &os, const Bureaucrat &obj);

#endif