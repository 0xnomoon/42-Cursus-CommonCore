#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form(target, 5, 25) {
    std::cout << "PresidentialPardonForm constructor that call Form" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor" << std::endl;
}

void    PresidentialPardonForm::execution() const {
    std::cout << this->getName() << " was forgiven by Zafod Beeblebrox" << std::endl;
}