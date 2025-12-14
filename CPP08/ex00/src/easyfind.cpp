#include "easyfind.hpp"


const char * ValueNotFound::what() const throw()
{
    return ("The value was not found in the container");
} 
