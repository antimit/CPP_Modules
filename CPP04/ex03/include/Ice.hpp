#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include <string>
#include "Character.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    Ice();
    Ice(Ice const & src);
    Ice &operator=(Ice const & src);
    virtual AMateria * clone()const;
    ~Ice();
    void use(ICharacter & target);
    private:

};

#endif