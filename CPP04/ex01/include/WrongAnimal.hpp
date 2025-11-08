#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>
class WrongAnimal
{
    public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const & src);
    ~WrongAnimal();
    WrongAnimal & operator=(WrongAnimal const &src );

    virtual void makeSound();

    protected:
    std::string type;
    
    
};

#endif