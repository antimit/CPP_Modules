#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("CURE")
{
    std::cout<<"Default Cure constructor"<<std::endl;
}

Cure::~Cure()
{
    std::cout<<"The Cure Destructor was called"<<std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
    std::cout <<"Copy constructor was called"<<std::endl;   
}

Cure & Cure::operator=(Cure const & src)
{
    if (this != &src)
    {
        AMateria::operator=(src);
    }
    return *this;
}

AMateria * Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter & target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}