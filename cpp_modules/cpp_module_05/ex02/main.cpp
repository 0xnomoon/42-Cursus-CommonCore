#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

	std::cout << "TEST W LVL HIGH ENOUGH" << std::endl;
	Form *form_house = new ShrubberyCreationForm("House");
	Form *form_yeer = new PresidentialPardonForm("Yeer");
	Form *form_robot = new RobotomyRequestForm("Robot");
	Bureaucrat eric(5, "Joe");

	eric.signForm(*form_house);
	eric.executeForm(*form_house);

	eric.signForm(*form_yeer);
	eric.executeForm(*form_yeer);

	eric.signForm(*form_robot);
	eric.executeForm(*form_robot);

	std::cout << "TEST W LVL TOO LOW" << std::endl;
	Bureaucrat david(150, "hhhh");

	david.signForm(*form_house);
	david.executeForm(*form_house);

	david.signForm(*form_yeer);
	david.executeForm(*form_yeer);

	david.signForm(*form_robot);
	david.executeForm(*form_robot);
	return (0);

}