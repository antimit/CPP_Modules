#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const & src);
    void attack(const std::string& target);
    ~FragTrap();

    FragTrap & operator=(FragTrap  const & src);

    void highFivesGuys(void);
};

#endif