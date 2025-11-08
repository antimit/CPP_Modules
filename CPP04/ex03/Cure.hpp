#ifndef CURE_HPP
#define CURE_HPP

class Cure 
{
    public:
    Cure();
    Cure(Cure const & src);
    Cure & operator=(Cure const & src);
    Cure & clone();
    ~Cure();
};


#endif