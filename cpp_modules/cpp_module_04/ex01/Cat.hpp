#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat &other);
	    virtual ~Cat();
	    Cat &operator=(const Cat& other);
        virtual void    makeSound(void) const;
        const Brain  &getBrain() const;
    private:
        Brain *brain;
};

#endif