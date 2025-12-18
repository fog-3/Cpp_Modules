#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}