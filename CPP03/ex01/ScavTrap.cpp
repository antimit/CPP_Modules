#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints == 0 || this->hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name
                  << " doesn’t have enough energy or is out of hit points to attack!"
                  << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name 
    << " attacks " << target
    << ", causing " << this->attackDamage 
    << " points of damage" << std::endl;
    this->energyPoints--;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    
    std::cout << "ScavTrap " << this->name 
          << " constructed with " << this->hitPoints << " HP, "
          << this->energyPoints << " EP, and "
          << this->attackDamage << " AD." << std::endl;

}


ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src)
{
    std::cout<< "ScavTrap copy constructor was called"<<std::endl;   
}

ScavTrap::ScavTrap():ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout<< "ScavTrap constructor was called"<<std::endl;   
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rSym)
{
     if(this!= &rSym)
    {
        ClapTrap::operator=(rSym);
    }

    return *this;
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name
          << " destroyed with " << this->hitPoints << " HP, "
          << this->energyPoints << " EP, and "
          << this->attackDamage << " AD." << std::endl;

}

void ScavTrap::guardGate()
{
   if (this->hitPoints > 0)
        std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode." << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " cannot guard — it has 0 hit points." << std::endl;
    
}

