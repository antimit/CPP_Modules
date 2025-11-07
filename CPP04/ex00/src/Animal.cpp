#include "Animal.hpp"


Animal::Animal()
{
    
}

Animal::~Animal()
{

}

Animal & Animal::operator=(Animal const & src)
{
    if(this!= &src)
    {
        this->type = src.type;   
    }
    return *this;
}

Animal::Animal(Animal const & src) : type(src.type)
{
    
}

void Animal::makeSound()const 
{   
    std::cout<<"General Animal's sound"<<std::endl;
}

std::string Animal::getType() const
{
    return type;
}