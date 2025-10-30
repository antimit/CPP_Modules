#include "Zombie.hpp"

int main()
{
    const std::string name = "Brainrot";
    Zombie * zombies = zombieHorde(10, name);

    for (size_t i = 0; i < 10; i++)
    {
        zombies[i].announce(); 
    }
    
   
    delete []zombies;

    return 0;
}