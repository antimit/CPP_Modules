#include "Animal.hpp"


Animal::Animal()
{
    type = "Animal";
    std::cout<<"Default Animal constructor was called"<<std::endl;
}

Animal::~Animal()
{
    std::cout<<"Animal destructor was called" << std::endl;
}

Animal & Animal::operator=(Animal const & src)
{
    std::cout<<"Animal assignment operator was called"<<std::endl;
    if(this!= &src)
    {
        this->type = src.type;   
    }
    return *this;
}

Animal::Animal(Animal const & src) : type(src.type)
{   
    std::cout<<"Animal copy constructor was called"<<std::endl;
}

void Animal::makeSound()const 
{   
    std::cout<<"General Animal's sound"<<std::endl;
}

std::string Animal::getType() const
{
    return type;
}