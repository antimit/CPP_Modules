#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "Character.hpp"
#include <iostream>

class AMateria
{
protected:
std::string type;

public:
AMateria();
AMateria(std::string const & type);
AMateria(AMateria const & src);
~AMateria();

AMateria & operator=(AMateria const & src);

std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};

#endif