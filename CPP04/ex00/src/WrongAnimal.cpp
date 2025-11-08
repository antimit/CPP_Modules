#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout<<"Default WrongAnimal constructor was called"<<std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor was called"<<std::endl;
}


WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
    std::cout<<"WrongAnimal assignment operator was called"<<std::endl;
    if(this != &src)
    {
        this->type = src.type;   
    }
    return *this;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src): type(src.type)
{
    std::cout<<"WrongAnimal copy constructor was called"<<std::endl;
}


void WrongAnimal::makeSound() const
{
    std::cout<<"Wrong animals doesnt know how to make right sound"<<std::endl;
}