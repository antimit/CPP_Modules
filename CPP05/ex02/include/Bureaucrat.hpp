#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

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
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char * what() const throw();
    };

    void signForm(AForm & form) const;
    void executeForm(AForm & form) const; 

    static int const highestGrade = 1;
    static int const lowestGrade = 150;
};

std::ostream & operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
