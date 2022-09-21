#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>
# include <iomanip>


class Weapon {
    public:
                                Weapon();
        explicit                Weapon(std::string const & type);
                                ~Weapon(void);
        std::string const       &getType(void) const;
        void                    setType(const std::string &str);

    private:
        std::string _ref;
};

#endif