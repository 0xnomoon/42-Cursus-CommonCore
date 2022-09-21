#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(FragTrap const &name);
        virtual ~FragTrap();
        explicit FragTrap(std::string const& name);
        FragTrap &operator=(FragTrap const &other);
        std::string     getName() const;
        int getHitPts() const;
        int getAttackDmg() const;
        int getEnergyPts() const;
        void    attack(std::string const & target);
	    void    highFivesGuys(void);
};

std::ostream &operator<<(std::ostream &out, FragTrap const & fragTrap);

#endif