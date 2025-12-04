#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const & src);
    PresidentialPardonForm(std::string const & target);      
    ~PresidentialPardonForm();

    PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

    std::string const & getTarget() const;

    void beExecuted(void) const;
    
    static int const gradeToSign = 25;
    static int const gradeToExecute = 5;

    private:
    std::string _target;
};

#endif
