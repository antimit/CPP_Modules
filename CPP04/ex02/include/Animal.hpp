#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal 
{
    public:
    Animal();
    Animal(Animal const & src);
    Animal & operator=(Animal const & src);
    virtual ~Animal();

    //Member functions
    virtual void makeSound()const = 0;
    virtual std::string getType() const = 0;

    protected:
    std::string type;

};


#endif