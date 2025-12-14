#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>


class ValueNotFound : public std::exception {
  public:
    virtual const char *what() const throw();
};

template<typename T>
void easyfind(T container, int toBeFound)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), toBeFound);

    if(it == container.end())
        throw ValueNotFound();
    std::cout<<"Found the value"<<toBeFound<<"in position"<<std::distance(container.begin(),it)<<std::endl;
}





#endif