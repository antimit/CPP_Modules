#include "HumanB.hpp"


void HumanB::attack()const
{
    if (!weapon) 
    {
        std::cout << name << " has no weapon" << std::endl;
        return;
    }
    std::cout << this->name<< " attacks with their " << this->weapon->getType()<<std::endl;
}

HumanB::HumanB(std::string name):name(name),weapon(NULL)
{
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanB::~HumanB()
{

}

HumanB::HumanB() :name(),weapon(NULL)
{

}

