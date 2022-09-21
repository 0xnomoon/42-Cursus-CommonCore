#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        explicit Intern(const Intern& other);
	    Intern& operator=(const Intern& other);
	    Form* makeForm(const std::string &formName, const std::string &formTarget);
};

#endif