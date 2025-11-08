#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class ICharacter;

class MateriaSource :  public IMateriaSource
{
    public:
    MateriaSource();
    MateriaSource(MateriaSource const & src);
    virtual ~MateriaSource();

    MateriaSource & operator=(MateriaSource const & src);

    virtual void getMemory() const;

    virtual void learnMateria(AMateria * materia);
    virtual AMateria * createMateria(std::string const & type);

    private:
    int     _idxTotal;
    AMateria * memory[4];
};

#endif