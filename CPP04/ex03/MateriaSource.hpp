#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
    public:
    virtual ~IMateriaSource();
    virtual void getMemory() const = 0;

    virtual void    learnMaterial(AMateria * materia) = 0;
    virtual AMateria *      createMateria(std::string const & type);
};


class MateriaSource : public IMateriaSource
{
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