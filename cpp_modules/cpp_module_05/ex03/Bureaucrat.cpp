#include "Bureaucrat.hpp"
#include "Form.hpp"

const   char *Bureaucrat::GradeTooHighException::what() const throw() {
    return _err.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &s){
    std::exception();
    _err = s;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const   char *Bureaucrat::GradeTooLowException::what() const throw() {
    return _err.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &s) {
    std::exception();
    _err = s;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::Bureaucrat() {
    std::cout << "Default Bureaucrat Constructor" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string &name) : _note(grade), _name(name) {
    std::cout << "Bureaucrat Constructor" << std::endl;
    try {
        if (_note < 1)
            throw GradeTooHighException("Grade Too High");
        else if (_note > 150)
            throw GradeTooLowException("Grade Too Low");
    } catch (const std::exception &except) {
        std::cout << "An exception has been caught: " << except.what() << std::endl;
    }
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &other) {
    std::cout << "Bureacrat Copy Assignement" << std::endl;
    if (this != &other) {
        _name = other._name;
        _note = other._note;
    }
    return *this;
}

int Bureaucrat::getGrade(void) const {
    return _note;
}

std::string Bureaucrat::getName(void) const {
    return _name;
}

void    Bureaucrat::upRank() {
    try {
        _note = _note - 1;
        if (_note <= 0)
            throw GradeTooHighException("Grade Too High");
    } catch (const std::exception &except) {
        std::cout << "Exception has been caught: " << except.what();
    }
}

void    Bureaucrat::deRank() {
    try {
        _note = _note + 1;
        if (_note > 150)
            throw GradeTooLowException("Grade Too Low");
    } catch (const std::exception &except) {
        std::cout << "Exception has been caught: " << except.what();
    }
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch(std::exception &e){
		std::cerr << this->_name << " cannot sign because " << e.what() <<std::endl;;
	}
}

void   Bureaucrat::executeForm(Form const &form){
    try {
		form.execute(*this);
		std::cout << this->getName() << " executs " << form.getName() << std::endl;
	}
	catch(std::exception &e){
		std::cerr << this->_name << " cannot execute because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << " Bureaucrat name is: " << bureaucrat.getName() << " ranked: " << bureaucrat.getGrade() << std::endl;
    return out;
}