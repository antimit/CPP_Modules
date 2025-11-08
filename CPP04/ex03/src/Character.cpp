#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(): _idxTotal(0), _name("Unnamed")
{
    std::cout<<"Default character constructor was called"<<std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(std::string name): _idxTotal(0), _name(name)
{
    std::cout<<"Character constructor with name "<<name<<" was called"<<std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

ICharacter::~ICharacter()
{
    std::cout<<"ICharacter destructor was called"<<std::endl;
}
Character::Character(Character const & src): _idxTotal(0), _name(src._name)
{
    std::cout <<"Copy Character constructor was called"<<std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    for (int i = 0; i < src._idxTotal; i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    this->_idxTotal = src._idxTotal;
}

Character & Character::operator=(Character const & src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
            {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        this->_name = src._name;
        this->_idxTotal = 0;
        for (int i = 0; i < src._idxTotal; i++)
        {
            if (src._inventory[i])
            {
                this->_inventory[i] = src._inventory[i]->clone();
                this->_idxTotal++;
            }
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout <<"Character destructor was called"<<std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

std::string const & Character::getName()const
{
    return this->_name;
}

void Character::equip(AMateria * m)
{
    if (!m)
        return;
    if (this->_idxTotal >= 4)
    {
        std::cout << "The inventory is full "<<std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout<<"The materia with type " << m->getType() << std::endl;
            this->_idxTotal++;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    if (this->_inventory[idx] != NULL)
    {
        this->_inventory[idx] = NULL;
        if (this->_idxTotal > 0)
            this->_idxTotal--;
        std::cout<<"The materia at index "<<idx<<" was unequipped"<<std::endl;
    }
}

void Character::use(int idx, ICharacter & target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout<<"Index out of range"<<std::endl;
        return;
    }
    if (this->_inventory[idx] == NULL)
    {
        std::cout<<"The item at index "<< idx << " is empty "<<std::endl;
        return;
    }
    this->_inventory[idx]->use(target);
}