/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:21:24 by fosuna-g          #+#    #+#             */
/*   Updated: 2026/11/23 17:21:25 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== FORM CREATION TESTS ===" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid Form", 0, 50); // Too high grade
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Invalid Form 2", 50, 151); // Too low grade
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== FORM SIGNATURE VERIFICATION ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 10);
        Bureaucrat intern("Intern", 140);
        Form contract("Employment Contract", 50, 20);

        std::cout << contract << std::endl;

        // The trainee does not have a high enough level to sign (50 is required; they have 140)
        intern.signForm(contract);
        std::cout << contract << std::endl;

        // The boss does have a high enough level (has 10, requires 50)
        boss.signForm(contract);
        std::cout << contract << std::endl;

        // Attempt to sign a form that is already signed
        boss.signForm(contract);

    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
