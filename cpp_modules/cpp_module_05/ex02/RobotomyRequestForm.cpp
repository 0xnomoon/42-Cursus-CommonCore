#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form(target, 45, 72) {
    std::cout << "RobotomyRequestForm constructor that call Form" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::execution() const {
    srand(time(NULL)); // Initialise la fonction srand (Initialize random number generator) sur le temps actuel
    int i = rand() % 2;
    if (i) 
        std::cout << this->getName() << " well been robotomized" << std::endl;
    else
        std::cout << "Failure Failure Failure" << std::endl;
}