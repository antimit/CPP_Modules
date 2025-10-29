#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new Zombie[N];
    for (int  i = 0; i < N; i++)
    {
        zombies[i].setName(name);
        zombies[i].announce();
    }
    
    return zombies;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}


void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    
}
