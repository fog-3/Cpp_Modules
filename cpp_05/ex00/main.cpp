/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:20:55 by fosuna-g          #+#    #+#             */
/*   Updated: 2026/11/23 17:20:56 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Test 1: Normal creation ---" << std::endl;
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;
        
        std::cout << "Increasing the grade..." << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Constructor rating too high ---" << std::endl;
    try {
        Bureaucrat b2("Bob", 0);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Constructor value set too low ---" << std::endl;
    try {
        Bureaucrat b3("Charlie", 151);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Increment overflow ---" << std::endl;
    try {
        Bureaucrat b4("David", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade(); // It should throw an exception
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}