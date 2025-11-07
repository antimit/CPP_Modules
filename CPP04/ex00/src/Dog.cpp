#include "Dog.hpp"

Dog::Dog()
{

}

Dog::~Dog()
{

}

Dog & Dog::operator=(Dog const & src)
{
    if(this !=&src)
    {
        this->type = src.type;
    }
    return *this; 
}

Dog::Dog(Dog const & src) : Animal::Animal(src)
{

}

void Dog::makeSound() const
{
    std::cout<< "Dog says brrrrr, ......bark"<<std::endl;
}