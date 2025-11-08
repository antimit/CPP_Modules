#include "AMateria.hpp"

#include "Character.hpp"

#include "Cure.hpp"

#include "Ice.hpp"

#include "MateriaSource.hpp"


void test_basic_usage() {
    std::cout << "\n===== TEST 1: Basic creation and use =====\n";

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* bob = new Character("Bob");

    AMateria* ice = src->createMateria("ICE");
    AMateria* cure = src->createMateria("CURE");

    bob->equip(ice);
    bob->equip(cure);

    bob->use(0, *bob); 
    bob->use(1, *bob); 

    delete bob;
    delete src;
}


void test_inventory_limits() {
    std::cout << "\n===== TEST 2: Equip overflow & unequip =====\n";

    Character alice("Alice");
    AMateria* m1 = new Ice();
    AMateria* m2 = new Ice();
    AMateria* m3 = new Cure();
    AMateria* m4 = new Cure();
    AMateria* m5 = new Ice(); 

    alice.equip(m1);
    alice.equip(m2);
    alice.equip(m3);
    alice.equip(m4);
    alice.equip(m5); 

    alice.unequip(1);
    alice.unequip(3);
    alice.use(1, alice);

	
    alice.unequip(0);
    alice.unequip(2);
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
}


void test_deep_copy_source() {
    std::cout << "\n===== TEST 3: Deep copy of MateriaSource =====\n";

    MateriaSource original;
    original.learnMateria(new Ice());
    original.learnMateria(new Cure());

    MateriaSource copy(original);

    std::cout << "Original memory types:\n";
    original.getMemory();

    std::cout << "Copy memory types:\n";
    copy.getMemory();

}

void test_unknown_type() {
    std::cout << "\n===== TEST 4: Unknown materia type =====\n";

    MateriaSource src;
    src.learnMateria(new Ice());
    
    AMateria* unknown = src.createMateria("FIRE");

    if (!unknown)
        std::cout << "Unknown materia returned nullptr as expected\n";
    else
        std::cout << "Error: Should not create unlearned materia\n";
}


void test_character_copy() {
    std::cout << "\n===== TEST 5: Character copy & assignment =====\n";

    Character original("Hero");
    original.equip(new Ice());
    original.equip(new Cure());

    Character copy(original); 
    Character assigned;
    assigned = original;

    std::cout << "Original uses:\n";
    original.use(0, original);
    original.use(1, original);

    std::cout << "Copy uses:\n";
    copy.use(0, copy);
    copy.use(1, copy);

    std::cout << "Assigned uses:\n";
    assigned.use(0, assigned);
    assigned.use(1, assigned);
}

int main() {
    test_basic_usage();
    test_inventory_limits();
    test_deep_copy_source();
    test_unknown_type();
    test_character_copy();
    return 0;
}