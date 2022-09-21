#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap"), FragTrap(name), ScavTrap(name), _name(name) {
    std::cout << "DiamondTrap Constructor" << std::endl;
    _energyPts = 50;
    _attackDmg = 30;
    _hitPts = 100;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
	std::cout << "DiamondTrap copy constructor." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &other){
    std::cout << "DiamondTrap copy assignement" << std::endl;
    if (this != &other)
    {
        this->_name = ClapTrap::getName();
        this->_hitPts = FragTrap::getHitPts();
        this->_energyPts = ScavTrap::getEnergyPts();
        this->_attackDmg = FragTrap::getAttackDmg();
    }
    return *this;
}

void    DiamondTrap::attack(std::string const &target) {
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI() {
    std::cout << "I'm " << _name << " and " << ClapTrap::_nameClapTrap << " is my ClapTrap name eheh" << std::endl;
}

void   DiamondTrap::highFive() {
    FragTrap::highFivesGuys();
}

void    DiamondTrap::keepGate() {
    ScavTrap::guardGate();
}

std::string    DiamondTrap::getName() const {
    return this->_name;
}

int     DiamondTrap::getHitPts() const {
    return FragTrap::getHitPts();
}

int     DiamondTrap::getEnergyPts() const {
    return ScavTrap::getEnergyPts();
}

int     DiamondTrap::getAttackDmg() const {
    return FragTrap::getAttackDmg();
}

std::ostream &operator<<(std::ostream &out, DiamondTrap const &DiamondTrap) {
    out << DiamondTrap.getName() << " got " << DiamondTrap.getHitPts() << " hp, " << DiamondTrap.getEnergyPts() << " ernegy point and " << DiamondTrap.getAttackDmg() << " attack damage" << std::endl;
    return out;
}