#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <bits/stdc++.h>
int main()
{
    Base * ptr = new B();
    (void)ptr;
    B b;

    Base &b = b; 

    identify(ptr);
    identify(&b);
    return 0;
}

