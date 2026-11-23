
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("DefaultPerson") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        _target = other._target;
        setIsSigned(other.getIsSigned());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::performAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
