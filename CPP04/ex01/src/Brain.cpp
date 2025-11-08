#include "Brain.hpp"
#include <stdexcept>


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
        for (std::size_t i = 0; i < 100; i++)
        {
            this->ideas[i] = src.ideas[i];
        }    
    }
    return *this;
}

void Brain::setIdea(std::size_t index, std::string const &idea)
{
    if (index >= 100)
        throw std::out_of_range("Brain idea index out of range");
    ideas[index] = idea;
}

std::string const &Brain::getIdea(std::size_t index) const
{
    if (index >= 100)
        throw std::out_of_range("Brain idea index out of range");
    return ideas[index];
}