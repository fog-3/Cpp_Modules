#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
private:
    std::string const   _name;
    int                 _grade;

public:
    // Canonical ortodoxal form
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();

    // Getters
    std::string const   getName() const;
    int                 getGrade() const;

    // Increment and decrement functions
    void                incrementGrade();
    void                decrementGrade();

    // Signature function for forms
    void                signForm(Form &form);

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

// Overload of the insertion operator
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif