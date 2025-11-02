#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap 
{
    public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap & src);
    ~ScavTrap();
    ScavTrap & operator=(ScavTrap const  & src);
    virtual void attack(const std::string& target);
    void guardGate();
};

#endif