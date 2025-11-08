#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout<<"Default WrongCat constructor was called"<<std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
    std::cout<<"WrongCat copy constructor was called"<<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor was called"<<std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    if(this !=&src)
    {
        this->type = src.type;
    }
    return *this;
}


void WrongCat::makeSound()
{
    std::cout<<"Wrong cat doesn't say MEOW"<<std::endl;
}