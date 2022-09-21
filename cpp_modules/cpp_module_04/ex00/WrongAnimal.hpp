#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
	    virtual ~WrongAnimal();
	    WrongAnimal &operator=(const WrongAnimal& other);
        virtual void    makeSound(void) const;
        std::string     getType(void) const;
    protected:
        std::string type;
};

#endif