/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:38 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 13:11:06 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include <iostream>

void testSection(const std::string& title) {
    std::cout << "\n\033[1;35m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
    testSection("BASIC CONSTRUCTION");
    FragTrap frag1("Boomer");
    FragTrap frag2("Exploder");
    
    testSection("HIGH FIVES - EXCLUSIVE METHOD");
    frag1.highFivesGuys();
    frag2.highFivesGuys();
    
    testSection("ATTACKS WITH IMPROVED DAMAGE (30)");
    frag1.attack("target A");
    frag2.attack("target B");
    
    testSection("DAMAGE AND REPAIR");
    frag1.takeDamage(50);
    frag1.beRepaired(25);
    frag1.attack("after repair");
    
    testSection("MAXIMUM ENERGY (100 points)");
    FragTrap energyFrag("EnergyMaster");
    for (int i = 0; i < 105; i++) {
        std::cout << "Attack #" << (i + 1) << ": ";
        energyFrag.attack("energy test");
    }
    
    testSection("HIGH FIVE WITHOUT ENERGY");
    energyFrag.highFivesGuys();
    
    testSection("COPY BUILDER");
    FragTrap frag3(frag1);
    frag3.highFivesGuys();
    frag3.attack("copied attack");
    
    testSection("ASSIGNMENT OPERATOR");
    FragTrap frag4("TempFrag");
    frag4 = frag2;
    frag4.highFivesGuys();
    frag4.attack("assigned attack");
    
    testSection("NO LIFE POINTS");
    FragTrap toughFrag("ToughOne");
    toughFrag.takeDamage(150); // More damage than maximum HP
    toughFrag.attack("should fail");
    toughFrag.beRepaired(10);  // It should fail
    toughFrag.highFivesGuys(); // This really works
    
    testSection("MULTIPLE HIGH FIVES");
    FragTrap happyFrag("HappyBot");
    happyFrag.highFivesGuys();
    happyFrag.highFivesGuys();
    happyFrag.highFivesGuys();
    happyFrag.attack("between high fives");
    happyFrag.highFivesGuys();
    
    testSection("INITIAL VALUES VERIFICATION");
    std::cout << "Frag1 - HP: " << frag1.getHitPoints() 
              << ", Energy: " << frag1.getEnergyPoints()
              << ", Damage: " << frag1.getAttackDamage() << std::endl;
    
    testSection("CHAIN DESTROYER");
    
    std::cout << "\n\033[1;32m✅ All FragTrap tests completed!\033[0m" << std::endl;
    std::cout << "\033[1;33m(The destroyers will be shown below)\033[0m" << std::endl;
    
    return 0;
}