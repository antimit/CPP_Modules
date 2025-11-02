#include "ClapTrap.hpp"
#include <iostream>
#include <string>

static void banner(const std::string& title)
{
    std::cout << "\n==================== " << title << " ====================\n";
}

int main()
{
    banner("Test 1: Basic flow (attack -> repair -> takeDamage)");
    {
        ClapTrap john("John");
        john.attack("Dummy");
        john.beRepaired(4);
        john.takeDamage(1);
        john.attack("Dummy");
        
        john.beRepaired(1000);
         
        john.takeDamage(0);
    } 

    banner("Test 2: Energy exhaustion (10 energy total)");
    {
        ClapTrap eddie("Eddie");
        for (int i = 0; i < 9; ++i)
            eddie.attack("Target");
        eddie.beRepaired(1);
      
        eddie.attack("Target");       
        eddie.beRepaired(3);       
    }

    banner("Test 3: Overkill damage and post-death behavior");
    {
        ClapTrap daisy("Daisy");
        daisy.takeDamage(5);         
        daisy.attack("Target");
        daisy.takeDamage(9999);     
        daisy.attack("Target");     
        daisy.beRepaired(5);          
                                      
        daisy.takeDamage(1);         
    }

    banner("Test 4: Repair capping behavior");
    {
        ClapTrap rhea("Rhea");
        rhea.takeDamage(3);          
        rhea.beRepaired(2);           
        rhea.beRepaired(5);        
        rhea.beRepaired(1);          
    }

   
    banner("Test 5: Default constructor ‘Unnamed’");
    {
        ClapTrap unnamed;             
        unnamed.attack("Target");
        unnamed.takeDamage(10);     
        unnamed.beRepaired(3);       

    banner("DONE");
    }
    return 0;
    
}
