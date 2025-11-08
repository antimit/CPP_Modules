#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal 
{
    public:
    //The Orthodox Canonical Class Form
    Cat();
    ~Cat();
    Cat(Cat const & src);
    Cat & operator=(Cat const & src);
    

    //Member functions
    void makeSound() const;
};

#endif