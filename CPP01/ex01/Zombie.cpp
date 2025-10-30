#include "Zombie.hpp"

void Zombie::setName(const std::string &name)
{
    this->name = name;
}


void Zombie::announce()const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    
}
