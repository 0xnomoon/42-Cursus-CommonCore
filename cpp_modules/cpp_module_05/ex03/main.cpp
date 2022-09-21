#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Bureaucrat uuu(1, "uuu");
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->beSigned(uuu);
	rrf->execute(uuu);
	
	Bureaucrat uu(5, "Kar");
	Intern newRandomIntern;
	Form *rf;
	rf = newRandomIntern.makeForm("shrubbery creation", "Joe");
	rf->beSigned(uu);
	rf->execute(uu);

	Bureaucrat u(1, "Rar");
	Intern newwRandomIntern;
	Form *rrrf;
	rrrf = newwRandomIntern.makeForm("presidential pardon", "hhhh");
	rrrf->beSigned(u);
	rrrf->execute(u);
}
