#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout<<"Default WrongCat constructor was called"<<std::endl;
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
    std::cout<<"WrongCat assignment operator was called"<<std::endl;
    if(this !=&src)
    {
        this->type = src.type;
    }
    return *this;
}


void WrongCat::makeSound() const
{
    std::cout<<"Wrong cat doesn't say MEOW"<<std::endl;
}