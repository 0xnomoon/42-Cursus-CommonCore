#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        virtual ~ScavTrap();
        explicit ScavTrap(std::string const &name);
        ScavTrap(ScavTrap const &scavTrap);
        ScavTrap &operator=(ScavTrap const &other);
        void    attack(std::string const & target);
        void    guardGate();
        std::string     getName() const;
        int getHitPts() const;
        int getAttackDmg() const;
        int getEnergyPts() const;
};

std::ostream &operator<<(std::ostream &out, ScavTrap const & scavTrap);

#endif