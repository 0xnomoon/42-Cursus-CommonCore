#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {
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
        ~Bureaucrat();
        Bureaucrat(int grade, const std::string& name);
        Bureaucrat &operator=(Bureaucrat const &other);
        int getGrade(void) const ;
        std::string getName(void) const ;
        void    upRank(void);
        void    deRank(void);
        void    signForm(const Form& form);
    private:
        Bureaucrat();
        int _note;
        std::string _name;
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif