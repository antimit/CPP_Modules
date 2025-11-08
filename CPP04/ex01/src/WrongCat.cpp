#include "WrongCat.hpp"

WrongCat::WrongCat()
{

}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{

}

WrongCat::~WrongCat()
{
    
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    if(this !=&src)
    {
        this->type = src.type;
    }
    return *this;
}


void WrongAnimal::makeSound()
{
    std::cout<<"Wrong cat doesn't say MEOW"<<std::endl;
}