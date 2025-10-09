/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:16 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 12:53:46 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

void testSection(const std::string& title) {
    std::cout << "\n\033[1;36m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
    testSection("CONSTRUCTION AND DESTRUCTION");
    ClapTrap robot1("R2-D2");
    ClapTrap robot2("C-3PO");
    ClapTrap robot3(robot1); // Copy constructor
    
    testSection("BASIC ATTACKS");
    robot1.attack("C-3PO");
    robot2.attack("R2-D2");
    
    testSection("DAMAGE AND REPAIR");
    robot1.takeDamage(5);
    robot1.beRepaired(3);
    
    robot2.takeDamage(8);
    robot2.beRepaired(2);
    
    testSection("ENERGY CONSUMPTION");
    // Performing multiple attacks to consume energy
    for (int i = 0; i < 10; i++) {
        std::cout << "Attack #" << (i + 1) << ": ";
        robot1.attack("target");
    }
    
    testSection("NO HIT POINTS");
    ClapTrap robot4("Bender");
    robot4.takeDamage(15); // More damage than hit points
    robot4.attack("alguien"); // it shouldn't work
    robot4.beRepaired(5);    // it shouldn't work
    
    testSection("ASSIGNMENT OPERATOR");
    ClapTrap robot5("Wall-E");
    robot5 = robot1;
    robot5.attack("EVA");
    
    testSection("REPAIR LIMITS");
    ClapTrap robot6("Johnny5");
    robot6.takeDamage(2);
    robot6.beRepaired(1);
    robot6.beRepaired(1);
    robot6.beRepaired(1); // Last reparation with energy
    
    testSection("DESTRUCTORS");
    
    return 0;
}