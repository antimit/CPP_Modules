#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string &target)
{
    if (this->energyPoints == 0 || this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name
                  << " doesn’t have enough energy or is out of hit points to attack!"
                  << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name 
    << " attacks " << target
    << ", causing " << this->attackDamage 
    << " points of damage" << std::endl;
    this->energyPoints--;
}

ClapTrap::ClapTrap() :name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " was instantiated" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " with " << this->hitPoints << " hitpoints, " << this->energyPoints << " Energy points, " << this->attackDamage << " attack damage points, " << " was instantiated" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " with " << this->hitPoints << " hitpoints, " << this->energyPoints << " Energy points, " << this->attackDamage << " attack damage points, " << " was removed" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " doesn't have enough hitpoints points." << std::endl;   
        return;
    } 

    if (this->energyPoints == 0 )
    {
        std::cout << "ClapTrap " << this->name << " doesn't have enough energy points." << " The energy point count is: " << this->energyPoints << std::endl;
        return;
    }

    if (this->hitPoints == 10)
    {
        std::cout << "ClapTrap " << this->name << " doesn't need to be repaired" << std::endl;
        return;
    }
    if (this->hitPoints + amount >= 10)
    {
        std::cout << "ClapTrap " << this->name << " is fully repaired" << std::endl;
        this->hitPoints = 10;
       
    }
    else
    {
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " got additional " << amount << " hitpoints"<<std::endl;
    }
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already killed" << std::endl;
        return;
    }
    if (amount >=this->hitPoints)
    {
        std::cout << "ClapTrap " << this->name << " was attacked and killed" << std::endl;
        this->hitPoints =0;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " was attacked and lost " <<amount << " hitpoints." << std::endl;
    }
}


unsigned int ClapTrap::getHitPoints() const
{
    return this->hitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const
{
    return this->energyPoints;
}


unsigned int ClapTrap::getAttackDamage() const 
{
    return this->attackDamage;
}

std::string ClapTrap::getName() const
{
    return this->name;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rSym)
{
    if(this != &rSym)
    {
        this->hitPoints = rSym.hitPoints;
        this->energyPoints = rSym.energyPoints;
        this->attackDamage = rSym.attackDamage;
        this->name = rSym.name;
    }

    return *this;
}

ClapTrap::ClapTrap(ClapTrap const & src) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage)
{
    
}
