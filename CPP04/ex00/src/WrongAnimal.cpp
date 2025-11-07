#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{

}

WrongAnimal::~WrongAnimal()
{

}


WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
    if(this != &src)
    {
        this->type = src.type;   
    }
}

WrongAnimal::WrongAnimal(WrongAnimal const & src): type(src.type)
{

}


void WrongAnimal::makeSound()
{
    std::cout<<"Wrong animals doesnt know how to make right sound"<<std::endl;
}