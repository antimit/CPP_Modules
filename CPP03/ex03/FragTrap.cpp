#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{

     this->hitPoints = 100;
     this->energyPoints = 100;
     this->attackDamage = 30;

     std::cout << "FragTrap " << this->name
               << " constructed with " << this->hitPoints << " HP, "
               << this->energyPoints << " EP, and "
               << this->attackDamage << " AD." << std::endl;
}


FragTrap::FragTrap() : ClapTrap("Unnamed")
{
     this->hitPoints = 100;
     this->energyPoints = 100;
     this->attackDamage = 30;
      std::cout<< "FragTrap default constructor was called for  " << this->name<<std::endl;  
}


FragTrap & FragTrap::operator=(FragTrap  const &rSym)
{
     if(this!= &rSym)
     {
          ClapTrap::operator=(rSym); 
     }
     return *this;
}

FragTrap::FragTrap(FragTrap const &rSym): ClapTrap(rSym)
{
     std::cout<<"A FragTrap copy constructor was called" << std::endl;
}

FragTrap::~FragTrap()
{
     std::cout << "FragTrap " << this->name
               << " destroyed with " << this->hitPoints << " HP, "
               << this->energyPoints << " EP, and "
               << this->attackDamage << " AD." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
     if (this->energyPoints == 0 || this->hitPoints == 0)
     {
          std::cout << "FragTrap " << this->name
                    << " doesn’t have enough energy or is out of hit points to attack!"
                    << std::endl;
          return;
     }
     std::cout << "FragTrap " << this->name
               << " attacks " << target
               << ", causing " << this->attackDamage
               << " points of damage" << std::endl;
     this->energyPoints--;
}

void FragTrap::highFivesGuys()
{
     std::cout << "FragTrap " << this->name
               << " requests a positive high five!" << std::endl;
}
