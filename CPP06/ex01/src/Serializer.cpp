#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout<<"Default Serialize constructor was called"<<std::endl;
}


Serializer & Serializer::operator=(Serializer const & src)
{
    if(this != &src)
        return *this;
    return *this;
}

Serializer::~Serializer()
{
    std::cout<<"Default Serialize destructor was called"<<std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data * Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *> (raw));
}