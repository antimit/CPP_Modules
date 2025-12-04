#include "ShrubberyCreationForm.hpp"
#include <fstream>

const int ShrubberyCreationForm::gradeToSign;
const int ShrubberyCreationForm::gradeToExecute;

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target("default")
{
    std::cout<<"ShrubberyCreationForm default constructor was called"<<std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm(src), _target(src._target)
{
    std::cout<<"ShrubberyCreationForm copy constructor was called"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout<<"ShrubberyCreationForm destructor was called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target(target)
{
    std::cout<<"ShrubberyCreationForm constructor was called"<<std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    std::cout<<"Assignment operator was called"<<std::endl;
    if(this != &src)
    {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

std::string const & ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void ShrubberyCreationForm::beExecuted() const
{
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not create file" << std::endl;
        return;
    }
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file.close();
}
