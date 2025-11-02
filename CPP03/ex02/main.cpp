#include "FragTrap.hpp"

int main() {
    std::cout << "Stack object:\n";
    {
        FragTrap f("Franky");
        f.attack("dummy");
        f.highFivesGuys();
    } 

    std::cout << "\nPolymorphic delete:\n";
    {
        ClapTrap* p = new FragTrap("Poly");
        p->attack("target");
        delete p;
    }
}