#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog &other);
	    virtual ~Dog();
	    Dog &operator=(const Dog & other);
        virtual void    makeSound(void) const;
        const Brain  &getBrain() const;
    private:
        Brain *brain;
};

#endif