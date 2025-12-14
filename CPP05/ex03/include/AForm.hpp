#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm{
    
public:
    AForm();
    AForm(AForm const & src);
    AForm(std::string const & name,  const int &gradeToSign, const int & gradeToExecute);
    virtual ~AForm();
    AForm & operator=(AForm const & src);

    std::string const & getName() const;
    bool getIsSigned() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExecute() const;

    void	beSigned(Bureaucrat const & bureaucrat);
	void	execute(Bureaucrat const & bureaucrat) const;

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

    class AlreadySignedException: public std::exception
    {
        public:
        virtual const char * what() const throw();
    };

    class NotSignedException: public std::exception
    {
        public:
        virtual const char * what() const throw();
    };

private:
    const std::string name;
    bool formSigned;
    const unsigned int gradeToSign;
    const unsigned int gradeToExecute;

    protected:
		virtual void	beExecuted(void) const = 0;


};

std::ostream & operator<<(std::ostream & os, const AForm & form);

#endif