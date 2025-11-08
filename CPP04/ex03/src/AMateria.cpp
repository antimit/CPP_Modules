#include "AMateria.hpp"

#include "ICharacter.hpp"

AMateria::AMateria() 
{
    std::cout<<"AMateria default constructor was called"<<std::endl;
}

AMateria::AMateria(std::string const & type): type(type)
{
    std::cout<<"AMateria constructor with type "<<type<<" was called"<<std::endl;    
}

AMateria::AMateria(AMateria const & src) :type(src.type)
{
   std::cout<<"AMateria copy constructor was called"<<std::endl;
}

AMateria & AMateria::operator=(AMateria const & src)
{
    std::cout<<"AMateria assignment operator was called"<<std::endl;
     if(this != &src)
    {
        this->type = src.type;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout<<"AMateria destructor was called"<<std::endl;
}

std::string const& AMateria::getType()const
{
    return this->type;
}



void AMateria::use(ICharacter& target)
{
    std::cout<<"Target with the name of "<<target.getName()<<" was used"<<std::endl;
}