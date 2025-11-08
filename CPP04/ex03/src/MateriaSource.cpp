#include "MateriaSource.hpp"

  
MateriaSource::MateriaSource() : _idxTotal(0)
{
    std::cout<<"Default MaterialSource constructor was called"<<std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src) :_idxTotal(src._idxTotal)
{
    for (int i = 0; i < _idxTotal; i++)
    {
        if (src.memory[i])
            memory[i] = src.memory[i]->clone();
        else
            memory[i] = NULL;
    }
    
}

IMateriaSource::~IMateriaSource()
{
    std::cout <<"IMateria destructor was called"<<std::endl;
}

MateriaSource::~MateriaSource()
{
    std::cout<<"MaterialSource destructor was called"<<std::endl;

    for (int i = 0; i < this->_idxTotal ; i++)
    {
        if(memory[i] != NULL)
        delete memory[i];
    }
    
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
    if(this != &src)
    {
        for (int i = 0; i < this->_idxTotal; i++)
        {
            if (memory[i])
            {
                delete memory[i];
                memory[i] = NULL;
            }
        }
        this->_idxTotal = 0;
        for (int i = 0; i < src._idxTotal; i++)
        {
            if (src.memory[i])
            {
                memory[i] = src.memory[i]->clone();
                this->_idxTotal++;
            }
            else
                memory[i] = NULL;
        }
    }

    return *this;
}

void MateriaSource::getMemory() const 
{
    std::cout<<"MaterialSource memory has: "<<std::endl;

    for (int i = 0; i < this->_idxTotal; i++)
    {
        std::cout<<"Memory at index "<<i <<" has type "<<this->memory[i]->getType()<<std::endl;
    }
}

void MateriaSource::learnMateria(AMateria * materia)
{
    if(this->_idxTotal == 4)
    {
        std::cout <<"The inventory is full"<<std::endl;
    }

    if (!materia)
        return;
    if (this->_idxTotal >= 4)
        return;
    this->memory[this->_idxTotal] = materia;
    this->_idxTotal++;
}


AMateria * MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _idxTotal; i++)
    {
        if(this->memory[i] && this->memory[i]->getType() == type)
        {
            return this->memory[i]->clone();
        }
    }
    
    std::cout<<"The MateriaSource doesn't have specified materia type: "<< type<<" in its memory"<<std::endl;

    return NULL;
}

