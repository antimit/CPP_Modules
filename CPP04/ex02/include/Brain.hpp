#ifndef BRAIN_HPP
#define  BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    public: 
    Brain();
    Brain(Brain const & src);
    Brain & operator=(Brain const & src);
    ~Brain();

    private:
    std::string ideas[100];

};

#endif