
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form{
    private:
    const std::string name;
    bool formSigned;
    const unsigned int gradeToSign;
    const unsigned int gradeToExecute;


    public:
    Form();
    Form(const Form & other);
    Form(std::string const & name,  const int &gradeToSign, const int & gradeToExecute);
    Form & operator=(const Form & other);
    ~Form();

    const std::string getName() const;
    bool getSignedValue() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExecute() const;


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

    void beSigned(Bureaucrat const &obj);
    
};

    std::ostream & operator<<(std::ostream &os, const Form & obj);


#endif