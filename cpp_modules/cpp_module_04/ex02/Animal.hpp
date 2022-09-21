#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    public:
	    virtual ~Animal();
	    Animal &operator=(const Animal& other);
        virtual void    makeSound(void) const;
        std::string     getType(void) const;
    protected:
        Animal();
        Animal(const Animal &other);
        std::string type;
};

#endif