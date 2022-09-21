#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Constructor" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern Destructor" << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << "Intern Copy Constructor" << std::endl;
    *this = other;
}

Intern  &Intern::operator=(const Intern &other) {
    std::cout << "Intern Copy Assignement" << std::endl;
    (void)other; //Pour les FLAGS
    return *this;
}

Form    *Intern::makeForm(const std::string &fName, const std::string &fTarget) {
    std::string fArr[] = {std::string("robotomy request"), std::string("shrubbery creation"), std::string("presidential pardon")};
    Form        *execArr[] = {new RobotomyRequestForm(fTarget), new ShrubberyCreationForm(fTarget), new PresidentialPardonForm(fTarget)};
    for (int y = 0; y < 3; ++y)
        if (fName == fArr[y]) {
            std::cout << "Intern creates " << fName << std::endl;
            return execArr[y];
        }
    return (NULL);
}