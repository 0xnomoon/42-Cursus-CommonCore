#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap Constructor" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor" << std::endl;
}

ScavTrap::ScavTrap(std::string const &pName) : ClapTrap(pName) {
    std::cout << "ScavTrap Constructor" << std::endl;
    _hitPts = 100;
    _energyPts = 50;
    _attackDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor" << std::endl;
    this->_name = other._name;
    this->_energyPts = other._energyPts;
    this->_hitPts = other._hitPts;
    this->_attackDmg = other._attackDmg;
}

ScavTrap &ScavTrap::operator=(ScavTrap const & other) {
    std::cout << "Scavtrap Copy Assignement" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_energyPts = other._energyPts;
        this->_hitPts = other._hitPts;
        this->_attackDmg = other._attackDmg;
    }
    return *this;
}

void    ScavTrap::attack(const std::string &target) {
    std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _hitPts << " points of damage! " << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap entered in gate keeper mode" << std::endl;
}

int ScavTrap::getHitPts() const {
    return this->_hitPts;
}

int ScavTrap::getEnergyPts() const {
    return this->_energyPts;
}

int ScavTrap::getAttackDmg() const {
    return this->_attackDmg;
}

std::string     ScavTrap::getName() const
{
    return this->_name;
}

std::ostream &operator<<(std::ostream &out, ScavTrap const & ScavTrap) {
    out << ScavTrap.getName() << " got " << ScavTrap.getHitPts() << " hp, " << ScavTrap.getEnergyPts() << " ernegy point and " << ScavTrap.getAttackDmg() << " attack damage" << std::endl;
    return out;
}