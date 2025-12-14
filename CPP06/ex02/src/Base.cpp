#include "Base.hpp"


#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base()
{
    
}
Base* generate()
{

    switch (std::rand()%3)
    {
    case 0:
        return (new A());
    case 1:
        return (new B());
    case 2:
        return (new C());
    
    default:
        std::cout << "Error encountered on Base generate" << std::endl;
        exit(1);
    }
}

void identify(Base * ptr)
{
    if(dynamic_cast<A*>(ptr))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(ptr))
    {
        std::cout << "B" << std::endl;
    }
    else if(dynamic_cast<C*>(ptr))
    {
        std::cout << "C" << std::endl;
    }
    else 
    {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base & val)
{
    try
    {
        (void)dynamic_cast<A&>(val);
        std::cout << "A" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
    }
    
    try
    {
        (void)dynamic_cast<B&>(val);
        std::cout << "B" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
    }

    try
    {
        (void)dynamic_cast<C&>(val);
        std::cout << "C" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
    }
    std::cout << "Unknown type" << std::endl;
}