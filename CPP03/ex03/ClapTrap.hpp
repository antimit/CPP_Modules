#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>
#include <string>

class ClapTrap
{
    public:
    ClapTrap();
    ClapTrap(ClapTrap const & src);
    ClapTrap(std::string name);
    ~ClapTrap();

    ClapTrap & operator=(ClapTrap const & rSym);
    void virtual attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);


    //getters
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    std::string getName() const;

    protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
    
};

#endif