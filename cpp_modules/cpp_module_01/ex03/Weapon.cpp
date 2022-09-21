#include "Weapon.hpp"

Weapon::Weapon() 
{
}

Weapon::Weapon(const std::string &ref)
{
    _ref = ref;
}

Weapon::~Weapon(void)
{
}

void    Weapon::setType(const std::string &str)
{
   _ref = str;
}

const std::string &Weapon::getType(void) const
{
    return _ref;
}
