/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:23:01 by fosuna-g          #+#    #+#             */
/*   Updated: 2026/11/23 17:23:02 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "\n========== CPP05 EX03 TESTS ==========\n";

    Intern intern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat manager("Manager", 70);
    Bureaucrat employee("Employee", 150);

    AForm* form = NULL;

    // TEST 1: Shrubbery Creation
    std::cout << "\n--- TEST 1: SHRUBBERY ---\n";

    form = intern.makeForm("shrubbery creation", "garden");

    if (form) {
        std::cout << *form << std::endl;
        employee.signForm(*form);    // Should fail
        manager.signForm(*form);     // Should succeed
        manager.executeForm(*form);  // Should succeed
        delete form;
    }

    // TEST 2: Robotomy Request
    std::cout << "\n--- TEST 2: ROBOTOMY ---\n";

    form = intern.makeForm("robotomy request", "Bender");

    if (form) {
        std::cout << *form << std::endl;
        manager.signForm(*form);     // Should succeed
        manager.executeForm(*form);  // Should fail
        boss.executeForm(*form);     // Should succeed (50%)
        delete form;
    }

    // TEST 3: Presidential Pardon
    std::cout << "\n--- TEST 3: PRESIDENTIAL PARDON ---\n";

    form = intern.makeForm("presidential pardon", "Arthur Dent");

    if (form) {
        std::cout << *form << std::endl;
        manager.signForm(*form);     // Should fail
        boss.signForm(*form);        // Should succeed
        boss.executeForm(*form);     // Should succeed
        delete form;
    }

    // TEST 4: Invalid form
    std::cout << "\n--- TEST 4: INVALID FORM ---\n";

    form = intern.makeForm("invalid form", "Nobody");

    if (form == NULL)
        std::cout << "Correct: NULL returned" << std::endl;
    else
        delete form;

    // TEST 5: Unsigned form
    std::cout << "\n--- TEST 5: UNSIGNED FORM ---\n";

    form = intern.makeForm("shrubbery creation", "unsigned");

    if (form) {
        boss.executeForm(*form);     // Should fail
        delete form;
    }

    // TEST 6: Multiple forms
    std::cout << "\n--- TEST 6: MULTIPLE FORMS ---\n";

    AForm* forms[3];

    forms[0] = intern.makeForm("shrubbery creation", "forest");
    forms[1] = intern.makeForm("robotomy request", "Robot");
    forms[2] = intern.makeForm("presidential pardon", "Marvin");

    for (int i = 0; i < 3; i++) {
        if (forms[i]) {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
            delete forms[i];
        }
    }

    std::cout << "\n========== END OF TESTS ==========\n";

    return 0;
}
