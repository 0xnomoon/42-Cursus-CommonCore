#include "Form.hpp"

const   char *Form::GradeTooHighException::what() const throw() {
    return _err.c_str();
}

Form::GradeTooHighException::GradeTooHighException(const std::string &s){
    std::exception();
    _err = s;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const   char *Form::GradeTooLowException::what() const throw() {
    return _err.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string &s) {
    std::exception();
    _err = s;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::Form(const std::string &name, int requiredRankToExec, int requiredRankToSign) {
    std::cout << "Form Constructor" << std::endl;
    _name = name;
    _isSigned = false;
    _requiredRankToSign = requiredRankToSign;
    _requiredRankToExec = requiredRankToExec;
    if (requiredRankToSign < 1 || requiredRankToExec < 1)
        throw Form::GradeTooHighException("Grade Too High");
    else if (requiredRankToSign > 150 || requiredRankToExec > 150)
        throw Form::GradeTooLowException("Grade Too Low");
}

Form::Form(const Form &other) {
    std::cout << "Form Copy Constructor" << std::endl;
        _name = other._name;
        _isSigned = other._isSigned;
        _requiredRankToExec = other._requiredRankToExec;
        _requiredRankToSign = other._requiredRankToSign;
}

Form::~Form() {std::cout << "Form Destructor" << std::endl;}

Form &Form::operator=(const Form &other) {
    std::cout << "Form Copy Assignement" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

void            Form::beSigned(const Bureaucrat &bureaucrat) {
    if(bureaucrat.getGrade() <= _requiredRankToSign)
        _isSigned = true;
    else
        throw Form::GradeTooLowException("Grade Too Low");
}

const char* Form::NotSign::what() const throw(){return ("Form not sign");}

void Form::execute(Bureaucrat const &executor)const{
	if (this->_isSigned == false)
		throw Form::NotSign();
	else if (executor.getGrade() > this->_requiredRankToExec)
		throw Form::GradeTooLowException("Grade Too Low");
	this->execution(); 
}

bool                Form::isItSigned() const {return _isSigned;}
const std::string   &Form::getName() const {return _name;}
int                 Form::getRequiredRankToSign() const {return _requiredRankToSign;}
int                 Form::getRequiredRankToExec() const {return _requiredRankToExec;}


std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Name: " << form.getName() << std::endl << "Signed: " << form.isItSigned() << std::endl << "Required Rank To Exec: " << form.getRequiredRankToExec() << std::endl << "Required Rank To Sign: " << form.getRequiredRankToSign() << std::endl;
    return out;
}