#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

Animal animal[100];

for (size_t i = 0; i < 100; i++)
{
    if(i %2==0)
    {
        animal[i] = Dog();
    } 
    
    else
    {
        animal[i] = Cat();
    }
}


return 0;
}
