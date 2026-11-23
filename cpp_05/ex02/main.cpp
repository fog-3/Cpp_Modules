/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:21:46 by fosuna-g          #+#    #+#             */
/*   Updated: 2026/11/23 17:21:47 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "\n========== CPP05 EX02 TESTS ==========\n";

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 70);
        Bureaucrat intern("Intern", 150);

        std::cout << "\n--- BUREAUCRATS ---\n";
        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << intern << std::endl;

        // TEST 1: Shrubbery Creation
        std::cout << "\n--- TEST 1: SHRUBBERY ---\n";
        ShrubberyCreationForm shrub("christmas_tree");

        std::cout << shrub << std::endl;
        intern.signForm(shrub);      // Should fail
        manager.signForm(shrub);     // Should succeed
        intern.executeForm(shrub);   // Should fail
        manager.executeForm(shrub);  // Should succeed

        // TEST 2: Robotomy Request
        std::cout << "\n--- TEST 2: ROBOTOMY ---\n";
        RobotomyRequestForm robot("Bender");

        std::cout << robot << std::endl;
        manager.signForm(robot);     // Should succeed
        manager.executeForm(robot);  // Should fail
        boss.executeForm(robot);     // Should succeed (50%)

        // Multiple executions to test randomness
        std::cout << "\n--- ROBOTOMY RANDOMNESS ---\n";
        for (int i = 0; i < 5; i++) {
            boss.executeForm(robot);
        }

        // TEST 3: Presidential Pardon
        std::cout << "\n--- TEST 3: PRESIDENTIAL PARDON ---\n";
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << pardon << std::endl;
        manager.signForm(pardon);    // Should fail
        boss.signForm(pardon);       // Should succeed
        manager.executeForm(pardon); // Should fail
        boss.executeForm(pardon);    // Should succeed

        // TEST 4: Execute unsigned form
        std::cout << "\n--- TEST 4: UNSIGNED FORM ---\n";
        ShrubberyCreationForm unsignedForm("unsigned_tree");
        boss.executeForm(unsignedForm); // Should fail

        // TEST 5: Copy constructor
        std::cout << "\n--- TEST 5: COPY CONSTRUCTOR ---\n";
        ShrubberyCreationForm copy(shrub);
        std::cout << copy << std::endl;
        boss.executeForm(copy); // Should succeed if signed state copied

        // TEST 6: Assignment operator
        std::cout << "\n--- TEST 6: ASSIGNMENT ---\n";
        ShrubberyCreationForm assigned("original");
        assigned = shrub;
        std::cout << assigned << std::endl;
        boss.executeForm(assigned);

    }
    catch (const std::exception &e) {
        std::cerr << "Unexpected exception: "
                  << e.what() << std::endl;
    }

    std::cout << "\n========== END OF TESTS ==========\n";
    return 0;
}
