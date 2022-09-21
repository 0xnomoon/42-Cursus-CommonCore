#ifndef PRESIDENTIALPARDONFORM_HPP
#define  PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
    public:
        typedef Bureaucrat::GradeTooHighException GradeTooHighException;
        typedef Bureaucrat::GradeTooLowException GradeTooLowException;
        explicit    PresidentialPardonForm(const std::string &target);
        virtual     ~PresidentialPardonForm();
        void execution() const;
        void execute(const Bureaucrat & executor) const;
};

#endif