#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

static void banner(const std::string& title)
{
    std::cout << "\n==================== " << title << " ====================\n";
}

int main()
{
    
    banner("Stack DiamondTrap: ctor order (ClapTrap -> ScavTrap/FragTrap -> DiamondTrap) and dtor order (reverse)");
    {
        DiamondTrap d("Serena");
        d.whoAmI();
        d.attack("dummy");     
        d.guardGate();         
        d.highFivesGuys();    
    }

    banner("attack() source check (should print 'ScavTrap Serena attacks ...')");
    {
        DiamondTrap d("Scout");
        d.attack("target"); 
    }

    banner("Single ClapTrap virtual base proof (addresses must match)");
    {
        DiamondTrap d("Uni");
        ScavTrap* asScav = static_cast<ScavTrap*>(&d);
        FragTrap* asFrag = static_cast<FragTrap*>(&d);

        ClapTrap* baseViaScav = static_cast<ClapTrap*>(asScav);
        ClapTrap* baseViaFrag = static_cast<ClapTrap*>(asFrag);

        std::cout << "ClapTrap via ScavTrap: " << baseViaScav << std::endl;
        std::cout << "ClapTrap via FragTrap: " << baseViaFrag << std::endl;
        std::cout << "Same address? " << (baseViaScav == baseViaFrag ? "YES (one ClapTrap base)" : "NO (BUG)") << std::endl;

        d.whoAmI();
    }

    
    banner("Attribute mix check (HP=100, EP=50, AD=30) via behavior");
    {
        DiamondTrap d("Stats");
        for (int i = 0; i < 51; ++i)
            d.attack("battery-test");
        d.takeDamage(40); 
        d.beRepaired(20);
        d.whoAmI();
    }

    banner("Dead behavior (HP=0 blocks actions)");
    {
        DiamondTrap d("Morty");
        d.takeDamage(100);      
        d.attack("won't work"); 
        d.beRepaired(10);      
        d.whoAmI();
    }

    
    banner("DONE");
    return 0;
}
