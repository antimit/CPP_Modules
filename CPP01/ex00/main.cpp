#include "Zombie.hpp"

int	main() 
{
    Zombie* z =  newZombie("heap");
    randomChump("stack");

    delete z;
}