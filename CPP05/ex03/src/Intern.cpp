#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
    (void)src;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & src)
{
    (void)src;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

static AForm *	createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *	createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *	createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

const char * Intern::InvalidFormName::what(void) const throw()
{
	return ("Invalid form name");
}

AForm *	Intern::makeForm(std::string formName, std::string target)
{
	AForm *	formToCreate = NULL;
	static formList const forms[3] = 
		{
			{"shrubbery creation", createShrubberyCreationForm},
			{"robotomy request", createRobotomyRequestForm},
			{"presidential pardon", createPresidentialPardonForm}
		};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].formName == formName)
		{
			formToCreate = forms[i].function(target);
			std::cout << "Intern creates " << formToCreate->getName() << std::endl;
			return (formToCreate);
		}
	}
	std::cout << "Intern could not create form named \"" << formName << "\"" << std::endl;
	throw Intern::InvalidFormName();
}

