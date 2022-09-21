#ifndef ROBOTOMYREQUESTFORM_HPP
#define  ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form {
    public:
        typedef Bureaucrat::GradeTooHighException GradeTooHighException;
        typedef Bureaucrat::GradeTooLowException GradeTooLowException;
        RobotomyRequestForm();
        explicit RobotomyRequestForm(const std::string &target);
        virtual ~RobotomyRequestForm();
        void	execution()const;
        void execute(const Bureaucrat & executor) const;
};

#endif