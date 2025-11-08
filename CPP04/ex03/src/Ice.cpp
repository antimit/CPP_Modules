#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ICE")
{
    std::cout<<"Default Ice constructor was called"<<std::endl;
}

Ice::~Ice()
{
    std::cout<<"Default Ice destructor was called"<<std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
    std::cout<<"Copy constructor was called"<<std::endl;
}

Ice & Ice::operator=(Ice const & src)
{
    std::cout<<"Assignment operator was called"<<std::endl;

    if(this!=&src)
    {
        AMateria::operator=(src);
    }
    return *this;
}

AMateria * Ice::clone()const
{
    return new Ice();
}

void Ice::use(ICharacter & target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
