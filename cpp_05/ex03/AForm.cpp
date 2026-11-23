/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:30:14 by fernando          #+#    #+#             */
/*   Updated: 2026/11/23 17:22:35 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor
AForm::AForm() : _name("AbstractForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Parameter constructor
AForm::AForm(const std::string name, const int signGrade, const int executeGrade) : _name(name), _isSigned(false), _gradeToSign(signGrade), _gradeToExecute(executeGrade) {}

// Copy constructor
AForm::AForm(AForm const &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// Assignment operator (the name and grades are constants, so we only copy the signed status)
AForm &AForm::operator=(AForm const &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}

// Member function to sign the form
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (_isSigned == false)
		throw IsNotSignedException();
	if (_gradeToExecute < executor.getGrade())
		throw GradeTooLowException();

	performAction();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::IsNotSignedException::what() const throw()
{
	return ("Form can not be executed, because it is not signed!");
}

// Overload of the insertion operator
std::ostream &operator<<(std::ostream &os, AForm const &form) {
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
