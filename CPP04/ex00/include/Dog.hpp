#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal 
{
    public:
    //The Orthodox Canonical Class Form
    Dog();
    ~Dog();
    Dog(Dog const & src);
    Dog & operator=(Dog const & src);

    //MemberFunctions
    void makeSound() const;
    
    

};

#endif