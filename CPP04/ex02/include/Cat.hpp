#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
    //The Orthodox Canonical Class Form
    Cat();
    ~Cat();
    Cat(Cat const & src);
    Cat & operator=(Cat const & src);
    

    //Member functions
    virtual void makeSound() const;
    virtual std::string getType()const;
    Brain *getBrain();
    Brain const *getBrain() const;


    private:
    Brain brain;
};

#endif