#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>
class WrongAnimal
{
    public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const & src);
    virtual ~WrongAnimal();
    WrongAnimal & operator=(WrongAnimal const &src );

    void makeSound() const;

    protected:
    std::string type;
    
    
};

#endif