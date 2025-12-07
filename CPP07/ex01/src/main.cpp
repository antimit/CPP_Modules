#include "iter.hpp"


void print(std::string str)
{
    std::cout<<"The string is: "<<str<<std::endl;
}


int main()
{
    std::string strs[] = {"Hello", "Hi, GoodBye"};
    
    iter(strs, sizeof(strs)/ sizeof(strs[0]), print);
}