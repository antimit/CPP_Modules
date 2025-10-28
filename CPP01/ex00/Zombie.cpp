#include "Zombie.hpp"

Zombie::Zombie(str name) {
	this->name = name;
	std::cout << "Be careful ! The zombie " << name << " is in the house !" << std::endl;
}

Zombie::Zombie()
{

}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->name << " died a second time." << std::endl;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

std::string Zombie::get_name()
{
    return this->name;
}
