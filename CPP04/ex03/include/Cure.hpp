#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
    Cure();
    Cure(Cure const & src);
    Cure & operator=(Cure const & src);
    virtual AMateria * clone() const;
    void use(ICharacter & target);
    ~Cure();
};


#endif