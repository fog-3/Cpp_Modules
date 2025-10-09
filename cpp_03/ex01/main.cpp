/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:38 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 13:01:08 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

void testSection(const std::string& title) {
    std::cout << "\n\033[1;36m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
    testSection("CONSTRUCTION WITH INHERITANCE CHAIN");
    ScavTrap scav1("Guardian");
    ScavTrap scav2("Protector");
    
    testSection("SPECIFIC ATTACKS BY SCAVTRAP");
    scav1.attack("intruder");
    scav2.attack("enemy robot");
    
    testSection("GUARD MODE - EXCLUSIVE METHOD");
    scav1.guardGate();
    scav2.guardGate();
    
    testSection("INHERITED DAMAGE AND REPAIR");
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    scav1.attack("after repair");
    
    testSection("COPY CONSTRUCTOR WITH INHERITANCE");
    ScavTrap scav3(scav1);
    scav3.attack("copied target");
    scav3.guardGate();
    
    testSection("ASSIGNMENT OPERATOR WITH INHERITANCE");
    ScavTrap scav4("Temporary");
    scav4 = scav2;
    scav4.attack("assigned target");
    scav4.guardGate();
    
    testSection("SCAVTRAP ENERGY LIMITS (50 points)");
    ScavTrap energyTest("EnergyBot");
    for (int i = 0; i < 55; i++) {
        std::cout << "Ataque #" << (i + 1) << ": ";
        energyTest.attack("test dummy");
    }
    
    testSection("SCAVTRAP LIFE LIMITS (100 points)");
    ScavTrap healthTest("HealthBot");
    healthTest.takeDamage(95);
    healthTest.beRepaired(10);
    healthTest.takeDamage(20);  // It lefts 0 HP
    healthTest.attack("should fail");
    healthTest.guardGate();     // It can't attack but can guarGate
    
    std::cout << "\n\033[1;32m✅ All tests completed!\033[0m" << std::endl;
    std::cout << "\033[1;33m(The destroyers will be shown below)\033[0m" << std::endl;
    
    return 0;
}
