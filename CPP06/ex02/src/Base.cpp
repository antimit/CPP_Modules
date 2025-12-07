#include "Base.hpp"


#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <bits/stdc++.h>

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
        std::cout<<"The type is A"<<std::endl;
    }
    else if (dynamic_cast<B*>(ptr))
    {
        std::cout<<"The type is B"<<std::endl;
    }
    else if(dynamic_cast<C*>(ptr))
    {
        std::cout<<"The type is C"<<std::endl;
    }
    else 
    {
        std::cout<<"Uknown type"<<std::endl;
    }
}

void identify(Base & val)
{
    try
    {
        (void)dynamic_cast<A&>(val);
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        (void)dynamic_cast<B&>(val);
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        (void)dynamic_cast<C&>(val);
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"Uknown type"<<std::endl;
}