#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class   ClapTrap {
    public:
        explicit ClapTrap(std::string const &name);
        ClapTrap(ClapTrap const &clapTrap);
        virtual ~ClapTrap();
        ClapTrap &operator=(ClapTrap const &other);
        void    attack(std::string const &t);
        void    takeDamage(uint32_t amount);
        void    beRepaired(uint32_t amount);
        std::string     getName() const;
        int getHitPts() const;
        int getAttackDmg() const;
        int getEnergyPts() const;
    protected:
        std::string _nameClapTrap;
        int         _hitPts;
        int         _energyPts;
        int         _attackDmg;
        ClapTrap();
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &clapTrap);

#endif