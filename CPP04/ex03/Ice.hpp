#ifndef ICE_HPP
#define ICE_HPP


class Ice
{
    Ice();
    Ice(Ice const & src);
    Ice &operator=(Ice const & src);
    Ice & clone();
    ~Ice();

};

#endif