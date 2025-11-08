#include "Brain.hpp"


Brain::Brain()
{
    std::cout<<"Default Brain constructor was called"<<std::endl;      
}

Brain::Brain(Brain const & src) 
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = src.ideas[i];
}

Brain::~Brain()
{
    std::cout<<"Destructor was called"<<std::endl;
}

Brain & Brain::operator=(Brain const &src)
{
    if(this!=&src)
    {
        for (size_t i = 0; i < 100; i++)
        {
            this->ideas[i] = src.ideas[i];
        }    
    }
    return *this;
}