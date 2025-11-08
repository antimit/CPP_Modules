#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public virtual Animal 
{
    public:
    //The Orthodox Canonical Class Form
    Dog();
    ~Dog();
    Dog(Dog const & src);
    Dog & operator=(Dog const & src);

    //MemberFunctions
    virtual void makeSound() const;
    virtual std::string getType()const;
    
    
    private:
    Brain brain;
};

#endif