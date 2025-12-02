#ifndef AFORM_HPP
#define AFORM_HPP

#include "iostream"

class AForm{
    
public:
    AForm();
    AForm(AForm const & src);
    AForm(std::string const & name,  const int &gradeToSign, const int & gradeToExecute);
    ~AForm();
    AForm & operator=(AForm const & src);

    void	beSigned(Bureaucrat const & bureaucrat);
	void	execute(Bureaucrat const & bureaucrat);

     class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };


    class GradeTooLowException : public std::exception
    {
        const char * what() const throw();
    };

    class AlreadySignedException: public std::exception
    {
        const char * what() const throw();
    };

    class NotSignedException: public std::exception
    {
        const char * what() const throw();
    };
    
private:
    const std::string name;
    bool formSigned;
    const unsigned int gradeToSign;
    const unsigned int gradeToExecute;

    protected:
		virtual void	beExecuted(void) const = 0;


};

#endif