#include "Cat.hpp"

Cat::Cat() : Animal(), brain()
{
    this->type = "Cat";
    std::cout<<"Default Cat constructor was called"<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor was called"<<std::endl;
}

Cat::Cat(Cat const & src) : Animal(src), brain(src.brain)
{
   this->type = src.type;
   std::cout<<"Cat copy constructor was called"<<std::endl;
}

Cat & Cat::operator=(Cat const & src)
{
    std::cout<<"Cat assignment operator was called"<<std::endl;
    if(this!= &src)
    {
        Animal::operator=(src);
        this->brain = src.brain;
    }
    return *this;
}

void Cat::makeSound()const
{
    std::cout<<"Cat says MEOW"<<std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}

Brain *Cat::getBrain()
{
    return &brain;
}

Brain const *Cat::getBrain() const
{
    return &brain;
}

