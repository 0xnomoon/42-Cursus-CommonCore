#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    public:
        class GradeTooHighException : public std::exception {
            public:
                explicit GradeTooHighException(const std::string &str);
                virtual const char *what() const throw();
                virtual ~GradeTooHighException() throw();
            private:
                std::string _err;
        };
        class GradeTooLowException : public std::exception {
            public:
                explicit GradeTooLowException(const std::string &str);
                virtual const char *what() const throw();
                virtual ~GradeTooLowException() throw();
            private:
                std::string _err;
        };
        Form();
        Form(const std::string &name, int requiredRankToExec, int requiredRankToSign);
        Form(const Form &other);
        ~Form();
        Form &operator=(const Form &other);
        void    beSigned(const Bureaucrat &bureaucrat);
        const   std::string &getName() const;
        bool    isItSigned() const;
        int     getRequiredRankToSign() const;
        int     getRequiredRankToExec() const;
    private:
        std::string _name;
        bool    _isSigned;
        int    _requiredRankToSign;
        int     _requiredRankToExec;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif