#ifndef SHRUBBERYCREATIONFORM_HPP
#define  SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {
    public:
        typedef Bureaucrat::GradeTooHighException GradeTooHighException;
        typedef Bureaucrat::GradeTooLowException GradeTooLowException;
        explicit ShrubberyCreationForm(const std::string &target);
        virtual ~ShrubberyCreationForm();
        void	execution()const;
        void execute(const Bureaucrat & executor) const;
};

#endif