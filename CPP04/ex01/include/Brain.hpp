#ifndef BRAIN_HPP
#define  BRAIN_HPP

#include <string>
#include <iostream>
#include <cstddef>

class Brain
{
    public: 
    Brain();
    Brain(Brain const & src);
    Brain & operator=(Brain const & src);
    ~Brain();

    void setIdea(std::size_t index, std::string const &idea);
    std::string const &getIdea(std::size_t index) const;

    private:
    std::string ideas[100];

};

#endif