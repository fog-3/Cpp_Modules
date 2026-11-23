#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class Form 
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _gradeToSign;
        int const           _gradeToExecute;
    public:
        // Canonical ortodoxal form
        Form();
        Form(std::string const name, int gradeToSign, int gradeToExecute);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form();

        // Member functions
        void		        beSigned(const Bureaucrat &bureaucrat);
        std::string const   getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        // Custom exceptions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os,  Form const &form);

#endif