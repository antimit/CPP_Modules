#include "Dog.hpp"

Dog::Dog() : Animal(), brain()
{
    this->type = "Dog";
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
        Animal::operator=(src);
        this->brain = src.brain; // deep copy
        this->type = src.type;
    }
    return *this; 
}

Dog::Dog(Dog const & src) : Animal(src), brain(src.brain)
{
    this->type = src.type;
    std::cout<<"Dog copy constructor was called"<<std::endl;
}

void Dog::makeSound() const
{
    std::cout<< "Dog says brrrrr, ......bark"<<std::endl;
}

std::string Dog::getType()const
{
    return type;
}

Brain *Dog::getBrain()
{
    return &brain;
}

Brain const *Dog::getBrain() const
{
    return &brain;
}