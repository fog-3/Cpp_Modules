
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 25, 5), _target("DefaultToast") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 25, 5), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        _target = other._target;
        setIsSigned(other.getIsSigned());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::performAction() const {
    int random_number;

	random_number = rand() % 2;

	if (random_number == 1)
		std::cout << "Beeep Be Be Beeeee Beeeeeeeep. " << getName() << " has been robotomized successfully!" << std::endl; 		
	else
		throw RobotizationFailed();
}

const char *RobotomyRequestForm::RobotizationFailed::what() const throw()
{
	return ("Unfortunately robotomy failed.");
}
