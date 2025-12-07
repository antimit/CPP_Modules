#include "Serializer.hpp"


int main()
{
    Data  game =  {5,10,10,false,false};

    uintptr_t raw = Serializer::serialize(&game);

    std::cout<<"Raw value is "<<raw<<std::endl;

    Data * result = Serializer::deserialize(raw); 

    std::cout<<"The game level is "<<result->level<<std::endl;
}
