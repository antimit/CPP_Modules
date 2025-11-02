#include "ScavTrap.hpp"

int main() {
    std::cout << "Stack object:\n";
    {
        ScavTrap s("Serena");
        s.attack("dummy");
        s.guardGate();
    } 

    std::cout << "\nPolymorphic delete:\n";
    {
        ClapTrap* p = new ScavTrap("Polly");
        p->attack("target");   
        delete p;              
    }

}