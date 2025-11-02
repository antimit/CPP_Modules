#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) , name(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;

}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " with " << this->hitPoints << " hitpoints " << this->energyPoints << " Energypoints " << this->attackDamage << " attack damage points" << " was removed" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name
          << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string & target)
{
    ScavTrap::attack(target);
}