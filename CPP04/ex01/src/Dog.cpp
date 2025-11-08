#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Default Dog constructor was called"<<std::endl;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor was called"<<std::endl;
}

Dog & Dog::operator=(Dog const & src)
{
    std::cout<<"Dog assignment operator was called"<<std::endl;
    if(this !=&src)
    {
        this->type = src.type;
    }
    return *this; 
}

Dog::Dog(Dog const & src) : Animal::Animal(src)
{
    std::cout<<"Dog copy constructor was called"<<std::endl;
}

void Dog::makeSound() const
{
    std::cout<< "Dog says brrrrr, ......bark"<<std::endl;
}