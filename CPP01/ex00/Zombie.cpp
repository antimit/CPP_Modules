#include "Zombie.hpp"

Zombie::Zombie(str name) : name(name)
{
}

Zombie::Zombie()
{

}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->name << " died a second time." << std::endl;
}

void	Zombie::announce() const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

std::string Zombie::get_name() const
{
    return this->name;
}
