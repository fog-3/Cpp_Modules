/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:38 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 13:14:31 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

void testSection(const std::string& title) {
	std::cout << "\n\033[1;34m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
	testSection("DIAMONDTRAP CONSTRUCTION");
	DiamondTrap diamond("Sparkle");
	
	testSection("WHOAMI METHOD");
	diamond.whoAmI();
	
	testSection("ATTACK (from ScavTrap)");
	diamond.attack("target");
	
	testSection("HIGH FIVE (from FragTrap)");
	diamond.highFivesGuys();
	
	testSection("GUARD GATE (from ScavTrap)");
	diamond.guardGate();
	
	testSection("DAMAGE AND REPAIR");
	diamond.takeDamage(50);
	diamond.beRepaired(25);
	
	testSection("COPY BUILDER");
	DiamondTrap diamond2(diamond);
	diamond2.whoAmI();
	
	testSection("DESTRUCTION");
	
	return 0;
}
