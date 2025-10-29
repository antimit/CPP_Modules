#include "Zombie.hpp"

int main()
{
    Zombie * zombies = zombieHorde(10,"Brainrot");
   
    delete []zombies;

    return 0;
}