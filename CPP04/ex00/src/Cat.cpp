#include "Cat.hpp"

Cat::Cat()
{

}

Cat::~Cat()
{

}

Cat::Cat(Cat const & src) : Animal::Animal(src)
{
   
}

Cat & Cat::operator=(Cat const & src)
{
    if(this!= &src)
    {
        this->type = src.type;
    }
    return *this;
}

void Cat::makeSound()const
{
    std::cout<<"Cat says MEOW"<<std::endl;
}
