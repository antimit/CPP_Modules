#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

typedef std::string str;

class Zombie {
	public:
		Zombie(str name);
        Zombie();
		~Zombie();

        void	announce();

        //setters
        void set_name(std::string name);

        //getters
        std::string get_name();
	private:
		
		str	name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif