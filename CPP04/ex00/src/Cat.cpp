#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout<<"Default Cat constructor was called"<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor was called"<<std::endl;
}

Cat::Cat(Cat const & src) : Animal::Animal(src)
{
     type = src.type;
    std::cout<<"Cat copy constructor was called"<<std::endl;
}

Cat & Cat::operator=(Cat const & src)
{
    std::cout<<"Cat assignment operator was called"<<std::endl;
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
