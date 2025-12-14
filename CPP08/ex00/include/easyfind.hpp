#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class ValueNotFound : public std::exception {
public:
    virtual const char *what() const throw();
};

template<typename T>
typename T::iterator easyfind(T &container, int toBeFound)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toBeFound);

    if (it == container.end())
        throw ValueNotFound();
    return it;
}

#endif