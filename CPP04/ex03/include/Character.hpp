#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"


class AMateria;
class Character: public ICharacter
{
    public:
    Character();
    Character(std::string name);
    Character(Character const & src);
    virtual ~Character();

    Character& operator=(Character const & src);
    virtual std::string const & getName()const;

    virtual void    equip(AMateria *m);
    virtual void    unequip(int idx);
    virtual void    use(int idx, ICharacter & target);

    private:
    int     _idxTotal;
    std::string     _name;
    AMateria    *_inventory[4];
};

#endif