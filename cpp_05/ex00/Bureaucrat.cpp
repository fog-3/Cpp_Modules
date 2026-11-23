#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Parameter constructor
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

// Assignment operator (the name is a constant, so we copy the degree)
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters
std::string const Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Increase (as 1 is the highest, increasing it reduces the number)
void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

// Decrement (as 150 is the lowest, decrementing adds one to the number)
void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Operator <<
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}