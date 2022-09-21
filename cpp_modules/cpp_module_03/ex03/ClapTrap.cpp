#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap Constructor" << std::endl;
    _nameClapTrap = "";
    _energyPts = 10;
    _hitPts = 10;
    _attackDmg = 0;
}

ClapTrap::ClapTrap(const std::string &rName) : _nameClapTrap(rName) {
    std::cout << "ClapTrap Copy Constructor" << std::endl;
    _energyPts = 10;
    _hitPts = 10;
    _attackDmg = 0;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor Called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & other) {
    if (this != &other)
    {
        std::cout << "ClapTrap Copy Assignement" << std::endl;
        this->_nameClapTrap = other._nameClapTrap;
        this->_energyPts = other._energyPts;
        this->_hitPts = other._hitPts;
        this->_attackDmg = other._attackDmg;
    }
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap Copy Constructor" << std::endl;
    *this = other;
}

void    ClapTrap::attack(const std::string &target) {
    std::cout << "ClapTrap " << _nameClapTrap << " attack " << target << ", causing " << _hitPts << " points of damage! " << std::endl;
}

void    ClapTrap::takeDamage(uint32_t amount) {
    if (_hitPts - amount < 0)
        return ;
    _hitPts -= amount;
    if (_hitPts < 0)
        _hitPts = 0;
    std::cout << _nameClapTrap << " took " << amount << " damage" << std::endl;
}

void    ClapTrap::beRepaired(uint32_t amount) {
    _hitPts += amount;
    std::cout << _nameClapTrap << " got healed " << amount << " points" << std::endl;
}

int ClapTrap::getHitPts() const {
    return this->_hitPts;
}

int ClapTrap::getEnergyPts() const {
    return this->_energyPts;
}

int ClapTrap::getAttackDmg() const {
    return this->_attackDmg;
}

std::string     ClapTrap::getName() const
{
    return this->_nameClapTrap;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const & ClapTrap) {
    out << ClapTrap.getName() << " got " << ClapTrap.getHitPts() << " hp, " << ClapTrap.getEnergyPts() << " ernegy point and " << ClapTrap.getAttackDmg() << " attack damage" << std::endl;
    return out;
}