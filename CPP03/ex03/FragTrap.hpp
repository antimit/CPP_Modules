#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const & src);
    virtual void attack(const std::string& target);
    ~FragTrap();

    FragTrap & operator=(FragTrap  const & src);

    void highFivesGuys(void);
};

#endif