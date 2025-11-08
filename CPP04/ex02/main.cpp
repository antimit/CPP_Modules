#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <exception>

void test_basic_creation() {
    std::cout << "\n===== TEST 1: Basic construction/destruction =====\n";

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete dog; 
    delete cat; 
}

void test_animal_array() {
    std::cout << "\n===== TEST 2: Polymorphic Animal array =====\n";

    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "--- Deleting array elements ---\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];
}

void test_assignment_operator() {
    std::cout << "\n===== TEST 4: Assignment operator deep copy =====\n";

    Cat cat1;
    Cat cat2;
    cat1.getBrain()->setIdea(0, "Jump on the table");

    cat2 = cat1; 
    cat1.getBrain()->setIdea(0, "Scratch the sofa");

    std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << "\n";
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << "\n";
}


void test_mass_allocation() {
    std::cout << "\n===== TEST 5: Mass allocation & cleanup =====\n";

    const int count = 20;
    Animal* zoo[count];

    for (int i = 0; i < count; ++i)
        zoo[i] = (i % 2 == 0) ? (Animal*)new Dog() : (Animal*)new Cat();

    for (int i = 0; i < count; ++i)
        delete zoo[i];

    std::cout << "Mass allocation/destruction completed without crash\n";
}



void test_deep_copy() {
    std::cout << "\n===== TEST 3: Deep copy of Brain =====\n";

    Dog original;
    original.getBrain()->setIdea(0, "Chase squirrels");
    original.getBrain()->setIdea(1, "Eat bone");

    Dog copy(original);

    original.getBrain()->setIdea(0, "Sleep all day");

    std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << "\n";
    std::cout << "Copy idea[0]:     " << copy.getBrain()->getIdea(0) << "\n";

    if (original.getBrain() != copy.getBrain())
        std::cout << "Deep copy confirmed\n";
    else
        std::cout << "Shallow copy detected\n";
}


int main()
{

     Animal *animal[100];

    for (size_t i = 0; i < 100; i++)
    {
        if (i % 2 == 0)
        {
            animal[i] = new Dog();
        }

        else
        {
            animal[i] = new Cat();
        }
    }

    for (size_t i = 0; i < 100; i++)
    {
        delete animal[i];
    }

    try
    {
        test_basic_creation();
        test_animal_array();
        test_deep_copy();
        test_assignment_operator();
        test_mass_allocation();
    }
    catch (std::exception const &e)
    {
        std::cerr << "Unhandled exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
