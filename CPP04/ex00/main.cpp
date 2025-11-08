#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "TEST 1: Basic polymorphism\n";
    {
        const Animal* a = new Animal();
        const Animal* d = new Dog();
        const Animal* c = new Cat();

        std::cout << d->getType() << std::endl;
        std::cout << c->getType() << std::endl;

        a->makeSound(); 
        d->makeSound(); 
        c->makeSound(); 

        delete a;
        delete d;
        delete c;
    }

    std::cout << "\nTEST 2: Pointer to base calls overridden methods\n";
    {
        Animal* animals[2];
        animals[0] = new Dog();
        animals[1] = new Cat();

        for (int i = 0; i < 2; i++)
            animals[i]->makeSound();

        for (int i = 0; i < 2; i++)
            delete animals[i];
    }

    std::cout << "\nTEST 3: WrongAnimal vs WrongCat (no virtual function)\n";
    {
        const WrongAnimal* wa = new WrongAnimal();
        const WrongAnimal* wc = new WrongCat();

        wa->makeSound(); 
        wc->makeSound(); 

        delete wa;
        delete wc;
    }

    std::cout << "\nTEST 4: Direct object test (no polymorphism)\n";
    {
        Dog d;
        Cat c;

        std::cout << d.getType() << std::endl;
        std::cout << c.getType() << std::endl;

        d.makeSound();
        c.makeSound();
    }

    std::cout << "\nTEST 5: Destructor order check via base pointer\n";
    {
        const Animal* d = new Dog();
        const Animal* c = new Cat();

        delete d;
        delete c; 
    }

    return 0;
}
