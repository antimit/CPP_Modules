#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon
{
    private:
    std::string type;

    public:
    Weapon(std::string name);
    Weapon();
    ~Weapon();
    const std::string getType();
    void setType(std::string type);
};

#endif