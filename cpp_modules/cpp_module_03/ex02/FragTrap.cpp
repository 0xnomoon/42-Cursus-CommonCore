#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap Constructor" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
    std::cout << "Fragtrap Constructor" << std::endl;
    _hitPts = 100;
    _attackDmg = 30;
    _energyPts = 100;
}

FragTrap::~FragTrap() {
    std::cout << "Destructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	std::cout << "FragTrap constructor" << std::endl;
	_hitPts =  other._hitPts;
	_energyPts = other._energyPts;
	_attackDmg = other._attackDmg;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    if (this != &other) {
        std::cout << "FragTrap Copy Assignement" << std::endl;
        _name = other._name;
        _hitPts = other._hitPts;
        _attackDmg = other._attackDmg;
        _energyPts = other._energyPts;
    }
    return *this;
}

void    FragTrap::highFivesGuys() {
    std::cout << "( ⌒o⌒)人(⌒-⌒ )v" << std::endl << std::endl;
}

void    FragTrap::attack(const std::string &target) {
    std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _hitPts << " points of damage! " << std::endl;
}

int FragTrap::getHitPts() const {
    return this->_hitPts;
}

int FragTrap::getEnergyPts() const {
    return this->_energyPts;
}

int FragTrap::getAttackDmg() const {
    return this->_attackDmg;
}

std::string     FragTrap::getName() const
{
    return this->_name;
}

std::ostream &operator<<(std::ostream &out, FragTrap const & FragTrap) {
    out << FragTrap.getName() << " got " << FragTrap.getHitPts() << " hp, " << FragTrap.getEnergyPts() << " ernegy point and " << FragTrap.getAttackDmg() << " attack damage" << std::endl;
    return out;
}