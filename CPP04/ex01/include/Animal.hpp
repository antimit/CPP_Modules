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
    void makeSound()const;
    std::string getType() const;

    protected:
    std::string type;

};


#endif