#include "Character.hpp"

Character::Character():_idxTotal(0), _name("Unnamed")
{
    std::cout<<"Default character constructor was called"<<std::endl;

    for (size_t i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
    }
    
}

